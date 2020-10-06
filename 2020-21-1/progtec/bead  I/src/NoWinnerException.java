
@SuppressWarnings("serial")
public class NoWinnerException extends Exception 
{
	public NoWinnerException()
	{
		super("No one alive in the end of the game!");
	}
}
