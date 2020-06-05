package game.vehicles;

import game.utils.VehicleException;

public class Train extends Vehicle
{

    @Override
    public void accelerate(double amount) throws VehicleException
    {
        if(amount < 0)
            amount/=10;
        accelerateCurrentSpeed(amount);
    }

}