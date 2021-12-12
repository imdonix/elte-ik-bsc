//Magyar Tamás - RNYR2F
//g++.exe (GCC) 4.8.3

#include <iostream>

class Matrix
{

private:

    int n;
    short* arr;

public:

    Matrix(int n)
    {
        this->n = n;
        this->arr = new short[n * n];
    }

    Matrix(const Matrix &mat)
    {
        this->n = mat.n;
        this->arr = new short[n * n];
        for(int i = 0; i < n * n; i++)
            this->arr[i] = mat.arr[i];
    }

    ~Matrix()
    {
        delete[] arr;
    }

    int size() const
    {
        return this->n;
    }

    short get(const int x, const int y) const
    {
        if(x >= 0 && x < n && y >= 0 && y < n)
            return arr[y * n + x];
        else
            return (short) 0;
    }

    void set(const int x, const int y, short val)
    {
        arr[y * n + x] = val;
    }

};

std::ostream & operator<<(std::ostream & os, const Matrix& mat)
{
    std::cout << std::endl;
    for(int x = 0; x < mat.size(); x++)
    {
        for(int y = 0; y < mat.size(); y++)
        {
            std::cout << mat.get(y,x) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "---" << std::endl;
}

// ((bal sz + jobb sz) ∗ (felso sz + also sz) + aktualis allapot) mod 5
short f(short b, short t, short l, short r, short self)
{
    return ((l + r) * (b + t) + self) % 5;
}

int main()
{
    const int ROUND = 10;

    Matrix m(3);
    m.set(0,0,1);m.set(0,1,2);m.set(0,2,1);
    m.set(1,0,2);m.set(1,1,3);m.set(1,2,2);
    m.set(2,0,1);m.set(2,1,2);m.set(2,2,1);

    std::cout << "Start:";
    std::cout << m;

    for(int c = 0; c < ROUND; c++)
    {   
        Matrix tmp(m);
        for(int x = 0; x < m.size(); x++)
            for(int y = 0; y < m.size(); y++)
                tmp.set(x,y, f(m.get(x,y-1), m.get(x,y+1), m.get(x-1,y), m.get(x+1,y), m.get(x,y)));
                
        m = tmp;

        std::cout << "Round [" << c+1 << "]";
        std::cout << m;
    }
}