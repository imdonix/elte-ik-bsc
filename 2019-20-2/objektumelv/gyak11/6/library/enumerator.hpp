//Készítette:    Gregorics Tibor
//Dátum:         2017.08.31.
//Feladat:       Felsorolók ősosztálya

#pragma once

//Felsorolók őssztály-sablonja
//Műveletek: first(), next(), end(), current()
//Sablon paraméterek: Item - a felsorolt elemek típusa
template <typename Item>
class Enumerator
{
    public:
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool end() const = 0;
        virtual Item current() const = 0;
        virtual ~Enumerator(){}
};
