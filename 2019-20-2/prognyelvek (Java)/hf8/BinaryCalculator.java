class BinaryCalculator
{
	public static void main(String[] args)
	{
		calculate(2,4);
		calculate((short)2,(short)4);
		calculate((long)2,(long)4);
		calculate(2.0,4.0);
		calculate(2.0f,4.5f);
		calculate("2","4");
	}
	
	static void calculate(int a, int b)
	{
		doCalculate((long)a,(long)b);
	}
	
	static void calculate(short a, short b)
	{
		doCalculate((short)a,(short)b);
	}
	
	static void calculate(long a, long b)
	{
		doCalculate(a,b);
	}
	
	static void calculate(float a, float b)
	{
		doCalculate((long)a,(long)b);
	}
	
	static void calculate(double a, double b)
	{
		doCalculate((long)a,(long)b);
	}
	
	static void calculate(String a, String b)
	{
		doCalculate(Long.parseLong(a),Long.parseLong(b));
	}
	
	static void doCalculate(long a, long b)
	{
		System.out.println(Long.toBinaryString(a));
		System.out.println(Long.toBinaryString(b));
		System.out.println(Long.toBinaryString(a&b));
		System.out.println(Long.toBinaryString(a^b));
		System.out.println(Long.toBinaryString(-a));
		System.out.println(Long.toBinaryString(-b));
	}
}