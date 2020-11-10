package main;

public enum Check 
{   
	None,
	X,
	O;
		
	public Check Swap()
	{
		return switch(this) 
		{
			case X -> O;
			case O -> X;
			default -> X;
		};
	}
	
	public boolean isPlayer()
	{
		return !this.equals(None);
	}
	
	public static String ToString(Check c)
	{
		switch(c) 
		{
			case X:
				return "X";
			case O:
				return "O";
			default:
				return " ";
		}
	}	
	
}
