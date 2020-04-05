#include "enor.h"

Enor::Enor(const std::string &str)
{
    _x.open(str);
    if(_x.fail()) throw FILEERROR;
}

void Enor::next()
{
    if ( !(_end = (abnorm==_sx)) ){
        _current.name = _dx.name;
        _current.db = 0;
        for(; norm==_sx && _dx.name==_current.name; read())
            _current.db++;
    }
}

void Enor::read()
{
    _x >> _dx.name >> _dx.ingredient >> _dx.amount >> _dx.amount_type;
    _sx = _x.fail() ? abnorm : norm;
}
