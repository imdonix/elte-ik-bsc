#include <iostream>
#include <vector>
#include "library/summation.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/summation.hpp"
#include "library/counting.hpp"

using namespace std;

#define ERROR_FLAG "ERROR"

struct Post
{
  int time;
  string data;

  friend istream& operator>>(istream &s, Post &d){return s >> d.time >> d.data;}
};

struct Res
{
    int c;
    int s;

    Res(int count, int sum) : c(count), s(sum) {};
    Res() : c(0), s(0) {};
    Res operator+(const Res& a) const {return Res(a.c+c, a.s+s);}
};

class ErrorSum : public Counting<Post>
{
    protected:
        virtual bool cond(const Post& e) const {return e.data == ERROR_FLAG;}
};

struct Log
{
    string name;
    string id;
    int errors;

    friend istream& operator >> (istream& i, Log& l)
    {
        string str;
        getline(i, str);
        stringstream ss(str);

        ss >> l.name >> l.id;

        StringStreamEnumerator<Post> e(ss);
        ErrorSum sum;
        sum.addEnumerator(&e);
        sum.run();

        l.errors = sum.result();

        return i;
    };
};

class ErrorAndSum : public Summation<Log, Res>{
  protected:

    virtual bool cond(const Log& e) const {return e.errors > 0; }
    virtual Res func(const Log& e) const override {return Res(1, e.errors);};
    virtual Res neutral() const override {return Res();};
    virtual Res add( const Res& a, const Res& b) const override {return a+b;};
};


int main(int argc, char** argv)
{
    if(argc != 2)
    {
        cout << "Add meg a fajl nevet parameternek!";
        return 1;
    }

    SeqInFileEnumerator<Log> e(argv[1]);
    ErrorAndSum sum;
    sum.addEnumerator(&e);
    sum.run();

    Res r = sum.result();

    if(r.c == 0)
        cout << "Nem talalhato hibas küldetes a naploban!";
    else
        cout << "A hibas kuldetesek hibaszamainak atlaga: " << (((float)r.s)/r.c);

    return 0;
}
