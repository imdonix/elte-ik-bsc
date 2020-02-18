class Circle
{
	Point p;
	double r;
	
	void enlarge(double f)
	{
		r*=f;
	}	
	
	double getArea()
	{
		return r*r*Math.PI;
	}
}