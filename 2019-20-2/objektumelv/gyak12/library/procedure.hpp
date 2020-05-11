//Author:   Gregorics Tibor
//Date:     2018.06.30.
//Task:     general algorithmic pattern

#pragma once

#include <cstddef>
#include "enumerator.hpp"
#include <iostream>
#include <vector>

template < typename Item, typename Value> class Summation;
template < typename Item> class Summation<Item, std::ostream>;
template < typename Item, typename Value > class Summation<Item, std::vector<Value> > ;
template < typename Value> class Greater;
template < typename Value> class Less;
template < typename Item, typename Value = Item, typename Compare = Greater<Value> > class MaxSearch;
template < typename Item, bool optimist = false> class LinSearch;
template < typename Item> class Selection;

//template class of general programing theorems
//template parameters:  Item    - the type of the elements that are enumerated
//new virtual methods:  init()          - initializes the programming theorem
//                      body()          - one iteration of the programming theorem
//                      first()         - first step of the enumerator
//                      whileCond()     - can stop the enumerator earlier
//                      loopCond()      - loop condition of the programming theorem
//                      run()           - executes the programing theorem
//                      addEnumerator() - gives an enumerator to the programming theorem
//representation:       Enumerator<Item> *_enor
template <typename Item, typename Value = Item, typename Compare = Greater<Value>, bool optimist = false >
class Procedure
{
    friend class Summation<Item, Value>;
    friend class MaxSearch<Item, Value, Compare>;
    friend class LinSearch<Item, optimist>;
    friend class Selection<Item>;

    protected:
        Enumerator<Item> *_enor;

        Procedure():_enor(nullptr){}
        virtual void init() = 0;
        virtual void body(const Item& e) = 0;
        virtual void first() {_enor->first();}
        virtual bool whileCond(const Item& current) const { return true; }
        virtual bool loopCond() const
                   { return !_enor->end() && whileCond(_enor->current()) ; }
    public:
        enum Exceptions { MISSING_ENUMERATOR};
        virtual void run() final;
        virtual void addEnumerator(Enumerator<Item>* en) final { _enor = en;}
        virtual ~Procedure(){}
};

//Task: 	runs the programming theorem
//Input:    Enumerator<Item> *_enor - enumerator
//Activity: algorithm of programming theorem
template <typename Item, typename Value, typename Compare, bool optimist>
void Procedure<Item, Value, Compare, optimist>::run()
{
    if(_enor==nullptr) throw MISSING_ENUMERATOR;
    init();
    for(first(); loopCond(); _enor->next()){
        body(_enor->current());
    }
}
