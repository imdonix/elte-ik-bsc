class CommonDivisor
{
	public static void main(String[] args)
	{
		if(args.length > 0)
		{
			long[] nums = new long[args.length];
			for(int i=0;i<args.length;i++)
				nums[i] = Long.parseLong(args[i]);
			
			long min = nums[0];
			for(long num : nums)
				if(num < min)
					min = num;
			
			long divisor = 1;
			for(int i=2;i<=min;i++)
			{
				int c = 0;
				for(long num : nums)
					if(num % i == 0)
						c++;
					
				if(c == args.length)
					divisor = i;
			}
			
			System.out.println("A szamok legnagyobb kozos osztoja: " + divisor);
		}
		else
			System.out.println("Adj meg legalabb egy szamot!");
		
	}

}