class ModifiedPerfectNumber
{
	public static void main( String[] args)
	{
		if(args.length != 1)
		{
			System.out.println("Adj meg pontosan egy szamot!");
		}
		else
		{
			int n = Integer.parseInt(args[0]);
			int c = 0;
			
			for(int j=1;j<=n;j++)
			{
				int sum = 0;
				for(int i = 1; i < j;i++)
					if(j % i == 0)
						sum+=i;
				
				if(sum==j)
					c++;
			}
			
			System.out.println("Az 1 - " + n + " intervallumban " + c + " szam van!");

			
		}	
	}
}