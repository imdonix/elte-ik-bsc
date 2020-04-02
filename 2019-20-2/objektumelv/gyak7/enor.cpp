#include "enor.h"

Enor::Enor(const std::string &str)
{
    _x.open(str);
    if(_x.fail()) throw FILEERROR;
}

void Enor::next()
{
    if ( !(_end = (abnorm==_sx)) ){
        std::string nev = _dx.nev;
        _current = false;
        for( ; norm==_sx && _dx.nev==nev; read() ){
            _current = _current || ("MEDVE"==_dx.faj);
        }
    }
}

void Enor::read()
{
    _x >> _dx.nev >> _dx.faj >> _dx.suly;
    _sx = _x.fail() ? abnorm : norm;
}
