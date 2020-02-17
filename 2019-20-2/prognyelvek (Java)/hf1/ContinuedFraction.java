class ContinuedFraction
{
	public static void main(String[] args)
	{
		int accuracy = 300;
		
		//sqrt(2)
		double x = (double)1/2;
		for(int i=0; i < accuracy; i++)
			x = 1/(2+x);
		x+=1;
		
		//e
		double y = 0;
		for(int i=0; i < accuracy; i++)
			y=1/(1+(1/(1+(1/(((accuracy-i)*2)+y)))));
		y+=2;
		
		System.out.println("Sqrt(2) ~ " + x);
		System.out.println("e ~ " + y);		
		
	}
}