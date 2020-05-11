// Név:         Magyar Tamás
// Neptun:      RNYR2F
// Cím:         10. Szorgalmi
// Fordító:     g++ | gcc version 7.2.0

#include <iostream>
#include <vector>
#include <fstream>

#include "library/intervalenumerator.hpp"
#include "library/arrayenumerator.hpp"
#include "library/summation.hpp"

using namespace std;

class SelectThree : public Summation<int, std::vector<int>>
{
    protected:
        bool cond(const int& e) const { return !(e % 3); }
        int func(const int& e) const {return e;}
};

class SumOfTwo : public Summation<int>
{
    int func(const int& e) const { return e; };
    int neutral() const { return 0; };
    int add( const int& a, const int& b) const { return a+b; };
    bool cond(const int& e) const { return !(e % 2); }
};

class PrintToFile : public Summation<int, std::ostream>
{
    protected:
        std::string func(const int& e) const {return to_string(e) + "\n";};
    public:
        PrintToFile(std::ostream *o) : Summation(o) {}
};

int main()
{
    int N,M;
    cout << "Irj be ket szamot ami kozott akarsz keresni:" << endl;
    cin >> M >> N;

    IntervalEnumerator enumerator(M,N);
    SelectThree pr1;
    pr1.addEnumerator(&enumerator);
    pr1.run();
    vector<int> res = pr1.result();

    enumerator.first();
    SumOfTwo pr2;
    pr2.addEnumerator(&enumerator);
    pr2.run();
    res.push_back(pr2.result());

    ofstream f("output.txt", ofstream::out);
    ArrayEnumerator<int> printenor(&res);
    PrintToFile print(&f);
    print.addEnumerator(&printenor);
    print.run();

    return 0;
}