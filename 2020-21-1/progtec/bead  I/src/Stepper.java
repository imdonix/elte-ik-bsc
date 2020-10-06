
public class Stepper extends Entity 
{

	public Stepper(String name, int water) 
	{
		super(name, water);
	}

	@Override
	public int getMaxWater() 
	{
		return 12;
	}

	@Override
	public void apply(Weather condition) 
	{
		switch(condition) 
        { 
            case Sunny: apply(-2, 1); break; 
            case Cloudy: apply(-1, 2); break; 
            case Rainy: apply(3, 1); break; 
        }
	}

}
