#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    Enor t("inp.txt");
    bool mindLott = true;
    for( t.first(); !t.end() && mindLott; t.next() ){
        mindLott = t.current();
    }
    if(mindLott)
        cout << "Minden vadasz lott medvet." << endl;
    else
        cout << "NEM minden vadasz lott medvet." << endl;
    return 0;
}
