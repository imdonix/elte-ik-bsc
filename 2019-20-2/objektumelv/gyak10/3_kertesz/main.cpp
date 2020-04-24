#include <iostream>
#include "gardener.h"
#include "plant.h"

using namespace std;

int main()
{
    Garden* garden = new Garden(5);
    Gardener* gardener = new Gardener(garden);

    gardener->getGarden()->plant(1, new Potatoe(), 3);
    gardener->getGarden()->plant(2, new Pea(), 3);
    gardener->getGarden()->plant(4, new Pea(), 3);


    cout << "A betakarithato parcellak azonositoi: ";
    for( int i : gardener->_garden->canHarvest(6)){
        cout << i << " ";
    }
    cout << endl;

    delete garden;
    delete gardener;

    return 0;
}
