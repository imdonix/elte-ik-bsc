#pragma once
#include <iostream>
#include "technicalDepartment.hpp"
#include "foodDepartment.hpp"
using namespace std;

class Shop{
    private:
    public:
        TechnicalDepartment *_t;
        FoodDepartment *_f;
        Shop(string s1, string s2){
            _f = new FoodDepartment(s1);
            _t = new TechnicalDepartment(s2);
        }

        ~Shop(){
            if(_t != nullptr) delete _t;
            if(_f != nullptr) delete _f; 
        }

        Item *getFood(string name){
            return _f->getItem(name);
        }
        Item *getTechnical(string name){
            return _t->getItem(name);
        }

};