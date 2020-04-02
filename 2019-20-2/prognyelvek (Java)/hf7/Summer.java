import java.io.*;
import java.lang.StringBuilder;

public class Summer
{	
	public static String[] readLines(String src)
	{
		StringBuilder sb = new StringBuilder();
		String delimiter = ":";
		String line;
		
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(src));
			while ((line = br.readLine()) != null)
				{sb.append(line); sb.append(delimiter);}
			sb.deleteCharAt(sb.length()-1);
		}
		catch(IOException ex)
		{
			System.out.println("A fajlt nem lehetett megnyitni");
		}
		catch(StringIndexOutOfBoundsException ex)
		{
			System.out.println("A fajlt nem tartalmazott adatot");
		}
		
		return sb.toString().split(delimiter);
	}
	
	public static int[] sumLines(String[] lines)
	{
		int[] sums = new int[lines.length];
		String delimiter = " ";
		
		try
		{
			for(int i=0;i < lines.length; i++)
				for(String num : lines[i].split(delimiter))
					sums[i]+=Integer.parseInt(num);
		}
		catch(NumberFormatException ex)
		{
			System.out.println("Hibas adat van a fajlban");
		}			
		return sums;
	}
	
	public static void writeOutLines(int[] sums)
	{
		for(int s : sums)
			System.out.println(s);
	}
}