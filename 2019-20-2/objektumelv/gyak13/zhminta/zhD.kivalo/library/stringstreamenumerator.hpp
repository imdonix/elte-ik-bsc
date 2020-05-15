//Author:   Gregorics Tibor
//Date:     2017.08.31.
//Title:    enumerating the element of a stringstream

#pragma once

#include <typeinfo>
#include <sstream>

#include "enumerator.hpp"

//template class of the enumerator of strimgstreams
//template parameters:  Item    - the type of the elements that are enumerated
//overrode methods:     first(), next(), current(), end()
//representation:       std::stringstream _ss   - stringstream that contains the elements that must be enumerated
//                      Item          _df       - current element of the current row of the text file
template <typename Item>  // Item implementálja az operator>>-t
class StringStreamEnumerator : public Enumerator<Item>
{
    protected:
        std::stringstream _ss;
        Item              _df;

    public:
        StringStreamEnumerator(std::stringstream& ss) {
            _ss << ss.rdbuf();
        }

        void first()         override { next();}
        void next()          override { _ss >> _df; }
        bool end()     const override { return !_ss;}
        Item current() const override { return _df; }
};

