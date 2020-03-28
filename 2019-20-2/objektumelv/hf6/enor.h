// 6. kisbeadandó
// Magyar Tamás
// 2020-03-28

#pragma once

#include <fstream>

struct Order 
{
    int table;
    std::string name;
    std::string time;
    int db;
    int price;
};

enum Status { abnorm, norm };

class Enor
{
    public:
        enum Errors { FILEERROR };
        Enor(const std::string &str);
        void first() { read(); next(); }
        void next();
        Order current() const { return _dx; }
        bool end() const { return _end; }
    private:
        std::ifstream _x;
        Order _dx;
        Status _sx;
        bool _end;
        void read();
};

inline std::ostream& operator<<(std::ostream& os, const Order& o) { os << "("  << o.table << "|" << o.name << "|" << o.time << "|" << o.db << "|" << o.price << ")"; return os; }
inline std::istream& operator>>(std::istream& is, Order& o) { is >> o.table >>  o.name >>  o.time >>  o.db >> o.price; return is;}