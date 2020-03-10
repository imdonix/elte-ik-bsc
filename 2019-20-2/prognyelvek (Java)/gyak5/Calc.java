class Calc 
{
	public static void main( String[] args)
	{
				
		try
		{
			if(args.length != 2)
			throw new IllegalArgumentException("too few arguments");
		
			int a = Integer.parseInt(args[0]);
			int b = Integer.parseInt(args[1]);

			
			System.out.println("összege: " + (a+b));
			System.out.println("külömbsége: " + (a-b));
			System.out.println("szorzata: " + (a*b));
			if(b == 0)
				throw new ArithmeticException();
			System.out.println("hanyadosa: " + (a/b));
			System.out.println("maradeosztva: " + (a%b));
		}
		catch (IllegalArgumentException e)
		{
			System.out.println("Kevés argumentum");
			System.out.println(e.getMessage());
		}
		catch (ArithmeticException e)
		{
			System.out.println("0 osztás nem engedett");	
		}
		
	}
}