/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vehicles;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author bli
 */
public class Database {

    private final ArrayList<Vehicle> vehicles;

    public Database() {
        vehicles = new ArrayList<>();
    }

    public void read(String filename) throws FileNotFoundException, InvalidInputException {
        Scanner sc = new Scanner(new BufferedReader(new FileReader(filename)));
        int numVehicles = sc.nextInt();
        while (sc.hasNext()) {
            Vehicle vehicle;
            switch (sc.next()) {
                case "C":
                    vehicle = new Car(sc.next());
                    break;
                case "B":
                    vehicle = new Bus(sc.next());
                    break;
                case "T":
                    vehicle = new Truck(sc.next());
                    break;
                default:
                    throw new InvalidInputException();
            }
            int numRefuels = sc.nextInt();
            for (int i = 0; i < numRefuels; i++) {
                vehicle.addRefuel(sc.nextInt());
            }
            vehicles.add(vehicle);
        }
    }
    
    public void report() {
        System.out.println("Vehicles in the database:");
        for (Vehicle v : vehicles) {
            System.out.println(v);
        }
        System.out.println("Mean refuels: ");
        for (Vehicle vehicle: vehicles) {
            System.out.println(vehicle.plate + ": " + vehicle.meanRefuels());
        }
        String[] categories = {"C", "B", "T"};
        for (String cat : categories) {
            System.out.println("Refuels in category " + cat + ":");
            ArrayList<Vehicle> catVehicles = collectCategory(cat);
            System.out.println("Most fuel refueled: " + catVehicles.stream().max((vh1, vh2) -> vh1.sumRefuels().compareTo(vh2.sumRefuels())).get());
            System.out.println("Least fuel refueled: " + catVehicles.stream().min((vh1, vh2) -> vh1.sumRefuels().compareTo(vh2.sumRefuels())).get());
            System.out.println("Most times refueled: " + catVehicles.stream().max((vh1, vh2) -> vh1.numRefuels().compareTo(vh2.numRefuels())).get());
            System.out.println("Least times refueled: " + catVehicles.stream().min((vh1, vh2) -> vh1.numRefuels().compareTo(vh2.numRefuels())).get());
        }
    }

    public ArrayList<Vehicle> collectCategory(String category) {
        ArrayList<Vehicle> catVehicles = new ArrayList<>();
        for (Vehicle v : vehicles) {
            if (v.getCategory().equals(category)) {
                catVehicles.add(v);
            }
        }
        return catVehicles;
    }
    
    public void clear() {
        vehicles.clear();
    }

}
