#pragma once
#include <iostream>
#include <vector>

using namespace std;

// Implementálandó: lekérdezés, összeadás, szorzás, kiírás  || +(értékadás, beolvasás)
class NMatrix
{
    private:
        int n;
        vector<int> v1;
        vector<int> v2;
        void resize(int _n);
    public:
        enum Exceptions{OVERINDEXED, NULLPART, DIFFERENT};
        NMatrix(){};
        NMatrix(int _n): v1(_n+1,0), v2(_n*2,0) {n = _n;}
        int operator()(int i, int j) const;
        int& operator()(int i, int j);
        friend NMatrix operator+ (const NMatrix& a, const NMatrix& b);
        friend NMatrix operator* (const NMatrix& a, const NMatrix& b);
        friend ostream& operator<< (ostream& s, const NMatrix& a);
        friend istream& operator>> (istream& s, NMatrix& a);
};