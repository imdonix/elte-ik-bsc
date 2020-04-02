#pragma once

#include <string>
#include <fstream>

enum Status { abnorm, norm };

struct Zsakmany {
    std::string nev;
    std::string faj;
    int suly;
};

class Enor
{
    public:
        enum Errors { FILEERROR };
        Enor(const std::string &str);
        void first() { read(); next(); }
        void next();
        bool current() const { return _current; }
        bool end() const { return _end; }
    private:
        std::ifstream _x;
        Zsakmany _dx;
        Status _sx;
        bool _current;
        bool _end;

        void read();
};


