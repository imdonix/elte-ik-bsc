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
//                      unsigned int _ind            - index of enumeration
template <typename Item>
class ArrayEnumerator : public Enumerator<Item>
{
    protected:
        const std::vector<Item> *_vect;
        unsigned int             _ind;

    public:
        ArrayEnumerator(const std::vector<Item> *v):_vect(v){}
        void first()         override { _ind = 0; }
        void next()          override { ++_ind; }
        bool end()     const override { return _ind>=_vect->size(); }
        Item current() const override { return (*_vect)[_ind]; }
};

