#include "nmatrix.h"

void NMatrix::resize(int _n)
{
    n = _n;
    v1.resize(n+1,0);
    v2.resize(n*2,0);
}

int NMatrix::operator()(int i, int j) const 
{
    if (i > n || i < 1 || j > n || j < 1) throw OVERINDEXED;

    if((i==j))
        return v1[i];
    else if(j==n)
        return v2[n+i-1];
    else if(j==1)
        return v2[i-1];
    else
        return 0;
}

int& NMatrix::operator()(int i, int j)
{
    if (i > n || i < 1 || j > n || j < 1) throw OVERINDEXED;

    if((i==j))
        return v1[i];
    else if(j==n)
        return v2[n+i-1];
    else if(j==1)
        return v2[i-1];
    else
        throw NULLPART;
}

NMatrix operator+ (const NMatrix& a, const NMatrix& b)
{
    if(a.n!=b.n) throw NMatrix::DIFFERENT;

    NMatrix n(a.n);
    for(int i=1;i<=a.n;i++)
        n.v1[i] = a.v1[i] + b.v1[i];
    for(int i=1;i<=a.n*2-2;i++)
        n.v2[i] = a.v2[i] + b.v2[i];
    return n;
}

NMatrix operator* (const NMatrix& a, const NMatrix& b)
{
    if(a.n!=b.n) throw NMatrix::DIFFERENT;

    NMatrix n(a.n);

    //left side
    for(int i = 1; i <= a.n; ++i)
        for(int k = 1; k <= a.n; ++k)
            n(i,1) += a(i,k) * b(k,1);

    //right side
    if(a.n != 1)
        for(int i = 1; i <= a.n; ++i)
            for(int k = 1; k <= a.n; ++k)
                n(i,a.n) += a(i,k) * b(k,a.n);

    //diag
    for(int i = 2; i < a.n; ++i)
        for(int k = 1; k <= a.n; ++k)
            n(i,i) += a(i,k) * b(k,i);

    return n;
}

ostream& operator<< (ostream& s, const NMatrix& a)
{
    for(int i=1;i<=a.n;i++)
    {
        s << "| ";
        for(int j=1;j<=a.n;j++)
            s << a(i,j) << " ";
        s << "|" << endl;
    }

    return s;
}

istream& operator>>(istream& s, NMatrix& a)
{
    int n;
    s >> n;
    a.resize(n);

    for(int i=1;i<=a.n;i++)
        s >> a.v1[i];
    
    for(int i=1;i<=a.n*2-2;i++)
        s >> a.v2[i];

    return s;
}