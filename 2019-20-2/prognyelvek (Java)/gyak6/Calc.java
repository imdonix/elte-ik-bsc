class Calc
{

	public static void main(String[] args)
	{
		try
		{
			System.out.println(IsCalc(args, 5));
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

	static boolean IsCalc(String[] args, int i)
	{

		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);

			
		System.out.println("összege: " + (a+b));
		System.out.println("külömbsége: " + (a-b));
		System.out.println("szorzata: " + (a*b));
		System.out.println("hanyadosa: " + (a/b));
		System.out.println("maradeosztva: " + (a%b));
		
		return (int)a+b == i;
	}
}