// Magyar Tanás
// RNYR2F
// 8. Házi feladat
// g++ | gcc version 7.2.0

#include <iostream>
#include <vector>
#include "station.hpp"
#include "car.h"

using namespace std;

int main()
{
    Station* station = new Station(50);
    Car* car = new Car(2000, 20);

    cout << "Az autosnak " << car->get_tank() << "l uzemanyaga van es " << car->get_balance() << " penze" << endl;

    try
    {
        car->fillup(station, 1, 2, 20);
        cout << "Az autosnak " << car->get_tank() << "l uzemanyaga van es " << car->get_balance() << " penze" << endl;
    }
    catch(Station::StationExeption){ cout << "Az autosnak nem kasszat vagy toltot talalnia"; }
    catch(Register::RegisterExeptions) { cout << "Az autosnak nem volt eleg penze"; }

    delete station;
    delete car;
}   