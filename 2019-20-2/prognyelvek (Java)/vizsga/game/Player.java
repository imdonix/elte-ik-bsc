package game;

import java.util.ArrayList;

import game.utils.VehicleException;
import game.vehicles.Car;

public class Player
{
    public String name;
    public String ip;
    public int money;
    public ArrayList<Car> cars;

    public Player(String name, String ip, int money)
    {
        if(name == null || money < 0 || IsBadIP(ip))
            throw new IllegalArgumentException();
        
        this.name = name;
        this.ip = ip;
        this.money = money;
        this.cars = new ArrayList<Car>();
    }


    private static boolean IsBadIP(String ip)
    {
        if(ip == null)
            return true;
        if(ip.length() <= 0)
            return true;
        if(ip.contains(" ") || ip.contains("\n") || ip.contains("\t"))
            return true;
        return  false;
    }

    @Override
    public boolean equals(Object obj) 
    {
        if(obj instanceof Player)
        {
            Player p = (Player)obj;
            return p.name == name && p.money == money && p.cars.equals(cars);
        }
        else
            return false;
    }

    public void buyCar(Car c) throws VehicleException
    {
        if(c.getPrice() <= money && c.owner == null)
        {
            cars.add(c);
            money-= c.getPrice();
            c.owner = this;
        }
        else
            throw new VehicleException("Not enought money or smb is owned this car");
    }

    @Override
    public int hashCode() 
    {
        return name.length()*100 + (money * 100) + cars.hashCode();
    }

    public ArrayList<Car> getSortedCars()
    {
        ArrayList<Car> tmp;
        tmp = (ArrayList<Car>)cars.clone();
        tmp.sort(null);
        return cars;
    }
}