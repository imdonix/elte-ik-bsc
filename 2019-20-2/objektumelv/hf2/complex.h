#pragma once

class Complex{
    private:
        double x;
        double y;
    public:
        Complex(double re, double im)
        {
            x=re;
            y=im;
        }
        double getReal(){return x;}
        double getImaginary(){return y;}
        void add(Complex c);
        void multiple(Complex c);
        void divide(Complex c);
};