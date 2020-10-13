/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rpgame;

/**
 *
 * @author bli
 */
public class MainCharacter extends Character {

    protected double defense;

    public MainCharacter(String name, int HP, int attack, double defense) {
        super(name, HP, attack);
        this.defense = defense;
    }
    
    @Override
    public void applyDamageFrom(Character character) {
        HP -= character.attack / defense;
    }

}
