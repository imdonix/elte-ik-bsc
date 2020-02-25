package stringutils;

class IterLetterMain
{
	public static void main(String[] args)
	{
		IterLetter il = new IterLetter(args[0]);
		
		while(il.hasNext())
		{
			il.printNext();
		}
		
		il.restart();
	}
	
}