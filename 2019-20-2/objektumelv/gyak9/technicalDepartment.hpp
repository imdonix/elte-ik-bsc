#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "item.hpp"
using namespace std;

class TechnicalDepartment{
    private: 
    public:
        vector<Item*> _items;
        TechnicalDepartment(string fn){
            ifstream f(fn.c_str());
            Item i("", 0);
            while(f >> i) {
                _items.push_back(new Item(i));
            }
        }
        ~TechnicalDepartment(){
            for( Item *i : _items){
                delete i;
            }
        }
        Item *getItem(string name){
            Item *r = nullptr;
            for( Item *i : _items){
                if(i->name == name){
                    if(r == nullptr || r->price > i->price){
                        r = i;
                    }
                }
            }
            return r;
        }
};