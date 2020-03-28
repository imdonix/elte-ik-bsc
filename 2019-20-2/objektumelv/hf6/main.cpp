// 6. kisbeadandó
// Magyar Tamás
// 2020-03-28

#include <iostream>

#include "enor.h"

using namespace std;

int f(Order o);

int main()
{
    Enor t("inp1.txt");

    //Maximum keresés

    t.first();
    Order elem = t.current();
    int max = f(t.current());
    for(t.next();!t.end();t.next())
        if(f(t.current()) > max)
            max = f(t.current()), elem = t.current();

    cout << "A legtobbet bevetelt hozo rendeles: " << elem << " osszesen ennyibe kerult: " << max;
    return 0;
}

int f(Order o){ return o.db*o.price; }
