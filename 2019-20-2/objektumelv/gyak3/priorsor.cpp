#include "priorsor.h"

int PrQueue::maxindex(){
    if(isEmpty()) throw EMPTY_PRQUEUE;
    int max = 0;
    for(int i = 1; i < _vec.size(); i++){
        if(_vec[i].pr > _vec[max].pr) max = i;
    }
    return max;
}

Item PrQueue::max(){
    return _vec[maxindex()];
}

void PrQueue::add(Item i){
    _vec.push_back(i);
}

Item PrQueue::remMax(){
    int mi = maxindex();
    Item i = _vec[mi];
    if( mi != _vec.size()-1)
    {
        _vec[mi] = _vec[_vec.size()-1];
    }
    _vec.pop_back();
}

bool PrQueue::isEmpty(){
 return _vec.size() == 0;
}
