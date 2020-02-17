class Fact 
{
	public static void main( String[] args)
	{
				
		if(args.length != 1)
			return;
		
		int n = Integer.parseInt(args[0]);
		int s = 1;
		for(int i = 1; i <= n; s*=i++);
		System.out.println(s);
	}
}