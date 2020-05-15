#include <iostream>
#include <sstream>

#include "library/summation.hpp"
#include "library/maxsearch.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"


using namespace std;

struct Sample
{
    string date;
    int weight;
    int distance;
    friend istream& operator>>(istream &s, Sample &d){
      s >> d.date >> d.weight >>  d.distance;
      return s;
    }
};

struct SampleResult
{
  int lastWeight;
  bool wasClose;
};


class SampleSummation: public Summation<Sample, SampleResult>{
protected:
    virtual SampleResult func(const Sample& e) const override {
      return {e.weight, e.distance < 3};
    };
    virtual SampleResult neutral() const override{
      return {0, false};
    }
    virtual SampleResult add( const SampleResult& a, const SampleResult& b) const override {
      return {b.lastWeight, a.wasClose || b.wasClose };
    }
};

struct Line
{
  string id;
  string station;
  int lastWeight;
  bool wasClose;
  friend istream& operator>>(istream &s, Line &d){
    string str;
    getline(s, str);
    stringstream ss(str);

    ss >> d.id >> d.station;
    StringStreamEnumerator<Sample> e(ss);

    SampleSummation sum;
    sum.addEnumerator(&e);
    sum.run();

    d.lastWeight = sum.result().lastWeight;
    d.wasClose = sum.result().wasClose;
    return s;
  }
};

class LineMaxSearch: public MaxSearch<Line, int, Greater<int>>{
  
protected:
  virtual int func(const Line& e) const override {
    return e.lastWeight;
  };
  virtual bool cond(const Line& e) const override { return e.wasClose; }
};


struct BlackHole
{
  string id;
  bool isDangerous;
};

class BlackHoleSum: public Summation<Line, bool>{
  private: 
    string _id;
  public: 
    BlackHoleSum(string id): _id(id){}
  protected: 
    virtual bool func(const Line& e) const override {
      return e.wasClose;
    }
    virtual bool neutral() const override {
      return true;
    }
    virtual bool add( const bool& a, const bool& b) const override {
      return a && b;
    }
    virtual bool whileCond(const Line& e) const override { return e.id == _id; }
    virtual void first() override {}
};

class BlackHoleEnor: public Enumerator<BlackHole>{
  private:
    BlackHole _cur;
    bool _end;
    Enumerator<Line> *_f;

  public:
      BlackHoleEnor(Enumerator<Line> *f): _f(f) {}
      virtual void first() override {
        _f->first();
        next();
      }
      virtual void next() override {
        if(!(_end = _f->end())){
          _cur.id = _f->current().id;

          BlackHoleSum sum(_cur.id);
          sum.addEnumerator(_f);
          sum.run();
          _cur.isDangerous = sum.result();
        }
      }
      virtual bool end() const override {return _end;}
      virtual BlackHole current() const override {return _cur;}
};

class CoutProcedure: public Procedure<BlackHole>{
  protected:
    virtual void init() override {}
    virtual void body(const BlackHole& e) {
      if(e.isDangerous)
        cout << e.id << endl;
    };
};

int main(){
  SeqInFileEnumerator<Line> e("input.txt");

  LineMaxSearch mx;
  mx.addEnumerator(&e);
  mx.run();
  if(mx.found()){
    cout << "maximalis meretu fekete lyuk: " << mx.optElem().id << " "
    << mx.optElem().station << " "
    << mx.optElem().lastWeight << endl;
  }
  else{
    cout << "nem volt a feltetelnek megfelelo fekete lyuk" << endl;
  }

  SeqInFileEnumerator<Line> e2("input.txt");
  BlackHoleEnor e3(&e2);

  CoutProcedure c;
  c.addEnumerator(&e3);
  c.run();

  /*e3.first();
  while (!e3.end())
  {
    cout << e3.current().id << " " << e3.current().isDangerous << " " << endl;
    e3.next();
  }*/
  

}