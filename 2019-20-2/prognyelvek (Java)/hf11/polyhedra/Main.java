package polyhedra;

class Cylinder extends Prism
{
	double r;
	
	public Cylinder(double r, double h)
	{
		this.r=r;
		this.h=h;
	}
	
	@Override
	protected double baseArea()
	{
		return r*r*Math.PI;
	}
	
	@Override
	public String toString()
	{
		return "Cylinder : (h=" + h + " , r=" + r + ")";
	}
}

class Cube extends Prism
{	
	public Cube(double h)
	{
		this.h=h;
	}

	@Override
	protected double baseArea()
	{
		return h*h;
	}
	
	@Override
	public String toString()
	{
		return "Cube : (h=" + h + ")";
	}
}

class Main
{
	public static void main(String[] args)
	{
		Prism c = new Cylinder(2,4);
		Prism d = new Cube(3);
		
		System.out.println(c.toString());
		System.out.println(c.volume());
		System.out.println(d.toString());
		System.out.println(d.volume());
	}
	
	
}