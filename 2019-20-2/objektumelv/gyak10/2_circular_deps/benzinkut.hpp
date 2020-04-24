#pragma once

#include <vector>
#include <iostream>
#include "toltohely.hpp"
#include "penztar.hpp"
using namespace std;


class Benzinkut {
    private:
        vector<Penztar*> _penztarak;
        vector<Toltohely*> _toltok;
        int _egysegar;
    public:
        Benzinkut(int tdb, int pdb) {
            for(int i=0; i<tdb; ++i) 
                _toltok.push_back(new Toltohely() );
            for(int i=0; i<pdb; ++i) 
                _penztarak.push_back(new Penztar());
        }
        ~Benzinkut() {
            for(Toltohely *p : _toltok) 
                delete p;
            for(Penztar *p : _penztarak) 
                delete p;
        }

        Penztar *getPenztar(int sorszam)  {
            return _penztarak[sorszam];
        }
        Toltohely *getTolto(int sorszam)  {
            return _toltok[sorszam];
        }

        int getEgysegar() const {
            return _egysegar;
        }
        void setEgysegar(int ar) {
            _egysegar = ar;
        }
};