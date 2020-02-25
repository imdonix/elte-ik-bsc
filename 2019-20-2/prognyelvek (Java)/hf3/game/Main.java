package game;

import game.utils.Vehicle;

class Main
{
	public static void main(String[] args)
	{
		Vehicle v1 = new Vehicle(1, "ABC-001", 23, 12);
		Vehicle v2 = new Vehicle(2, "ABC-002", 11, 11);
		Vehicle v3 = new Vehicle(3, "ABC-003", 11, 11);
		Player p1 = new Player("killer", "192.168.1.2", 50, null);
		Player p2 = new Player("policeman", "192.168.1.3", 100, v2);
		
		System.out.println(p1.toString());
		System.out.println(p2.toString());
		v2.setPlate("RZS-916");
		System.out.println(p2.toString());
	}
}