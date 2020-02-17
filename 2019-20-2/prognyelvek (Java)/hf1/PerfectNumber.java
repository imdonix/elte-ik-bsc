class PerfectNumber
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
			int sum = 0;
			for(int i = 1; i < n;i++)
				if(n % i == 0)
					sum+=i;
			
			if(sum==n)
				System.out.println("Ez egy tokeletes szam! : " + n);
			else
				System.out.println("Ez nem egy tokeletes szam. : " + n);
		}	
	}
}