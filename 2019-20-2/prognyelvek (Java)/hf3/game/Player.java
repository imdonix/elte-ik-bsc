package game;

import game.utils.Vehicle;

class Player
{
	String name, ip;
	int hp;
	Vehicle vehicle;
	
	Player(String name, String ip, int hp, Vehicle vehicle)
	{
		this.name = name;
		this.ip = ip;
		this.hp = hp;
		this.vehicle = vehicle;
	}
	
	public String toString()
	{
		return name + " | " + ip + " | " + hp
		+ " | " + ( vehicle != null ? vehicle.getPlate() : "no vehicle aviable");
	}
	
}