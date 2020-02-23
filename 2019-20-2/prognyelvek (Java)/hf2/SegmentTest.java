class SegmentTest
{
	public static void main(String[] args)
	{
		Segment s = new Segment(0,0,10,0);		
		Line l = s.line();
		l.print();
		
		Point p1 = new Point(9.99,0);
		Point p2 = new Point(0,4);
		
		System.out.println(s.contains(p1));
		System.out.println(s.contains(p2));
		
		Line l1 = new Line();
		l1.a = 0; l1.b = 1; l1.c = 0;
	
		Line l2 = new Line();
		l2.a = 1; l2.b = 0; l2.c = 0;
		
		System.out.println(s.isParallelWith(l1));
		System.out.println(s.isParallelWith(l2));
		
		System.out.println(s.orientation(p1));
		System.out.println(s.orientation(p2));
		
		Segment a = new Segment(0,-1,0,-2);
		Segment b = new Segment(0,1,10,1);
		
		System.out.println(s.intersects(a));
		System.out.println(s.intersects(b));		
	}
	
	
}