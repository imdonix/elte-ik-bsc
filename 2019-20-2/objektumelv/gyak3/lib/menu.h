//Készítette:    Veszprémi Anna
//Dátum:         2018.02.20.
//Menürendszer header állomány

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "priorsor.h"

class Menu
{
    public:
        Menu(){};
        void Run();
    private:
        int MenuPrint();
        void Sorba();
        void Sorbol();
        void Legnagyobb();
        void Urese();
        void KiirSor();
        void TerhelesTeszt();
        PrQueue Q;

};

#endif // MENU_H_INCLUDED
