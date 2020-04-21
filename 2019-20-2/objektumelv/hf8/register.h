#pragma once
#include "car.h"

class Register
{
    private:
        Station* _station;
    public:
        enum RegisterExeptions{NotEnoughMoney};

        Register(Station* stat){ _station = stat;}
        void pay(Car* car, int slotind);
};