#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/maxsearch.hpp"
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"

using namespace std;

struct Mark     // Line
{
    string name;
    int mark;
};

istream& operator>>(istream &inp, Mark &e)
{
    inp >> e.name >> e.mark;
    return inp;
}

struct Student
{
    string name;
    double avr;
};

class StudentEnumerator : public Enumerator<Student>
{
private:
    SeqInFileEnumerator<Mark> _f;
    Student _student;
    bool _end;
public:
    StudentEnumerator(const string &fname): _f(fname) {}
    void first() override { _f.first(); next();}
    void next() override;
    Student current() const override { return _student; }
    bool end() const override { return _end; }
};

class BestStudent : public MaxSearch<Student,double>
{
protected:
    double func(const Student &e) const override { return e.avr; }
};

int main(int argc, char* argv[])
{
    string inputfile_name = (argc==1)? "input.txt" : argv[1];

    BestStudent pr;
    StudentEnumerator enor("input.txt");
    pr.addEnumerator(&enor);

    pr.run();

    if(!pr.found()) cout << "Nincs hallgato!\n";
    else cout << pr.optElem().name << " a legjobb hallgato, akinek az átlaga: " << pr.opt() << endl;;
    return 0;
}

struct Pair {
    int sum;
    int count;
    Pair(){}
    Pair(int a, int b) : sum(a), count(b) {}
};

class Average : public Summation<Mark, Pair>
{
private:
    string _name;
public:
    Average(const string &name) : _name(name) {}
protected:
    Pair func(const Mark &e) const override { return Pair(e.mark, 1); }
    Pair neutral() const override { return Pair(0, 0); }
    Pair add(const Pair &a, const Pair &b) const override { return Pair(a.sum+b.sum, a.count+b.count);}
    bool whileCond(const Mark &e) const override { return e.name==_name; }
    void first() override {}
};

void StudentEnumerator::next()
{
    if((_end = _f.end()));
    _student.name = _f.current().name;
    Average pr(_student.name);
    pr.addEnumerator(&_f);

    pr.run();

    if(pr.result().count>0) _student.avr = (double) pr.result().sum / pr.result().count;
    else _student.avr = 0.0;
}



