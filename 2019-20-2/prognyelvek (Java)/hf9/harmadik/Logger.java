import java.io.*;

class Logger
{
	protected void log(String stream){}
}

class ConsoleLogger extends Logger
{
	@Override
	protected void log(String stream){System.out.println(stream);}
}

class ConsoleCipherLogger extends Logger
{
	@Override
	protected void log(String stream){System.out.println(chip(stream, 3));}
	
	private String chip(String stream, int dist)
	{
		String AlphaNumericString = "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		StringBuilder sb=new StringBuilder(stream.length());
		
		for(int i=0;i<stream.length();i++)
		{
			int i=0;
			for(int j=0;j<AlphaNumericString.length();j++)
				if(stream.charAt(i) == AlphaNumericString.charAt(j)) 
					i = j;
				
			sb.append(AlphaNumericString.charAt((i+dist) % AlphaNumericString.length()));

		}
		return sb.toString();
	}
}

class FileLogger extends Logger
{
	private String src;
	
	FileLogger(String src)
	{
		super();
		this.src=src;
	}
	
	@Override
	protected void log(String stream)
	{
		try
		{
			PrintWriter out= new PrintWriter(new BufferedWriter(new FileWriter(src)));
			out.println(stream);
			out.close();
		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
	}
}