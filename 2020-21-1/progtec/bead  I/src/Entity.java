import java.util.Scanner;

public abstract class Entity implements Comparable<Entity>
{
	private String name;
	private int water;
	private int travelled;
		
	public Entity(String name, int water)
	{
		this.name = name;
		this.water = water;
		travelled = 0;
	}
	
	public boolean isAlive()
	{
		return water > 0;
	}
	
	public String getName()
	{
		return name;
	}
	
	public int getTravelled()
	{
		return travelled;
	}
	
	protected void apply(int water, int distance)
	{
		if(isAlive())
		{
			this.water += water;
			
			if(isAlive())
			{
				travelled += distance;
			}
		}
	}
	
	
	
	public abstract int getMaxWater();
	
	public abstract void apply(Weather condition);
	
	
	
	@Override
	public int compareTo(Entity ent) 
	{
		return travelled - ent.getTravelled();
	}
	
	@Override
	public String toString()
	{
		return String.format("%s - Travelled: %d - Waterleft: %d ", name, travelled, water);
	}
	
	
	public static Entity Create(Scanner scanner)
	{
		String name = scanner.next();
		String type = scanner.next();
		int water = scanner.nextInt();
		
		Entity tmp;
		
		switch(type) 
        { 
            case "h": tmp = new Sandpiper(name,  water); break; 
            case "s": tmp = new Sponge(name,  water); break; 
            case "l": tmp = new Stepper(name,  water); break; 
            default: 
                throw new IllegalArgumentException();
        } 
		
		return tmp;
	}
	
}
