class SqrRoot
{
	public static void main(String[] args)
	{
		if(args.length == 2)
		{
			double S = Double.parseDouble(args[0]);
			double E = Double.parseDouble(args[1]);
			
			double x = (S)/2;
			double temp;
			do
			{
				double y = (x + S / x ) / 2;
				temp = x;
				x = y;
			} while (Math.abs(x-temp) > E);		
			
			System.out.println("Sqrt(" + S + ") = " + x);
		}
		else
			System.out.println("Adj meg pontosan ketto szamot (S E)");
		
	}
}