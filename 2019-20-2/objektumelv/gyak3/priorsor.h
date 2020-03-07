#ifndef PRIORSOR_H_INCLUDED
#define PRIORSOR_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Item{
public:
    string val;
    int pr;
    Item(){}
    Item(string v, int p = 0)  {val = v; pr = p; }

    friend ostream& operator<< (ostream &s, const Item &i){
        s << "Pr: " << i.pr << ", Val: " << i.val;
        return s;
    }

    friend istream& operator>> (istream &s, Item &i){
        s >> i.pr >> i.val;
        return s;
    }

};

class PrQueue{
private:
    vector<Item> _vec;
    int maxindex();
public:
    enum PrQueueError {EMPTY_PRQUEUE};

    Item max();
    Item remMax();
    bool isEmpty();
    void add(Item);
};


#endif // PRIORSOR_H_INCLUDED
