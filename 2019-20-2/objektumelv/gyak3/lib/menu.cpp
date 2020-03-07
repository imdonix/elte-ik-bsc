//Készítette:    Veszprémi Anna
//Dátum:         2019.02.19.
//Menürendszer forráskód
//Feladat:       A menüpontok a prioritásos sor típus műveleteit meghívják, majd
//               a művelet lefutása után mindig kiírják a sor jellemzőit.
//               Terhelés teszttel vizsgálható a memória kapacitás.

#include <iostream>
#include "menu.h"
#include "read.hpp"
#include <sstream>
#define menudb 6 //egyedul itt kell javitani, ha a menüt bővítjük

using namespace std;

//Ellenőrzéshez 0..menudb kozotti menüpontokat lehet választani
bool check(int a){return a>=0 && a<=menudb;}

void Menu::Run()
{
    int v;
    do{
        v=MenuPrint();
        switch(v)
        {
            case 1:
                Sorba();
                KiirSor();
                break;
            case 2:
                Sorbol();
                KiirSor();
                break;
            case 3:
                Legnagyobb();
                KiirSor();
                break;
            case 4:
                Urese();
                KiirSor();
                break;
            case 5:
                KiirSor();
                break;
            case 6:
                TerhelesTeszt();
                break;
            default:
                cout<<"\nViszontlatasra!\n";
                break;

        }
    }while(v!=0);
}

int Menu::MenuPrint()
{
    int valasz;
    cout<<"\n****************************************\n";
    cout<<"0. Kilepes\n";
    cout<<"1. Prior sorba berak\n";
    cout<<"2. Legnagyobbat kivesz\n";
    cout<<"3. Legnagyobbat lekerdez\n";
    cout<<"4. Ures-e vizsgalat\n";
    cout<<"5. Sort kiir\n";
    cout<<"6. Terheles teszt (mennyi elemet tudunk a sorba tenni)\n";
    cout<<"****************************************\n";
    //hiba üzenet rugalmas előállítása
    ostringstream s;
    s<<"0 es "<<menudb<<" kozotti egesz szam legyen!";
    string errmsg=s.str();
    //beolvasás read.hpp segítségével
    valasz=read<int>("Valasztas:",errmsg,check);

    return valasz;
}

void Menu::Sorba()
{
    Item e;
    cout<<"Mit tegyunk be?\n";
    cin >> e;
    Q.add(e);
}

void Menu::Sorbol()
{
    Item e;
    bool hiba=false;
    try{
        e=Q.remMax();
    }catch(PrQueue::PrQueueError err)
    {
        hiba=true;
        if(err==PrQueue::EMPTY_PRQUEUE)
            cerr<<"A kiveves nem sikerult! A pr.sor ures!\n";
        else
            cerr<<"Programhiba, forduljon a program keszitojehez :-))\n";
    }
    if(!hiba) cout<<"Kivett elem:\n"<<e<<endl;
}

void Menu::Legnagyobb()
{
    Item e;
    bool hiba=false;
    try{
        e=Q.max();
    }catch(PrQueue::PrQueueError err)
    {
        hiba=true;
        if(err==PrQueue::EMPTY_PRQUEUE)
            cerr<<"A vizsgalat nem sikerult! A pr.sor ures!\n";
        else
            cerr<<"Programhiba, forduljon a program keszitojehez :-))\n";
    }
    if (!hiba) cout<<"Legnagyobb elem:\n"<<e<<endl;
}

void Menu::Urese()
{
    if(Q.isEmpty())
        cout<<"A pr.sor ures.\n";
    else
        cout<<"A pr.sor nem ures.\n";
}

void Menu::KiirSor()
{
    cout<<Q;
}



void Menu::TerhelesTeszt()
{
    const int meret=1000000000;
    PrQueue Q;
    cout<<"A sor pillanatnyi elemszamat kovetheti:\n";
    try{
        for(int i=1; i<meret; ++i)
        {
            if(i%1000000==0) cout<<i<<endl;
            Q.add(Item(i,"a"));
        }
    }catch(...)
    {
        cerr<<"Elfogyott a szabad memoria!\n";
        cerr<<"A vector merete: "<<Q.getCapacity()<<endl;
    }
}


