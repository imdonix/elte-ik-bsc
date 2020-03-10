import java.io.*;


class Summer
{
	public static void main(String[] args)
	{
		String line;
		try
		{
		
			FileReader fr = new FileReader("input.txt");    
			BufferedReader br = new BufferedReader(fr);    
			while ((line = br.readLine()) != null)
			{
				int s = 0;
				String[] splitted = line.split(",");
				for(String num : splitted)
					s+=Integer.parseInt(num);
				System.out.println(s);
			}
		 
		}
		catch(IOException ex)
		{}
		

	}
}