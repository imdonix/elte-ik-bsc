//Author:   Gregorics Tibor
//Date:     2018.06.30.
//Task:     Linear search

#pragma once

#include "procedure.hpp"

//template class of linear search
//template parameters:  Item            - the type of the elements that are enumerated
//                      bool optimist   - sets the version of linear search
//overrode methods:     init(), whileCond(), body()
//new methods:          found(), elem() - gives back the result of linear search
//new virtual methods:  cond()          - defines a condition on an Item type element
//representation:       bool _l         - logical variable of linear search
//                      Item _elem      - current element of linear search
template < typename Item, bool optimist >
class LinSearch : public Procedure<Item>
{
protected:
    bool _l;
    Item _elem;

    void init() final override { _l = optimist; }
    void body(const Item& e) final override { _l = cond(_elem = e); }
    bool whileCond(const Item& e) const final override { return optimist?_l:!_l;}

    virtual bool cond(const Item& e) const = 0;

public:
    bool found()  const{ return _l; }
    Item elem()   const{ return _elem;}
};

