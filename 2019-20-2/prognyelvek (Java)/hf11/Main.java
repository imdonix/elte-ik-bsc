class Square implements Shape
{
	double x;
	Square(double x){this.x=x;}
	
	public double getPerimeter(){return 4*x;}
	public double getArea(){return x*x;}
}

class Rectangle implements Shape
{
	double x,y;
	Rectangle(double x,double y){this.x=x;this.y=y;}
	
	@Override public double getPerimeter(){return 2*x+2*y;}
	@Override public double getArea(){return x*y;}
}

class Circle implements Shape
{
	double r;
	Circle(double r){this.r=r;}
	
	@Override public double getPerimeter(){return 2*r*Math.PI;}
	@Override public double getArea(){return r*r*Math.PI;}
}

class Main
{
	
	public static void main(String[] args)
	{
		Shape s1 = new Square(2);
		Shape s2 = new Rectangle(2,4);
		Shape s3 = new Circle(1);
		

		System.out.println(s1.getPerimeter());
		System.out.println(s1.getArea());
		System.out.println(s2.getPerimeter());
		System.out.println(s2.getArea());
		System.out.println(s3.getPerimeter());
		System.out.println(s3.getArea());
	}
}