#include "enor_2.h"

Enor::Enor(const std::string &str)
{
    _x.open(str);
    if(_x.fail()) throw FILEERROR;
}

void Enor::next()
{
    if ( !(_end = (abnorm==_sx)) ){
        std::string nev = _dx.nev;
        _current.nev = nev;
        _current.suly = 0;
        for( ; norm==_sx && _dx.nev==nev; read() ){
            _current.suly += _dx.suly;
        }
    }
}

void Enor::read()
{
    _x >> _dx.nev >> _dx.faj >> _dx.suly;
    _sx = _x.fail() ? abnorm : norm;
}
