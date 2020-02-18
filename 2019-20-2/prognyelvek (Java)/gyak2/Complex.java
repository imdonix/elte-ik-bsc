class Complex
{
	int re,im;
	
	double abs()
	{
		return Math.sqrt(re*re + im*im);
	}
	
	void add(Complex c)
	{
		re+=c.re;
		im+=c.im;
	}
	
	void sub(Complex c)
	{
		re-=c.re;
		im-=c.im;
	}
	
	void mul(Complex c)
	{
		int temp = re;
		re=(re*c.re) - (im*c.im);
		im=(temp*c.im) + (im*c.re);
	}
	
	void print()
	{
		System.out.println("C: re=" + re + " im=" + im);
	}
}