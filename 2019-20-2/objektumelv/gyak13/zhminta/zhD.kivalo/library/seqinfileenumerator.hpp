//Author:   Gregorics Tibor
//Date:     2018.06.30.
//Task:     class of the enumerator of sequential input files

#pragma once

#include <fstream>
#include <typeinfo>
#include <sstream>

#include "enumerator.hpp"

//template class of the enumerator of sequential input files
//template parameters:  Item    - the type of the elements that are enumerated
//overrode methods:     first(), next(), current(), end()
//representation:       std::ifstream _f        - text file that contains the elements that must be enumerated
//                      Item          _df       - current element of the current row of the text file
//                      bool          _end      - true, if there are no more element in the text file
//                      std::stringstream _ss   - current row of the text file
template <typename Item>  // Item implements the operator>>()
class SeqInFileEnumerator : public Enumerator<Item>
{
    protected:
        std::ifstream _f;
        Item          _df;
        bool          _end;
        std::stringstream _ss;

        static std::ifstream create_ifstream(const std::string& str) {
            std::ifstream f(str);
            if(f.fail()) throw OPEN_ERROR;
            return f;
        }

        bool read_next_not_empty_line(){
            std::string line;
            _ss.clear();
            while( getline(_f, line) && line.size()==0 ) ;
            if(!(_f.fail())) _ss.str(line);
            return !_f.fail();
        }
    public:
        enum Exceptions { OPEN_ERROR };
        SeqInFileEnumerator(const std::string& str){
            _f = create_ifstream(str);
            _end = false;
        }
        void first() final override {
            _end = !read_next_not_empty_line();
            next();
        }
        void next() final override {
            _ss >> _df;
            if(_ss.fail()) {
                _end = !read_next_not_empty_line();
                _ss >> _df;
            }
        }
        bool end()     const final override { return _end;}
        Item current() const final override { return _df; }
};

//template specialization if the parameter is char
//switch off the skipping over white spaces
template<>
inline std::ifstream SeqInFileEnumerator<char>::create_ifstream(const std::string& str) {
    std::ifstream f(str);
    if(f.fail()) throw OPEN_ERROR;
    f.unsetf(std::ios::skipws);
    return f;
}
