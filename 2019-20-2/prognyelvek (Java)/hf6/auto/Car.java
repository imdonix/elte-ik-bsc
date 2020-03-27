package auto;
import auto.utils.Color;

/**
* Simple Car class represented with: plate, color, maxSpeed
*
* @author  Magyar Tamás
* @version 1.0
* @since   2020-03-27
*/
public class Car
{
	static int autoCounter = 0;
	
	String plate;
	Color color;
	int maxSpeed;

	public Car(String plate, Color color, int maxSpeed)
	{
		this.plate = plate;
		this.color = color;
		this.maxSpeed = maxSpeed;
		autoCounter++;	
	}
	
	public Car()
	{
		this("AAA-000", Color.BLUE, 120);
	}
	
	public String toString()
	{
		return plate + "|" + color + "|" + maxSpeed;
	}

	/**
	* Compare two cars bym maxspeed, retrun true if the left car is faster then the right car;
	* @param left Left Car
	* @param right Right Car
	* @return boolean.
	*/
	public static boolean compare(Car left, Car right)
	{
		return left.maxSpeed > right.maxSpeed;
	}
	
   /**
   * Parse a String to Car, separated by colum;
   * @param line input String
   * @return the car.
   */
	public static Car ParseLine(String line)
	{
		Car temp = new Car();
		String[] splitted = line.split(",");
		temp.plate = splitted[0];
		temp.color = Color.valueOf(splitted[1]);
		temp.maxSpeed = Integer.parseInt(splitted[2]);
		return temp;		
	}
}