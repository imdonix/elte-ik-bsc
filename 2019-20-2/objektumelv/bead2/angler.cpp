//Author:   Magyar Tamás
//Date:     2020-03-29
//Title:    Anglers
#include "angler.h"

using namespace std;

void AnglerEnor::next()
{
    if( !(_end = _tt.end()) )
    {
        _cur.name = _tt.current().angler;
        _cur.skillful = true;
        for(; !_tt.end() && _tt.current().angler == _cur.name; _tt.next())
            _cur.skillful = _cur.skillful && _tt.current().catfish_catch;
    }
}
