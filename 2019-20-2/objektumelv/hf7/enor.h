#pragma once

#include <string>
#include <fstream>

enum Status { abnorm, norm };

struct Recipe 
{
    std::string name;
    std::string ingredient;
    int amount;
    std::string amount_type;
};

struct RecipeLength 
{
    std::string name;
    int db;
};

class Enor
{
    public:
        enum Errors { FILEERROR };
        Enor(const std::string &str);
        void first() { read(); next(); }
        void next();
        RecipeLength current() const { return _current; }
        bool end() const { return _end; }
    private:
        std::ifstream _x;
        Recipe _dx;
        Status _sx;
        RecipeLength _current;
        bool _end;

        void read();
};


