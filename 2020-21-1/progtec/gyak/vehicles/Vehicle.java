/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vehicles;

import java.util.ArrayList;

/**
 *
 * @author bli
 */
public abstract class Vehicle {

    String plate;
    String category;
    ArrayList<Integer> refuels;

    public Vehicle(String plate, String category) {
        this.plate = plate;
        this.category = category;
        refuels = new ArrayList<>();
    }

    public void addRefuel(int amount) {
        refuels.add(amount);
    }

    public Double sumRefuels() {
        double sum = 0;
        for (int refuel : refuels) {
            sum += refuel;
        }
        return sum;
    }

    public Integer numRefuels() {
        return refuels.size();
    }

    public Double meanRefuels() {
        return sumRefuels() / numRefuels();
    }

    public String getCategory() {
        return category;
    }    

    @Override
    public String toString() {
        return "Vehicle{" + "plate=" + plate + ", category=" + category + ", refuels=" + refuels + '}';
    }

}
