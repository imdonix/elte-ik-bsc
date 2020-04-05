#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    Enor t("inp.txt");

    t.first();
    string name = t.current().name;
    int max = t.current().db;
    for(t.next(); !t.end(); t.next())
        if(t.current().db > max)
            name = t.current().name, max = t.current().db;

    cout << "A legtobb osszetevo ehez kell: " << name << endl;
    return 0;
}
