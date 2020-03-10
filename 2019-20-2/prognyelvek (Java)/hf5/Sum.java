import java.io.*;

class Sum
{
	
	static String FILE_NAME = "numstoadd.txt";
	
	public static void main(String[] args)
	{
		try
		{
			String line;
			BufferedReader br = new BufferedReader(new FileReader(FILE_NAME));
			while((line = br.readLine()) != null)
				Process(line);
		}
		catch(IOException ex)
		{
			System.out.println(ex.getMessage());
		}
	}
	
	static void Process(String s)
	{
		String[] splitted = s.split(" ");
		String[] numsString = splitted[1].split(",");
		
		int numToFind = Integer.parseInt(splitted[0]);
		int[] nums = new int[numsString.length];
		
		for(int i=0;i<numsString.length;i++)
			nums[i] =  Integer.parseInt(numsString[i]);
		
		boolean found = false;
		for(int i=0;i<numsString.length-1;i++)
			for(int j=i+1;j<numsString.length;j++)
				if(numToFind == nums[i] + nums[j])
				{
					System.out.println(numToFind + " " + nums[i] + " " + nums[j]);
					found = true;
				}
				
		if(!found)
			System.out.println(numToFind + " none");
	}
}