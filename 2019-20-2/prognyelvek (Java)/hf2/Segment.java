class Segment
{
	double x1, y1, x2, y2;
	
	Segment(double x1, double y1, double x2, double y2)
	{
		this.x1 = x1;
		this.x2 = x2;
		this.y1 = y1;
		this.y2 = y2;
	}
	
	Segment(Point p1, Point p2)
	{
		this.x1 = p1.x;
		this.x2 = p2.x;
		this.y1 = p1.y;
		this.y2 = p2.y;
	}
	
	Line line()
	{
		Line l = new Line();
		double dirX = x2 - x1;
		double dirY = y2 - y1;
		l.a = dirY;
		l.b = -dirX;
		l.c = dirY*x1-dirX*y1;
		return l;
	}
	
	boolean contains(Point p)
	{
		Point p1 = new Point(x1,y1);
		Point p2 = new Point(x2,y2);
		return p1.distance(p2) == p.distance(p1) + p.distance(p2);
	}
	
	double orientation(Point p)
	{
		return (y2-y1)*(p.x-x2)-(p.y-y2)*(x2-x1);
	}
	
	boolean intersects(Segment s)
	{
		double o1 = orientation(new Point(s.x1,s.y1));
		double o2 = orientation(new Point(s.x2,s.y2));
		double o3 = s.orientation(new Point(x1,y1));
		double o4 = s.orientation(new Point(x2,y2));
		
		return  o1 != o2 && o3 != o4;
		
	}
	
	// nem feladat
	boolean isParallelWith(Line l)
	{
		return line().isParallelWith(l);
	}
	
	//nem feladat
	boolean isOrthogonalTo(Line l)
	{
		return line().isOrthogonalTo(l);
	}
}