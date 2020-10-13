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
public abstract class Dragon extends Character {
 
    protected final int ATTACK_THRESHOLD;

    public Dragon(String name, int HP, int attack, int ATTACK_THRESHOLD) {
        super(name, HP, attack);
        this.ATTACK_THRESHOLD = ATTACK_THRESHOLD;
    }

    @Override
    public void applyDamageFrom(Character character) {
        if (character.attack > ATTACK_THRESHOLD) {
            HP -= character.attack;
        }
    }
    
}
