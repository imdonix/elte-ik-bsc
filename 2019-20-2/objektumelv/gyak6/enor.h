#pragma once

#include <fstream>

struct Pair {
    int n;
    int db;
};

enum Status { abnorm, norm };

class Enor
{
    public:
        enum Errors { FILEERROR };

        Enor(const std::string &str);
        void first() { read(); next(); }
        void next();
        Pair current() const { return _cur; }
        bool end() const { return _end; }
    private:
        std::ifstream _x;
        int _dx;
        Status _sx;
        Pair _cur;
        bool _end;

        void read();
};
