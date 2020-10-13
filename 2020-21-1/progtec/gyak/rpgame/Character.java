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
public abstract class Character {

    protected String name;
    protected int HP;
    protected int attack;

    public Character(String name, int HP, int attack) {
        this.name = name;
        this.HP = HP;
        this.attack = attack;
    }

    public void attack(Character character) {
        if (isAlive()) {
            character.attacked(this);
        }
    }

    public void attacked(Character character) {
        if (isAlive()) {
            applyDamageFrom(character);
        }
    }

    public boolean isAlive() {
        return HP >= 0;
    }

    protected void applyDamageFrom(Character character) {
        HP -= character.attack;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getHP() {
        return HP;
    }

    public void setHP(int HP) {
        this.HP = HP;
    }

    public int getAttack() {
        return attack;
    }

    public void setAttack(int attack) {
        this.attack = attack;
    }

}
