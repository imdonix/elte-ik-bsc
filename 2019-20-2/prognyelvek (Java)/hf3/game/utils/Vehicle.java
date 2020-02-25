package game.utils;

public class Vehicle
{
	int modelid, color1, color2;
	String plate;

	
	public Vehicle(int modelid, String plate, int color1, int color2)
	{
		this.modelid = modelid;
		this.plate = plate;
		this.color1 = color1;
		this.color2 = color2;
	}
	
	public void setPlate(String plate)
	{
		this.plate = plate;
	}
	
	public String getPlate()
	{
		return plate;
	}
}