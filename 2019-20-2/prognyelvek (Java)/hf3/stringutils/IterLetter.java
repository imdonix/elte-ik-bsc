package stringutils;

class IterLetter
{
	String s;
	int i;
	
	IterLetter(String str)
	{
		if(str != null)
			s = str;
		else
			s = "";
		i = 0;
	}
	
	void printNext()
	{
		if(hasNext())
			System.out.println(s.charAt(i++));
	}
	
	void restart()
	{
		i = 0;
	}
	
	boolean hasNext()
	{
		return s.length() > i;
	}
}