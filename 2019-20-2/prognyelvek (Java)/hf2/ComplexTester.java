class ComplexTester
{
	public static void main(String[] args)
	{
		Complex a = new Complex();
		a.re = 1;
		a.im = 2;
		
		Complex b = new Complex();
		b.re = 1;
		b.im = -2;
		
		
		System.out.print("a := ");
		a.print();
		System.out.print("b := ");
		a.print();
		
		//con
		System.out.print("a := con(a) = ");
		a.conjugate();
		a.print();
		
		//rec
		System.out.print("a := rec(a) = ");
		a.reciprocate();
		a.print();
		
		System.out.print("a := a x b = ");
		a.mul(b);
		a.print();
		
		//div
		System.out.print("b := b / a = ");
		b.div(a);
		b.print();
		
		System.out.print("b := b / b = ");
		b.div(b);
		b.print();
		
	}
}