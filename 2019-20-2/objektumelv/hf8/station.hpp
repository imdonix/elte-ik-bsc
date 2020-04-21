#pragma once
#include <vector>
#include "slot.hpp"
#include "register.h"

using namespace std;

class Station
{
    private:
        const int SLOT_SIZE = 6;
        const int REG_SIZE = 2;
        int price;
        vector<Slot*> slots;
        vector<Register*> registers;
    public:
        enum StationExeption
        {
            SlotNotFound,
            RegisterNotFound
        };

        Station(int price)
        {
            this->price = price;
            for(int i=0;i<SLOT_SIZE;i++) slots.push_back(new Slot());
            for(int i=0;i<REG_SIZE;i++) registers.push_back(new Register());
        }

        ~Station()
        {            
            for(int i=0;i<SLOT_SIZE;i++) delete slots[i];
            for(int i=0;i<REG_SIZE;i++) delete registers[i];
        }

        int get_price(){ return price; }

        Slot* get_slot(int ind)
        {
            if(ind <= SLOT_SIZE)
                return slots[ind-1];
            else
                throw SlotNotFound;
        }

        Register* get_register(int ind)
        {
            if(ind <= REG_SIZE)
                return registers[ind-1];
            else
                throw RegisterNotFound;
        }
};

