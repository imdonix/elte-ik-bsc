import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main 
{
	public static void main(String[] args) 
	{
	    Scanner scanner = new Scanner(System.in);
	  
	    while(true) 
	    {
	    	System.out.println("-----");
	    	System.out.println("Enter the file's name OR Type 'exit' to close the program. ");
	    	String input = scanner.next();
	    	
	    	if(input.equals("exit"))
	    		return;
	    	
	    	Game game = new Game(input);
			
			try 
			{
				game.Load();
			} 
			catch (FileNotFoundException e) 
			{ System.out.println("File is not found with this name. Try again."); }
			catch (IllegalArgumentException e)
			{ System.out.println("The file is contain an unkown entity type. Try again."); }
			
			try 
			{
				System.out.println("A nyertes: " + game.Play());
			} 
			catch (NotLoadedException e) 
			{ System.out.println("Can't simultate the game without loading data."); } 
			catch (NoWinnerException e) 
			{ System.out.println("No one stayed alive or started the race."); }
			catch (IllegalArgumentException e)
			{ System.out.println("The race is contain an unkown wheater condition."); }
	    	
	    }		
	}

}
