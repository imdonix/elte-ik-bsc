public class Circle
{
	protected Point center;
    protected double radius;
	
	public Circle(double r)
	{
		this.radius=r;
	}
	
	public Circle(double x, double y,double r)
	{
		this.center=new Point(x,y);
		this.radius=r;
	}
	
	public Circle(Point center,double r)
	{
		this.center=center;
		this.radius=r;
	}
	

}