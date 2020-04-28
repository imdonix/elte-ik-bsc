// Név:         Magyar Tamás
// Neptun:      RNYR2F
// Cím:         9. Házi feladat
// Fordító:     g++ | gcc version 7.2.0

#include <iostream>
#include "hunter.hpp"
#include "specialTrophy.hpp"

using namespace std;

int main()
{
    Hunter* hunter = new Hunter("Zoli", 45);

    hunter->addTrophy(new ElephantTrophy("Észak-Afrika", "1999.01.01", 1200, 50, 45));
    hunter->addTrophy(new ElephantTrophy("Dél-Afrika", "1999.01.02", 1210, 50, 60));
    hunter->addTrophy(new RhinoTrophy("Dél-Afrika", "1999.01.03", 800, 70));
    hunter->addTrophy(new RhinoTrophy("Dél-Afrika", "1999.02.03", 700, 60));
    hunter->addTrophy(new LionTrophy("Közép-Afrika", "1999.04.03", 300, true));
    hunter->addTrophy(new LionTrophy("Dél-Afrika", "1999.04.04", 300, true));
    hunter->addTrophy(new LionTrophy("Közép-Afrika", "2003.04.03", 311, false));
    hunter->addTrophy(new LionTrophy("Dél-Afrika", "2003.04.02", 320, true));
    
    cout <<  hunter->getName() << " " << hunter->countMaleLions() << " him oroszlan trofeaval rendelkezik" << endl;

    delete hunter;

    return 0;
}