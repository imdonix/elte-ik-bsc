//Author:   Magyar Tamás
//Date:     2020-03-29
//Title:    Anglers
#include "contest.h"

using namespace std;

ContestEnor::ContestEnor(const std::string &str)
{
    _f.open(str);
    if(_f.fail())throw MissingInputFile;
}

void ContestEnor::next()
{
    string line;
    getline(_f , line);
    if(!(_end = _f.fail()))
    {
        istringstream is(line);
        is >> _cur.angler >> _cur.contest;

        _cur.catfish_catch = false;
        string fish;
        double size;
        for( is >> fish >> size ; !is.fail(); is >> fish >> size )
            _cur.catfish_catch = _cur.catfish_catch || fish == "catfish";
    }
}
