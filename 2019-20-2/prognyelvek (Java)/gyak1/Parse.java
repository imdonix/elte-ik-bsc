class Parse
{
	public static void main( String[] args)
	{
		String str1 = System.console().readLine();
		String str2 = System.console().readLine();
				
		int a = Integer.parseInt(str1);
		int b = Integer.parseInt(str2);
		
		for(int i = a; i < b-((b-a)/2);i++)
			System.out.println(i);
	}
}