public class ColouredCircle extends Circle
{
	private ColouredPoint center;
	
	public ColouredCircle(Point center,double radius,Colour color)
	{
		super(radius);
		this.center=new ColouredPoint(center,color);
	}
	
	public Colour getSzin()
	{
		return this.center.getSzin();
	}
	
	public ColouredCircle(double x, double y,double radius,Colour color)
	{
		super(radius);
		this.center=new ColouredPoint(x,y,color);
	}
}