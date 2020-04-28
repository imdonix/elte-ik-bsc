enum Colour {RED,GREEN,BLUE}

class ColouredPoint extends Point
{
	private Colour color;
	
	public ColouredPoint(Colour color)
	{
		super();
		this.color=color;
	}
	
	public ColouredPoint(double x, double y,Colour color)
	{
		super(x,y);
		this.color=color;
	}
	
	public ColouredPoint(Point that,Colour color)
	{
		super(that);
		this.color=color;
	}
	
	public Colour getSzin()
	{
		return color;
	}
	
	public void setSzin(Colour color)
	{
		this.color=color;
	}

}