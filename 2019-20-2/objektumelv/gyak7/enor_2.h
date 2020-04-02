#pragma once

#include <string>
#include <fstream>

enum Status { abnorm, norm };

struct Zsakmany {
    std::string nev;
    std::string faj;
    int suly;
};

struct Vadasz{
    std::string nev;
    int suly;
};

class Enor
{
    public:
        enum Errors { FILEERROR };
        Enor(const std::string &str);
        void first() { read(); next(); }
        void next();
        Vadasz current() const { return _current; }
        bool end() const { return _end; }
    private:
        std::ifstream _x;
        Zsakmany _dx;
        Status _sx;
        Vadasz _current;
        bool _end;

        void read();
};


