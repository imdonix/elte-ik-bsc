//Author:   Gregorics Tibor
//Date:     2018.06.30.
//Task:     Counting

#pragma once

#include "summation.hpp"

//template class of counting
//template parameters:  Item    - the type of the elements that are enumerated
//overrode methods:     init(), add(), neutral()
template < typename Item >
class Counting : public Summation<Item, int>
{
protected:
    int neutral() const final override { return 0; }
    int add(const int &a, const int &b) const final override { return a + b; }
    int func(const Item &e) const final override { return 1; }
};
