#include <iostream>
#include "enor_2.h"

using namespace std;

int main()
{
    Enor t("inp.txt");
    for( t.first(); !t.end() && t.current().suly < 400; t.next() ){
        cout << t.current().nev << " " << t.current().suly << endl;
    }
    if(t.end())
        cout << "nem volt ilyen vadasz" << endl;
    else
        cout << "400nal tobbet lovo vadasz: " << t.current().nev << endl;
    return 0;
}
