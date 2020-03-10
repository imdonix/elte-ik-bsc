import java.io.*;


class Search
{
	public static void main(String[] args)
	{		
		String line;
		try
		{
		
			FileReader fr = new FileReader(args[0]);    
			BufferedReader br = new BufferedReader(fr);    
			String lookfor = System.console().readLine();
			while ((line = br.readLine()) != null)
				if(line.contains(lookfor))
					System.out.println(line);
		}
		catch(IOException ex)
		{
			System.out.println("No input file!");
		}
	}
}