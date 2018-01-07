package facade;

import dk.vetterlain.radiator.entitty.Person;
import dk.vetterlain.radiator.entitty.Radiator;
import dk.vetterlain.radiator.model.RadiatorClient;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.persistence.RollbackException;

/**
 *
 * @author joacim og zam
 */
public class PersonFacade {

    private final EntityManagerFactory EMF;
    RadiatorClient myClient;

    public PersonFacade(String persistenceUnit) {

        this.EMF = Persistence.createEntityManagerFactory(persistenceUnit);
    }

    public static void main(String[] args) {
        new PersonFacade("PU").start();
    }

    public void start() {
        Person p = new Person();
        p.setPin("1234");
        p.setUsername("user");
        Radiator r = new Radiator();
        r.setTemperature(20F);
        p.setRadiator(r);
        createPerson(p);
    }

    private EntityManager getEntityManager() {
        return EMF.createEntityManager();
    }

    public Person getPerson(int id) {
        return getEntityManager().find(Person.class, id);
    }

    public Person createPerson(Person person) {
        EntityManager em = getEntityManager();
        Person personInDB = null;
        try {
            em.getTransaction().begin();
            em.persist(person);
            em.getTransaction().commit();
            personInDB = em.find(Person.class, person.getId());
        } catch (RollbackException r) {
            em.getTransaction().rollback();
        } finally {
            em.close();
        }
        return personInDB;
    }

    public Person updatePerson(Person person) {
        EntityManager em = getEntityManager();
        Person personInDB = em.find(Person.class, person.getId());
        if(person.getRadiator().getTemperature() == null){
            person.getRadiator().setTemperature(personInDB.getRadiator().getTemperature());
        }
        try {
            em.getTransaction().begin();
            personInDB = em.merge(person);
            em.getTransaction().commit();
        } catch (RollbackException r) {
            em.getTransaction().rollback();
        } finally {
            em.close();
        }
        sendMessageToRadiator(personInDB.getRadiator().getTemperature());
        return personInDB;
    }

    public void sendMessageToRadiator(Float temperature) {
        RadiatorClient myClient = new RadiatorClient("192.168.0.104", 5000);
        myClient.sendMessage(temperature + "");
    }

}
