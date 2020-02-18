class PointMain
{
	public static void main(String[] args)
	{
		Point p = new Point();
		Point o = new Point();
		o.x = 0;
		o.y = 0;
		p.x = 2;
		p.y = 4;
				
		p.move(1,2);
		p.print();
		
		p.mirror(o);		
		p.print();
		
		System.out.println(p.distance(o));
		
		//comp
		
		Complex c = new Complex();
		c.re = 4;
		c.im = 3;
		
		Complex d = new Complex();
		d.re = 4;
		d.im = 3;

		
		System.out.println(c.abs());

		c.mul(d);
		c.print();
		
		//circle
		Circle e = new Circle();
		e.p = p;
		e.r = 1;
		
		e.enlarge(1);
		System.out.println(e.getArea());
		
		//line
		Line f = new Line();
		f.a = f.b = 1;
		f.c = 0;
		
		Line g = new Line();
		g.a = g.b = 2;
		g.c = 0;
		
		
		System.out.println(f.contains(p));
		System.out.println(f.isParallelWith(g));
		System.out.println(f.isOrthogonalTo(g));

	}
	
}