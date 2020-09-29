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
public class Emu extends Animal {

    public Emu(String name, int weight) {
        super(name, weight, "E");
        MALNOURISHED_THRESHOLD = 20;        
    }    
}
