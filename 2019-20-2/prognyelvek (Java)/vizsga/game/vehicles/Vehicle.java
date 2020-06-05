package game.vehicles;

import game.utils.*;

public abstract class Vehicle 
{
    private static int counter = 0;

    protected final int id;
    private double currentSpeed;

    public Vehicle() {id = counter++; currentSpeed = 0;}

    public double getCurrentSpeed(){ return currentSpeed; }

    final protected void accelerateCurrentSpeed(double delta) throws VehicleException
    {
         currentSpeed += delta;
         if(counter < 0)
            throw new VehicleException("The vechicle speed is under zero.");
    }

    public abstract void accelerate(double amount) throws VehicleException;

}