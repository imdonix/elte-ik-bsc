package main;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

import game.Player;
import game.vehicles.Car;

public class Main 
{

    public static void main(String[] args)
    {
        String[] names = {"Daniel", "Peter", "Richard", "Tamas", "Zorror"};
        Player dani = loadPlayerFromFile(names[0]);
        Player ricsi = loadPlayerFromFile(names[1]);

        dani.cars.add(new Car(110, 50000));
        dani.cars.add(new Car(121, 30000));
        dani.cars.add(new Car(140, 40000));
        dani.cars.add(new Car(140, 50000));
        dani.cars.add(new Car(190, 30000));
        dani.cars.add(new Car(11000, 40000));
        ricsi.cars.add(new Car(130, 10000));
        ricsi.cars.add(new Car(120, 10000));

        System.out.println(dani.getSortedCars());
    }

    
    public static Player loadPlayerFromFile(String playerName){
        File input = new File("users/" + playerName + ".txt");
    
        String[] data = null; // array
        try (BufferedReader bf = new BufferedReader(new FileReader(input)))
        {
            String line = bf.readLine();
            data = line.split(" ");
            int money;

            try{money = Integer.parseInt(data[1]);}
            catch(NumberFormatException e){money = 0;}
             
            
            try
            {
                return new Player(playerName, data[0], money); // int + nullától + catch
            }
            catch(IllegalArgumentException ex)
            {
                System.out.println("Bad palyer data for " + playerName );
            }
        } catch (IOException e) {
            System.out.println("IO error occured: " + e.getMessage());
        }
        return null;
    }
}