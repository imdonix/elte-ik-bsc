// Algo ZH1 
// Feladat: Két L1 lista metszete, az első listába képezve.
// Készítette: Magyar Tamás
// Dátum: 2020.04.09.
// Fordító: gcc 7.2.0 Target: x86_64-w64-mingw32

#include <stdlib.h>
#include "list.h"

//Alloc E1
E1* new(int key)
{
    E1* p = (E1*) malloc(sizeof(E1));
    p->key=key;
    p->next=NULL;
    return p;
}

//Dealloc E1
void delete(E1* p)
{
    free(p);
}

//List creator
E1* createHead()
{
    return new(0);
}

//Jegyzet alapján
void follow(E1* p, E1* q)
{
    q->next=p->next;
    p->next=q;
}

//Jegyzet alapján
E1* out_next(E1* p)
{
    E1* q = p->next;
    p->next=q->next;
    q->next=NULL;
    return q;
}

//Check is the lists are contain the same keys
int eqv(E1* L, E1* M)
{
    int temp = 0;
    E1* p = L->next;
    E1* q = M->next;
    for(; p!=NULL&&q!=NULL;p=p->next,q=q->next) // check items
        if(p->key!=q->key)
            temp++;
    temp+= p!=NULL||q!=NULL; // check length
    return !temp;
}

//Task
void interselect(E1* L, E1* M)
{
    E1* p=L;
    E1* q=M;
    while(p->next!=NULL&&q->next!=NULL)
        if(p->next->key==q->next->key)
            delete(out_next(q)), p=p->next;
        else if(p->next->key>q->next->key)
            delete(out_next(q));
        else
            delete(out_next(p));
    while(p->next!=NULL) delete(out_next(p));
    while(q->next!=NULL) delete(out_next(q));
}