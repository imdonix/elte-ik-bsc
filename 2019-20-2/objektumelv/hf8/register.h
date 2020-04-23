#pragma once

class Car;
class Station;

class Register
{
    private:
        Station* _station;
    public:
        enum RegisterExeptions{NotEnoughMoney};
        
        Register(Station* stat);
        void pay(Car* car, int slotind);
};