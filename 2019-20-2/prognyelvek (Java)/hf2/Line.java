class Line
{
	double a,b,c;
	
	boolean contains(Point p)
	{
		return c == a*p.x+b*p.y;
	}
	
	boolean isParallelWith(Line l)
	{
		return a/b == l.a/l.b;
	}
	
	boolean isOrthogonalTo(Line l)
	{
		return 0 == l.a*a + l.b*b;
	}
	
	void print()
	{
		System.out.println(a + "x+" + b + "y" + " = " + c);
	}
}