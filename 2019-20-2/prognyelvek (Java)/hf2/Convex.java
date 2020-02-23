class Convex
{	
	public static void main(String[] args)
	{
		Point[] points = new Point[args.length];
		for(int i=0;i<args.length;i++)
		{
			String[] cordinates = args[i].split(";");
			points[i] = new Point(Double.parseDouble(cordinates[0]), Double.parseDouble(cordinates[1]));
		}
		
		Segment[] segments = new Segment[args.length+1];
		segments[0] = new Segment(points[0], points[args.length-1]);
		for(int i=0;i<args.length-1;i++)
			segments[i] = new Segment(points[i], points[i+1]);
		
		boolean valid = true;
		for(int i=0;i<args.length+1;i++)
			for(int j=i;j<args.length;j++)
			valid = valid && !segments[i].intersects(segments[j]);
		
		boolean convex = true;
		for(int i=0;i<args.length+1;i++)
			for(int j=0;j<args.length+1;j++)
				if(Math.abs(j-i) > 1)
					convex = convex && !segments[i].intersects(segments[j]);
		
		System.out.println((convex && valid));
	}
}