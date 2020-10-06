
public class Sponge extends Entity 
{

	public Sponge(String name, int water) 
	{
		super(name, water);
	}

	@Override
	public int getMaxWater() 
	{
		return 20;
	}

	@Override
	public void apply(Weather condition) 
	{
		switch(condition) 
        { 
            case Sunny: apply(-4, 0); break; 
            case Cloudy: apply(-1, 1); break; 
            case Rainy: apply(6, 3); break; 
        }
	}
}
