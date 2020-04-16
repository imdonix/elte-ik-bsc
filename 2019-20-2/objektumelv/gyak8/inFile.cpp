#include "inFile.h"

std::istream &operator>>(std::istream &is, Measurement &m)
{
    is >> m.date >> m.weight >> m.distance;
    return is;
}

std::istream &operator>>(std::istream &is, Station &st)
{
    std::string line;
    getline(is,line,'\n');
    std::stringstream ss(line);
    ss >> st.name >> st.station;
    st.close = false;
    st.lastWeight = 0; /// ha nincs adat, ne szálljon el
    Measurement m;

    while (ss >> m)
    {
        st.close = st.close || (m.distance < 2700);
        st.lastWeight = m.weight;
    }
    return is;
}


inFileMax::inFileMax(const std::string fileName)
{
    _x.open(fileName.c_str());
    if (_x.fail()) throw FILE_ERROR;
}

void inFileMax::read()
{
    _sx = (_x >> _dx) ? norm : abnorm;
}



inFile::inFile(const std::string fileName)
{
    _x.open(fileName.c_str());
    if (_x.fail()) throw FILE_ERROR;
}

void inFile::read()
{
    _sx = (_x >> _dx) ? norm : abnorm;
}

void inFile::next()
{
    if ( !(_end = (_sx == abnorm)))
    {
        _cur.name = _dx.name;
        _cur.allClose = true;
        int sumOfWeights = 0;
        int countOfStations = 0;
        for ( ; _sx == norm && _cur.name == _dx.name; read() )
        {
            sumOfWeights += _dx.lastWeight;
            ++countOfStations;
            _cur.allClose = _cur.allClose && _dx.close;
        }
        if (countOfStations > 0)
        {
            _cur.avgOfWeights = double(sumOfWeights) / countOfStations;
        }
        else
        {
            _cur.avgOfWeights = 0;
        }
    }
}
