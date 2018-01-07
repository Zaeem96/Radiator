package rest;

import com.google.gson.Gson;
import dk.vetterlain.radiator.entitty.Person;
import facade.PersonFacade;
import javax.ws.rs.Consumes;
import javax.ws.rs.Produces;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import javax.ws.rs.core.MediaType;

/**
 * REST Web Service
 *
 * @author joacim og zam
 */
@Path("person")
public class PersonResource {

    private Gson gson;
    private static PersonFacade p;

    public PersonResource() {
        p = new PersonFacade("PU");
        gson = new Gson();
    }

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getPerson() {
        return gson.toJson(new PersonFacade("PU").getPerson(1));
    }

    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void updatePerson(String content) {
        p.updatePerson(gson.fromJson(content, Person.class));
    }

}
