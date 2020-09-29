/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package animalfarm;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author pinter
 */
public class AnimalFarm {

    private final ArrayList<Animal> animals;

    public AnimalFarm() {
        animals = new ArrayList<>();
    }

    public void read(String filename) throws FileNotFoundException, InvalidInputException {
        Scanner sc = new Scanner(new BufferedReader(new FileReader(filename)));
        int numAnimals = sc.nextInt();
        while (sc.hasNext()) {
            Animal animal;
            String kind = sc.next();
            String name = sc.next();
            int weight = sc.nextInt();
            switch (kind) {
                case "C":
                    animal = new Cow(name, weight);
                    break;
                case "H":
                    animal = new Horse(name, weight);
                    break;
                case "G":
                    animal = new Goat(name, weight);
                    break;
                case "E":
                    animal = new Emu(name, weight);
                    break;
                default:
                    throw new InvalidInputException();
            }
            int numMeals = sc.nextInt();
            for (int i = 0; i < numMeals; i++) {
                animal.addMeal(sc.nextInt());
            }
            animals.add(animal);
        }
    }

    public void report() {
        System.out.println("Animals on the farm:");
        for (Animal a : animals) {
            System.out.println(a);
        }
        System.out.println("Malnourished animals:");
        for (Animal a : animals) {
            if (a.isMalnourished()) {
                System.out.println(a);
            }
        }
        System.out.println("Animals that consumed more than 1 kg of food:");
        for (Animal a : animals) {
            if (a.consumedMore(100)) {
                System.out.println(a);
            }
        }
    }

    public void clear() {
        animals.clear();
    }

}
