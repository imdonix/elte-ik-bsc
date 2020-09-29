/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package animalfarm;

import java.util.ArrayList;

/**
 *
 * @author pinter
 */
public abstract class Animal {

    private String name;
    private String kind;
    private int weight;
    protected int MALNOURISHED_THRESHOLD; // could be static
    private ArrayList<Integer> meals;

    public Animal(String name, int weight, String kind) {
        this.name = name;
        this.weight = weight;
        this.kind = kind;
        meals = new ArrayList<>();
    }

    public void addMeal(int meal) {
        meals.add(meal);
    }

    public boolean isMalnourished() {
        return weight < MALNOURISHED_THRESHOLD;
    }

    public boolean consumedMore(int dkgs) {
        int sumMeals = 0;
        for (int meal : meals) {
            sumMeals += meal;
        }
        return sumMeals > dkgs;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public String getKind() {
        return kind;
    }

    @Override
    public String toString() {
        return "Name: " + name + ", weight: " + weight + ", meals: " + meals;
    }

}
