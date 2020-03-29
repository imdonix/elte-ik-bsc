//Author:   Magyar Tamás
//Date:     2020-03-29
//Title:    Anglers
#pragma once

#include <fstream>
#include <sstream>
#include <string>

struct Contest 
{
    std::string angler;
    std::string contest;
    bool catfish_catch;
};

class ContestEnor
{
    private:
        std::ifstream _f;
        Contest _cur;
        bool _end;
    public:
        enum FileError{MissingInputFile};
        ContestEnor(const std::string &str);
        void first() {next();}
        void next();
        Contest current() const { return _cur;}
        bool end() const { return _end;}
};
