#pragma once
#include "parcel.h"
#include <vector>

class Garden
{
    protected:
        std::vector<Parcel*> _parcels;
    public:
        Garden(int n);  // parcellak száma
        Parcel* getParcel(int i) const; // parcella lekerdezese
        void plant(int id, Plant* plant, int date); // ültetes parcellaba
        std::vector<int> canHarvest(int date); // learathato parcella azonositok lekerdezese
};
