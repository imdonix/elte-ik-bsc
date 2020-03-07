#include <iostream>
#include "vector2d.h"

using namespace std;

int main()
{
    Vector2D v1(1,0);
    Vector2D v2(1,0);
    Vector2D v3(1,1);
    cout << v1 << endl;
    v1.add(v2);
    cout << v1 << endl;
    v1.multiple(4);
    cout << v1 << endl;
    cout << v1 << " es " << v3 << " ";
    if(v1.isMeroleges(v3))
        cout << "meroleges";
    else
        cout << "nem meroleges"; 
}