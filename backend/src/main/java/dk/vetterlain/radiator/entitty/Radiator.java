package dk.vetterlain.radiator.entitty;

import java.io.Serializable;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

/**
 *
 * @author joacim
 */
@Entity
public class Radiator implements Serializable {

    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    private Float targetTemperature;
    private Float currentTemperature;

    public Float getCurrentTemperature() {
        return currentTemperature;
    }

    public void setCurrentTemperature(Float currentTemperature) {
        this.currentTemperature = currentTemperature;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Float getTargetTemperature() {
        return targetTemperature;
    }

    public void setTargetTemperature(Float temperature) {
        this.targetTemperature = temperature;
    }

    @Override
    public String toString() {
        return "Radiator{" + "id=" + id + ", temperature=" + targetTemperature + ", currentTemperature=" + currentTemperature + '}';
    }

}
