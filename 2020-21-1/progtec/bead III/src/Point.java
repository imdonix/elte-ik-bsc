package tron;

public final class Point 
{
	public final int x,y;
	
	public Point()
	{
		this(0,0);
	}
	
	public Point(int x, int y)
	{
		this.x = x;
		this.y = y;
	}

	
	public Point add(Point p)
	{
		return new Point(x + p.x, y + p.y);
	}
	
	public boolean equals(Point p)
	{
		return p.x == x && p.y == y;
	}
	
	public boolean isNull()
	{
		return equals(new Point());
	}
	
	
	public static Point right = new Point(1,0);
	
	public static Point left = new Point(-1,0);
	
	public static Point down = new Point(0,1);

	public static Point up = new Point(0,-1);
	
}
