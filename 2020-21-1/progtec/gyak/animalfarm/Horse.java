/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package animalfarm;

/**
 *
 * @author pinter
 */
public class Horse extends Animal {

    public Horse(String name, int weight) {
        super(name, weight, "H");
        MALNOURISHED_THRESHOLD = 60;
    }
}
