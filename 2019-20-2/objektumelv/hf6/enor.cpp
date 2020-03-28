// 6. kisbeadandó
// Magyar Tamás
// 2020-03-28

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
    if (!_end) read();       
}

void Enor::read()
{
    _x >> _dx;
    if (_x.fail()) _sx = abnorm;
    else _sx= norm;
}