//Author:   Gregorics Tibor
//Date:     2017.08.31.
//Title:    enumerating the element of an array

#pragma once

#include "enumerator.hpp"
#include <vector>

//template class of enumerations over arrays
//template parameters:  Item    - the type of the elements that are enumerated
//overrode methods:     first(), next(), end(), current()
//representation:       vector<Item> *_vect - the array that must be enumerated
//                      int _ind            - index of enumeration
template <typename Item>
class ArrayEnumerator : public Enumerator<Item>
{
    protected:
        const std::vector<Item> _vect;
        int   _ind;

    public:
        ArrayEnumerator(const std::vector<Item> &v):_vect(v) {}

        void first()  final override { _ind = 0;}
        void next()   final override { ++_ind; }
        bool end()    const final override { return _ind>=(int)_vect.size();}
        Item current()const final override { return _vect[_ind];}
};

