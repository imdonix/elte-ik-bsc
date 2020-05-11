//Author:   Gregorics Tibor
//Date:     2017.08.31.
//Title:    General maximum search

#pragma once

#include "procedure.hpp"

//template class including "greatert" relation
//Method: operátor()
//template parameter: Value - type of the values that must be compared
template <typename Value> // Value implements the operator>()
class Greater{
    public:
        bool operator()(const Value& l, const Value& r){
            return l > r;
        }
};

//template class including "less" relation
//Method: operátor()
//template parameter: Value - type of the values that must be compared
template <typename Value> // Value implements the operator>()
class Less{
    public:
        bool operator()(const Value& l, const Value& r){
            return l < r;
        }
};

//template class of general maximum search
//template parameters:  Item    - the type of the elements that are enumerated
//                      Value   - the type of the values of the elements that are enumerated
//                      Compare - it may be Greater or Less
//overrode methods:     init(), body()
//new methods:          found(), opt(), optElem()   -   give back the results of maximum search
//new virtual methods:  func() - computes the value of an Item type element
//                      cond() - defines a condition on an Item type element
//representation:       bool _l       - logical variable of the conditional maximum search
//                      Item _optelem - the best Item type element that is found for a given moment
//                      Value _opt    - the Value type value of the best Item type element that is found for a given moment
//                      Compare _better - object that compares values, its type may be Greater or Less
template <typename Item, typename Value, typename Compare >
class MaxSearch : public Procedure<Item, Value, Compare>
{
protected:
    bool    _l;
    Item    _optelem;
    Value   _opt;
    Compare _better;

    void init() final override { _l = false;}
    void body(const Item& e) final override;

    virtual Value func(const Item& e) const = 0;
    virtual bool  cond(const Item& e) const { return true;}

public:
    bool found()   const { return _l;}
    Value opt()    const { return _opt;}
    Item optElem() const { return _optelem;}
};

// body of the loop of the general maximum search
template <class Item, class Value, class Compare>
void MaxSearch<Item,Value,Compare>::body(const Item& e)
{
    Value val = func(e);
    if ( !cond(e) ) return;
    if (_l){
        if (_better(val,_opt)){
            _opt = val;
            _optelem = e;
        }
    }
    else {
        _l = true;
        _opt = val;
        _optelem = e;
    }
}

