// 6. kisbeadandó
// Magyar Tamás
// 2020-04-03
// v2

#include <iostream>

#include "enor.h"

using namespace std;

int f(Order o);

int main()
{
    Enor t("inp1.txt");

    //Maximum keresés

    t.first();
    string elem = t.current().name;
    int max = t.current().income;
    for(t.next();!t.end();t.next())
        if(t.current().income > max)
            max = t.current().income, elem = t.current().name;

    cout << "A legtobbet bevetelt hozo eltel: " << elem << " osszesen ennyi hozamot termelt: " << max;
    return 0;
}