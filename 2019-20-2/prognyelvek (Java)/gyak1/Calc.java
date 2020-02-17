class Calc 
{
	public static void main( String[] args)
	{
				
		if(args.length != 2)
			return;
		
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);

		
		System.out.println("összege: " + (a+b));
		System.out.println("külömbsége: " + (a-b));
		System.out.println("szorzata: " + (a*b));
		if(b != 0)
		{
			System.out.println("hanyadosa: " + (a/b));
			System.out.println("maradeosztva: " + (a%b));
		}
	}
}