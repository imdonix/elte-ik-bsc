// 6. kisbeadandó
// Magyar Tamás
// 2020-04-03
// v2

#include "enor.h"

using namespace std;

Enor::Enor(const string &str)
{
    _x.open(str);
    if(_x.fail()) throw FILEERROR;
}

void Enor::next()
{
    _end = (abnorm==_sx);
    if (!_end)
    {
        _cur.name = _dx.name;
        _cur.income = 0;
        for(;norm==_sx&&_dx.name==_cur.name;read())
            _cur.income+=f(_dx);
    } 
}

void Enor::read()
{
    _x >> _dx;
    if (_x.fail()) _sx = abnorm;
    else _sx= norm;
}

int Enor::f(Order o){ return o.db*o.price; }