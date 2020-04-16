#include <iostream>
#include <vector>
#include <fstream>
#include "item.hpp"

class ListItem{
    public: 
        string name;
        bool found;
        ListItem(string n, bool f): name(n), found(f){}
};

class Customer{

    private:
        vector<ListItem*> _list;
        vector<Item*> _basket;
    public: 
        Customer(string fn){
            ifstream f(fn.c_str());
            string n;
            while(f >> n) {
                _list.push_back(new ListItem(n, false));
            }
        }

        ~Customer(){
            for( ListItem *i : _list){
                delete i;
            }
        }

        void shopAt(Shop *shop){
            for(ListItem *i : _list){
                Item *j = shop->getFood(i->name);
                if(j != nullptr){
                    i->found = true;
                    _basket.push_back(j);
                }
            }
            for(ListItem *i : _list){
                Item *j = shop->getTechnical(i->name);
                if(!(i->found) && j != nullptr){
                    i->found = true;
                    _basket.push_back(j);
                }
            }
        }

        void collectNotFound(vector<ListItem> &nf){
            for(ListItem *i : _list){
                if(!i->found){
                    nf.push_back(ListItem(*i));
                }
            }
        }

        void collectBasket(vector<Item> &nf){
            for(Item *i : _basket){
                nf.push_back(Item(*i));
            }
        }


};