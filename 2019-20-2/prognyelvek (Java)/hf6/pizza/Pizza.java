package pizza;

enum Component{beef, cheese, corn, fish, ham, mushroom, salami, tomato};

public class Pizza
{
	private final double diameter;
	private final String[] components;
	private final Time preparation, delivery;
	
	public Pizza(double diameter, String[] components) throws IllegalArgumentException
	{
		for(String comp : components)
			Component.valueOf(comp);
		
		this.diameter = diameter;
		this.components = components;
		
		int prepTime=0;
		for(String comp : components)
			prepTime+=comp.length()*diameter;
		preparation = new Time(prepTime);
		delivery = new Time(60*5);
	}
	
	public Time getPrepTime()
	{
		return preparation;
	}
	
	public static Pizza ParseLine(String line)
	{
		String[] splitted = line.split(":");
		String[] comps = splitted[1].split(",");
		return new Pizza(Double.parseDouble(splitted[0]), comps);
	}
}