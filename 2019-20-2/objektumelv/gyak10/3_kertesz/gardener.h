#pragma once
#include "garden.h"

class Gardener
{
    private:
        Garden* _garden;
    public:
        Gardener(Garden* k) :  _garden(k) {}
        Garden *getGarden();
};
