//Author:   Gregorics Tibor
//Date:     2018.06.30.
//Task:     Selection

#pragma once

#include "procedure.hpp"

//template class of linear search
//template parameters:  Item        - the type of the elements that are enumerated
//overrode methods:     init(), loopCond(), body()
//new methods:          result()    - gives back the result of selection
//new virtual methods:  cond()      - defines a condition on an Item type element
template < typename Item >
class Selection : public Procedure<Item>
{
protected:
    void init() override final {}
    void body(const Item& e) override final {}
    bool loopCond() const override final {
        return !cond(Procedure<Item>::_enor->current());
    }
    virtual bool cond(const Item& e) const = 0;
public:
    Item result() const {
        return Procedure<Item>::_enor->current();
    }
};


