import auto.utils.Color;
import auto.Car;
import pizza.*;
import java.io.*;
import java.util.*; 

public class Main
{
	public static void main(String[] args)
	{
		//Task : Cars
		Car[] cars = new Car[1];
		int i = 0;
		
		try
		{
			BufferedReader br = new BufferedReader(new FileReader("input.txt"));
			String line;
			while ((line = br.readLine()) != null)
				cars = Put(cars, i++, Car.ParseLine(line));
		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
		
		for(int j = 0; j < i; j++)
			System.out.println(cars[j].toString());
		System.out.println("-----------------------------------");
		
		//Task : Pizza	
		PizzaTest(args[0]);
		System.out.println("-----------------------------------");
		
		//Task : TelsShops
		TelevisionShop.WriteMinMaxDiameter();
		TelevisionShop.WriteMinMaxDiameter(TelevisionShop.SONY);
		TelevisionShop.WriteAll();
	}
	
   /**
   * Put a @see Car into a car array , if the array is small the crate a new 2x array.
   * @param cars base array.
   * @param index the position of the new car.
   * @param newCar the new @see Car.
   * @return The new or the same car array.
   */
	static Car[] Put(Car[] cars, int index, Car newCar)
	{
		if(index < cars.length)
		{
			cars[index] = newCar;
			return cars;
		}
		else
		{
			Car[] temp = new Car[cars.length*2];
			for(int i = 0; i < cars.length; i++)
				temp[i] = cars[i];
			
			temp[index] = newCar;
			return temp;			
		}		
	}
	
	static void PizzaTest(String src)
	{
		List<Pizza> pizzas = new ArrayList<Pizza>();
		
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(src));
			String line;
			while ((line = br.readLine()) != null)
				pizzas.add(Pizza.ParseLine(line));
		}
		catch(IOException  ex)
		{
			System.out.println("A rendeleseket tartalmazo fajlt nem sikerult megnyitni");
		}
		catch(IllegalArgumentException  ex)
		{
			System.out.println("Egy rendeles nem sikerult beolvasni mert rossz feltetet adott meg");
		}
		catch(Exception  ex)
		{
			System.out.println("Egyeb hiba");
		}
		
		Time allprep = new Time(0);
		for(Pizza pizza : pizzas)
			allprep.add(pizza.getPrepTime());
		
		System.out.println("A rendelesek elkeszitesehez ennyi ido szukseges (perc:masodperc): " + allprep.toString());
	}

}