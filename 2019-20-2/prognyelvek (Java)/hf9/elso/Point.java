public class Point 
{
    protected double x, y;

    public Point() 
	{
        this.x = this.y = 0;
    }

    public Point(double x, double y) 
	{
        this.x = x;
        this.y = y;
    }

    public Point(Point that) 
	{
        this.x = that.x;
        this.y = that.y;
    }
}