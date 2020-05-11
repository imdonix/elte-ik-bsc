//Author:   Gregorics Tibor
//Date:     2017.08.31.
//Title:    enumerating the element of an interval

#pragma once

#include "enumerator.hpp"

//template class of enumerations over intervals
//template parameters:  Item    - the type of the elements that are enumerated
//overrode methods:     first(), next(), end(), current()
//representation:       int _m, _n  - the ends of the interval that must be enumerated
//                      int _ind    - index of enumeration
class IntervalEnumerator : public Enumerator<int>
{
private:
    int _m, _n;
    int _ind;
public:
    IntervalEnumerator(int m, int n): _m(m), _n(n) {}
    void first() override { _ind = _m;}
    void next() override { ++_ind; }
    int current() const override { return _ind; }
    bool end() const override { return _ind>_n; }
};
