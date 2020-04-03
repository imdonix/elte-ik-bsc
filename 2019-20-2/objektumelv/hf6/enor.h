// 6. kisbeadandó
// Magyar Tamás
// 2020-04-03
// v2

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

struct BestOrder
{
    std::string name;
    int income;
};

enum Status { abnorm, norm };

class Enor
{
    public:
        enum Errors { FILEERROR };
        Enor(const std::string &str);
        void first() { read(); next(); }
        void next();
        BestOrder current() const { return _cur; }
        bool end() const { return _end; }
    private:
        int f(Order o);
        std::ifstream _x;
        Order _dx;
        Status _sx;
        BestOrder _cur;
        bool _end;
        void read();
};

inline std::ostream& operator<<(std::ostream& os, const Order& o) { os << "("  << o.table << "|" << o.name << "|" << o.time << "|" << o.db << "|" << o.price << ")"; return os; }
inline std::istream& operator>>(std::istream& is, Order& o) { is >> o.table >>  o.name >>  o.time >>  o.db >> o.price; return is;}