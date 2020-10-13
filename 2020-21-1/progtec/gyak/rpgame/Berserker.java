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
public class Berserker extends Orc {

    public Berserker(String name, int HP, int attack) {
        super(name, HP, attack);
    }

    @Override
    public void applyDamageFrom(Character character) {
        HP -= character.attack * 2;
    }

}
