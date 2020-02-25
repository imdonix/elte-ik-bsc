package stringutils;

class IterMain
{
	public static void main(String[] args)
	{
		IterLetter il = new IterLetter("egyszo");
		
		while(il.hasNext())
		{
			il.printNext();
		}
		
		il.restart();
		
		IterWord iw = new IterWord("tobb szobol allo mondat");
		
		while(iw.hasNext())
		{
			iw.printNext();
		}
		
		iw.restart();
		
	}
	
}