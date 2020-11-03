import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Game 
{
	private List<Bug> bugs;
	private boolean end;
	
	public Game(int n)
	{
		end = false;
		bugs = new ArrayList<Bug>(n);
		for(int i = 0; i < n; i++)
			bugs.add(new Bug(0,0, Direction.EAST));
		
		new Thread(getMoveRunnable()).start();
		new Thread(getInputRunnable()).start();
	}
	
	boolean isGameEnded()
	{
		return !end;
	}
	
	
	Runnable getMoveRunnable()
	{
		return new Runnable() 
		{
			@Override
			public void run() 
			{
				while(isGameEnded()) 
				{
					synchronized(bugs)
					{						
						for(Bug b : bugs) 
						{
							b.move();
							end = end || b.isDead();								
						}
						
						for(Bug b : bugs)
							System.out.println(b);
						System.out.println("-----");
						
					}
					try {Thread.sleep(1000);} catch (InterruptedException e) {}
				}
				
				System.out.println("Game over!");
			}
		};
	}
	
	Runnable getInputRunnable()
	{
		return new Runnable() 
		{
			@Override
			public void run() 
			{
				while(isGameEnded()) 
				{
					Scanner scan = new Scanner(System.in);
					Direction direction = getDirectionFromString(scan.next());
					
					synchronized(bugs)
					{
						for(Bug b : bugs)
							b.turnTo(direction);
					}
				}
			}
		};
	}
	
	public static Direction getDirectionFromString(String inp)
	{
		switch( inp )
		{
			case "W" : return Direction.NORTH;
			case "D" : return Direction.EAST;
			case "S" : return Direction.SOUTH;
			case "A" : return Direction.WEST;
			default : throw new IllegalArgumentException();
		}
	}
	
	
}
