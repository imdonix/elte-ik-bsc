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
    if (!_end) {
        _cur.n = _dx;
        _cur.db = 0;
        for( ; norm==_sx && _dx==_cur.n ; read() ){
            ++_cur.db;
        }
    }
}

void Enor::read()
{
    _x >> _dx;
    if ( _x.fail() ) _sx = abnorm;
    else _sx= norm;
}
