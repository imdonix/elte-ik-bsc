package stringutils;

class IterWord
{
	String[] words;
	int i;
	
	IterWord(String str)
	{
		words = str.split(" ");
		i = 0;
	}
	
	void printNext()
	{
		if(hasNext())
			System.out.println(words[i++]);
	}
	
	void restart()
	{
		i = 0;
	}
	
	boolean hasNext()
	{
		return words.length > i;
	}
}