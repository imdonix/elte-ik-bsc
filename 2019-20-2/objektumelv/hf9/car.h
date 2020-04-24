#pragma once
#include "station.hpp"
#include <iostream>

class Station;

class Car
{
    private:
        int _tank;
        int _balance;
    public:
        Car(int balance, int tank) : _balance(balance), _tank(tank) {}
        int get_balance() {return _balance;}
        int get_tank() {return _tank;}
        void fill(int amount) {_tank+=amount;}
        void detract(int amount) { _balance-=amount; }

        void fillup(Station* station, int slotind, int regind, int amount);
};

