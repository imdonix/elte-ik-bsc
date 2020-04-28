import java.util.Objects;

class Circle
{
	private double x,y,r;
	
	public Circle(double x,double y,double r)
	{
		this.x = x;
		this.y = y;
		this.r = r;
	}
	
	double getX(){return x;}
	double getY(){return y;}
	double getR(){return r;}
	
	@Override
	public boolean equals(Object o)
	{
		if(o instanceof Circle)
			return ((Circle)o).r == r;
		else
			return false;
	}
	
	@Override
	public int hashCode()
	{
		return Objects.hash(r);
	}
	
}