#include <iostream>

#include "enor.h"

using namespace std;

int main()
{
    Enor t("inp.txt");

    for( t.first(); !t.end(); t.next() ){
        cout << t.current().n << " " << t.current().db << endl;
    }

    return 0;
}
