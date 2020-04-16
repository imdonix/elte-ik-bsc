/*
ZH megoldas
A kivalo szint fajlszerkezetere lett irva, a ket megoldas egyben talalhato.

*/

#ifndef INFILE_H
#define INFILE_H

#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>


struct Measurement
{
    std::string date;
    int weight;
    int distance;
    friend std::istream &operator>>(std::istream &is, Measurement &m);
};

struct Station
{
    std::string name;
    std::string station;
    int lastWeight; //megfelelt szint
    bool close; //megfelelt szint
    friend std::istream &operator>>(std::istream &is, Station &s);
};

struct BlackHole
{
    std::string name;
    double avgOfWeights;
    bool allClose; //kivalo szint
};

enum Status {norm, abnorm};

class inFileMax
{
    public:
        enum Error {FILE_ERROR};
        inFileMax(const std::string fileName);
        ~inFileMax() { _x.close(); }
        void first() { read(); }
        void next() { read(); }
        Station current() const { return _dx; }
        bool end() const { return _sx==abnorm; }

    private:
        std::ifstream _x;
        Station _dx;
        Status _sx;

        void read();
};


class inFile
{
    public:
        enum Error {FILE_ERROR};
        inFile(const std::string fileName);
        ~inFile() { _x.close(); }
        void first() { read(); next(); }
        void next();
        BlackHole current() const { return _cur; }
        bool end() const { return _end; }

    private:
        std::ifstream _x;
        Station _dx;
        Status _sx;
        bool _end;
        BlackHole _cur;

        void read();
};

#endif // INFILE_H
