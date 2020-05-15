#include <iostream>
#include <fstream>
#include <sstream>

#include "library/summation.hpp"
#include "library/maxsearch.hpp"
#include "library/enumerator.hpp"

#include "library/stringstreamenumerator.hpp"
#include "library/seqinfileenumerator.hpp"


using namespace std;

struct Sample 
{
  string date;
  int weight;
  int distance;

  friend istream& operator>>(istream &s, Sample &d){
    s >> d.date >> d.weight >> d.distance;
    return s;
  }
};

struct SampleResult
{
  int lastWeight;
  bool wasClose;
  SampleResult(int lw, bool c): lastWeight(lw), wasClose(c) {}
  SampleResult() {}
};


class LineSum : public Summation<Sample, SampleResult>
{
protected:
    virtual SampleResult func(const Sample& e) const override {
      return SampleResult(e.weight, e.distance < 3);
    };
    virtual SampleResult neutral() const override { return SampleResult(0, false); };
    virtual SampleResult add( const SampleResult& a, const SampleResult& b) const override {
        return SampleResult(b.lastWeight, a.wasClose || b.wasClose);
    };

};



struct Line
{
  string id;
  string station;
  int lastWeight;
  bool wasClose;
  friend istream& operator>>(istream &s, Line &l){
    string str;
    getline(s, str);

    stringstream ss(str);

    ss >> l.id >> l.station;

    StringStreamEnumerator<Sample> e(ss);
    LineSum sum;
    sum.addEnumerator(&e);
    sum.run();

    l.lastWeight = sum.result().lastWeight;
    l.wasClose = sum.result().wasClose;
  }
};

class LineMaxSearch: public MaxSearch<Line, int, Greater<int> >{
  protected:
    virtual int func(const Line& e) const override {
      return e.lastWeight;
    };
    virtual bool  cond(const Line& e) const override { return e.wasClose; }
};


struct BlackHole
{
  string id;
  bool isDangerous;
};

class BlacHoleSum:public  Summation<Line, bool>{
  private: 
    string _id;
  public: 
    BlacHoleSum(string id) : _id(id) {}
  protected:
    virtual void first() override {}
    virtual bool whileCond(const Line& e) const override { return e.id == _id; }
    virtual bool func(const Line& e) const override {
      return e.wasClose;
    };
    virtual bool neutral() const override { return true; };
    virtual bool add( const bool& a, const bool& b) const override {
        return a && b;
    };
};

class BlackHoleEnor: public Enumerator<BlackHole>{
  private: 
    BlackHole _cur;
    bool _end;

    Enumerator<Line> *_f;

  public:
    BlackHoleEnor(Enumerator<Line> *f): _f(f) {};

    virtual void first() override { _f->first(); next();}
    virtual void next() override {
      if(!(_end = _f->end())){
        _cur.id = _f->current().id;
        BlacHoleSum sum(_cur.id);
        sum.addEnumerator(_f);
        sum.run();
        _cur.isDangerous = sum.result();
      }
    }
    virtual bool end() const override { return _end;}
    virtual BlackHole current() const override { return _cur;}
};

class CoutSum : public Summation<BlackHole, BlackHole>{
  protected:
  
    virtual bool  cond(const BlackHole& e) const { return e.isDangerous; }
    virtual BlackHole func(const BlackHole& e) const override {
      return e;
    };
    virtual BlackHole neutral() const override { return BlackHole(); };
    virtual BlackHole add( const BlackHole& a, const BlackHole& b) const override {
      cout << b.id << " " << b.isDangerous << endl;
      return b;
    };
};

int main(){
  SeqInFileEnumerator<Line> e("input.txt");

  /*e.first();
  while (!e.end())
  {
    cout << e.current().lastWeight <<  e.current().id << endl; 
    e.next();
  }*/
  
  LineMaxSearch mx;
  mx.addEnumerator(&e);
  mx.run();
  if(mx.found()){
    cout << "legnagyobb fekete lyuk: " << mx.optElem().id << " " << mx.optElem().station << " " << mx.opt() << endl;
  }
  else {
    cout << "nem volt ilyen" << endl;
  }

  
  SeqInFileEnumerator<Line> e2("input.txt");
  BlackHoleEnor e3(&e2);

  /*e3.first();
  while (!e3.end())
  {
    if(e3.current().isDangerous) cout << e3.current().isDangerous <<  e3.current().id << endl; 
    e3.next();
  }*/

  CoutSum cs;
  cs.addEnumerator(&e3);
  cs.run();
  

}