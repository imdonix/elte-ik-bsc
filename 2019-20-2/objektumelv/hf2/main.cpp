#include <iostream>
#include <math.h> 
#include "complex.h"

using namespace std;

void write(Complex a);


int main()
{
    Complex a(1,2);
    Complex b(2,2);
    cout << "a = "; write(a);
    cout << "b = "; write(b);

    cout << "a = a + b = ";
    a.add(b);
    write(a);

    cout << "a = a x a = ";
    a.multiple(a);
    write(a);

    cout << "a = a / b = ";
    a.divide(b);
    write(a);

    return 0;
}

void write(Complex a)
{
    cout << a.getReal() << " + " << a.getImaginary() << "i" << endl;
}

void Complex::add(Complex c)
{
    x+=c.x;
    y+=c.y;
}

void Complex::multiple(Complex c)
{
    double t = x;
	x=(x*c.x)-(y*c.y);
	y=(t*c.y)+(y*c.x);
}

void Complex::divide(Complex c)
{
    // Division : Smith's formula.
    double t=x;
    if (abs(c.y) < abs(c.x))
    {
        double d=c.y/c.x;
         x=(x+y*d)/(c.x+c.y*d);
         y=(y-t*d)/(c.x+c.y*d);
    }
    else
    {
        double e=c.x/c.y;
        x=(y+x*e)/(c.y+c.x*e);
        y=(-t+y*e)/(c.y+c.x*e);
    }
}
