
public class Sandpiper extends Entity 
{

	public Sandpiper(String name, int water) 
	{
		super(name, water);
	}

	@Override
	public int getMaxWater() 
	{
		return 8;
	}

	@Override
	public void apply(Weather condition) 
	{
		switch(condition) 
        { 
            case Sunny: apply(-1, 3); break; 
            case Cloudy: apply(0, 1); break; 
            case Rainy: apply(3, 0); break; 
        }
	}

}
