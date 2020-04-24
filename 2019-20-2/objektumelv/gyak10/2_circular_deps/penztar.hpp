#pragma once

#include <vector>
#include "benzinkut.hpp"

class Benzinkut;

class Penztar {
    private:
    public:
        Benzinkut *telephely;

        int fizet(int sorszam) {
            int liter = telephely->getTolto(sorszam)->getKijelzo();
            telephely->getTolto(sorszam)->lenullaz();
            return liter * telephely->getEgysegar();
        }
};