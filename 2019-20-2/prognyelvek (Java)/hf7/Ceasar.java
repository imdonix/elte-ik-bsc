import java.lang.StringBuilder;

class Ceasar
{
	private final char[] alphabet = "abcdefghijklmnopqrstuvwxyz".toCharArray();
	int n;
	
	private Ceasar(int n)
	{
		this.n = n;
	}
	
	String chiper(String text)
	{		
		return code(text, 1);
	}
	
	String decipher(String text)
	{
		return code(text, -1);
	}
	
	private String code(String text, int way)
	{
		StringBuilder sb = new StringBuilder();
		for (char c : text.toCharArray())
		{
			int charcode =(int)(c - 'a');
			
			if(charcode < 0 || charcode > 24)
				throw new IllegalArgumentException();

			sb.append(alphabet[(charcode + (n * way)) % 25]);
		}
		return sb.toString();
	}
	
	
	
	public static Ceasar Create(int n)
	{
		if(n < 1 || n > 25)
			throw new IllegalArgumentException();
		return new Ceasar(n);
	}
	
}