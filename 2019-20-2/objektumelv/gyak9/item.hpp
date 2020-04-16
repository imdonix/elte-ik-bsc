#pragma once
#include <iostream>
using namespace std;

class Item{
    public:
        string name;
        int price;
        Item(string n, int p): name(n),price(p) {}
        friend istream& operator>> (istream& s, Item& i ){
            return s >> i.name >> i.price;
        }
        friend ostream& operator<< (ostream& s, const Item& i ){
            return s << i.name << " " << i.price;
        }
};