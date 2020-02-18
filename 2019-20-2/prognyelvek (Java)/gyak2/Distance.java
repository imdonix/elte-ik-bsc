class Distance
{
	public static void main(String[] args)
	{
		Point[] ps = new Point[args.length/2];
		for(int i=0;i<args.length/2;i++)
		{
			Point p = new Point();
			p.x = Integer.parseInt(args[i*2]);
			p.y = Integer.parseInt(args[i*2+1]);
			ps[i]=p;
		}
		
		double s = 0;
		for(int i=1;i<args.length/2;i++)
			s+= ps[i].distance(ps[i-1]);
		System.out.println(s);
	}
}