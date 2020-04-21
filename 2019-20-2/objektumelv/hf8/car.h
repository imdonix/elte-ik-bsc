#pragma once
#include "station.hpp"

class Car
{
    private:
        int balance;
    public:
        Car(int bal){ balance = bal;}
        int get_balance() {return balance;};
        void detract(int amount);
        void fillup(Station* station, int slotind, int regind, int amount);
};