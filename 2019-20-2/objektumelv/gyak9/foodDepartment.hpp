#pragma once
#include <iostream>
#include <vector>
#include "item.hpp"
using namespace std;

class FoodDepartment{
    private: 
    public:
        vector<Item*> _items;
        FoodDepartment(string fn){
            ifstream f(fn.c_str());
            Item i("", 0);
            while(f >> i) {
                _items.push_back(new Item(i));
            }
        }
        
        ~FoodDepartment(){
            for( Item *i : _items){
                delete i;
            }
        }

        Item *getItem(string name){
            for( Item *i : _items){
                if(i->name == name){
                    return i;
                }
            }
            return nullptr;
        }


};