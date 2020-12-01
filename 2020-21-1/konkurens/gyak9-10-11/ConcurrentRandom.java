package mmorpg;

import java.util.Random;

public class ConcurrentRandom 
{
	private static Random random = new Random();
	
	public static int nextInt(int min, int max)
	{
		int rand;
		
		synchronized(random) 
		{
			rand = random.nextInt(max-min);
		}
	
		return rand + min;
	}
	
}
