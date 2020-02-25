package circle;

import circle.utils.Point;

class Circle
{
	private Point p;
	private double r;
	
	void enlarge(double f)
	{
		r*=f;
	}	
	
	double getArea()
	{
		return r*r*Math.PI;
	}
}