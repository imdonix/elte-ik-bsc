#include <iostream>
#include <vector>
#include "benzinkut.hpp"
#include "penztar.hpp"

using namespace std;

int main() {
    const int toltoDb = 6;
    const int penztarDb = 2;

    Benzinkut *_telephely = new Benzinkut(toltoDb,penztarDb);
    _telephely->setEgysegar(280);

    delete _telephely;
    return 0;
}
