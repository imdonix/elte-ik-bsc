#include <iostream>
#include "library/seqinfileenumerator.hpp"
#include "library/maxsearch.hpp"

using namespace std;

struct NameCount{ string name; int c;};
struct Name
{  
    string first;  string last;
    friend istream& operator>>(istream &is, Name &name)
    { return (is >> name.first >> name.last);}
};

class NameCountEnumerator : public Enumerator<NameCount>
{
    private:
        SeqInFileEnumerator<Name> _en;
        NameCount _x;
    public:
        NameCountEnumerator(string inp) : _en(inp) {}
        void first() { _en.first(); }
        bool end() const {return _en.end();}
        NameCount current() const { return _x;}

        void next() 
        {
            _x.name = _en.current().last;
            _x.c = 0;
            for(; _en.current().last == _x.name && !_en.end(); _en.next()) _x.c++;
        }
};

class MostCommonName : public MaxSearch<NameCount, int, Greater<int>>
{
    int func(const NameCount& e) const {return e.c;};
};


int main()
{
    NameCountEnumerator enumerator("input.txt");
    MostCommonName proc;
    proc.addEnumerator(&enumerator);
    proc.run();
    cout << proc.optElem().name << proc.optElem().c;

    return 0;
}