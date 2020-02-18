class Point
{
	double x,y;
	
	void move(double dx,double dy)
	{
		x+=dx;
		y+=dy;
	}
	
	void mirror(double cx,double cy)
	{
		x = 2*cx-x;
		y = 2*cy-y;
	}
	
	void mirror(Point p)
	{
		x = 2*p.x-x;
		y = 2*p.y-y;
	}
	
	double distance(Point p)
	{
		return Math.sqrt(Math.pow(p.x-x,2) + Math.pow(p.y-y,2));
	}
	
	void print()
	{
		System.out.println("P: x=" + x + " y=" + y);
	}
	
}