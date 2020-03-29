//Author:   Magyar Tamás
//Date:     2020-03-29
//Title:    Anglers
#pragma once

#include "contest.h"
#include <string>


struct Angler 
{
    std::string name;
    bool skillful;
};

class AnglerEnor
{
    private:
        ContestEnor _tt;
        Angler _cur;
        bool _end;
    public:
        AnglerEnor(const std::string &str): _tt(str) { };
        void first() {_tt.first(); next();}
        void next();
        Angler current() const { return _cur;}
        bool end() const { return _end;}
};

