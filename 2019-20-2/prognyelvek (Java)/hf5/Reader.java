import java.io.*;
import java.util.InputMismatchException;

class Reader
{
	private static String FILE_NAME = "in.txt";
	
	public static void main(String[] args)
	{
		try
		{
			if(args.length != 1)
				throw new InputMismatchException();
			
			int skip = Integer.parseInt(args[0]);
			int c;
			BufferedReader br = new BufferedReader(new FileReader(FILE_NAME));
			
			while((c = br.read()) != -1)
			{
				System.out.println(((char)c));
				br.skip(skip);
			}	
			
		}
		catch(NumberFormatException ex)
		{
			System.out.println("Egesz szamot adj meg parameternek!");
		}
		catch(InputMismatchException ex)
		{
			System.out.println("Pontosan egy egesz szamot adj meg");
		}
		catch(IOException ex)
		{
			System.out.println(ex.getMessage());
		}
	}
}