import java.io.*;

class EvenOdd
{
	private static String IN_FILE_NAME = "nums.txt";
	private static String OUT_FILE_NAME = "out.txt";
	
	public static void main(String[] args)
	{
		try
		{
			String line;
			BufferedReader br = new BufferedReader(new FileReader(IN_FILE_NAME));
			BufferedWriter bw = new BufferedWriter(new FileWriter(OUT_FILE_NAME));
			while((line = br.readLine()) != null)
				{
					bw.write(line + " is an " + (IsEven(line) ? "even" : "odd") + " number");	
					bw.newLine();
				}
			bw.flush();	
			System.out.println("A fajlba iras megtortent");
	}
		catch(IOException ex)
		{
			System.out.println(ex.getMessage());
		}
	}
	
	static boolean IsEven(String s)
	{
		return Integer.parseInt(s) % 2 == 0;
	}
}