package game.vehicles;

import game.Player;
import game.utils.VehicleException;

public class Car extends Vehicle implements Comparable<Car> {
    private final int maxSpeed;
    private final int price;

    public Player owner;

    public Car(int maxSpeed, int price) {
        this.maxSpeed = maxSpeed;
        this.price = price;
    }

    public int getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return "[" + id + " | " + maxSpeed + " | " + price + "]";
    }

    @Override
    public void accelerate(double amount) throws VehicleException 
    {
        if(amount + getCurrentSpeed() <= maxSpeed )
            accelerateCurrentSpeed(amount);
    }

    @Override
    public int compareTo(Car c) {
        if(maxSpeed == c.maxSpeed)
            return c.price - price;
        return c.maxSpeed - maxSpeed;
    }
}