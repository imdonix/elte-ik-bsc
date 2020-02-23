class Complex
{
	double re,im;
	
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
		double temp = re;
		re=(re*c.re) - (im*c.im);
		im=(temp*c.im) + (im*c.re);
	}
	
	void conjugate()
	{
		im*=-1;
	}
	
    void reciprocate() {
        double scale = re*re + im*im;
        re = re / scale;
		im = -im / scale;
    }
	
	void div(Complex c)
	{
		// Division : Smith's formula.
		double t=re;
		if (Math.abs(c.im) < Math.abs(c.re))
		{
			double d=c.im/c.re;
			 re=(re+im*d)/(c.re+c.im*d);
			 im=(im-t*d)/(c.re+c.im*d);
		}
		else
		{
			double e=c.re/c.im;
			re=(im+re*e)/(c.im+c.re*e);
			im=(-t+im*e)/(c.im+c.re*e);
		}
	}
	
	void print()
	{
		if(im==0.0)
			System.out.println(re);
		else
			System.out.println(re + ((im >= 0) ? " + " : " - ") + Math.abs(im) + "i");
	}
}