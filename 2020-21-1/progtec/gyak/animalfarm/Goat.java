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
public class Goat extends Animal {

    public Goat(String name, int weight) {
        super(name, weight, "G");
        MALNOURISHED_THRESHOLD = 12;
    }    
}
