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

//Task
void interselect(E1* L, E1* M)
{
    
    for(E1* p=L;p->next!=NULL;)
    {
        char c=0;
        for(E1* q=M->next;q!=NULL&&!c; q=q->next)
            if(p->next->key == q->key) c++;

        if(!c)
            delete(out_next(p));
        else
            p=p->next;
    }
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