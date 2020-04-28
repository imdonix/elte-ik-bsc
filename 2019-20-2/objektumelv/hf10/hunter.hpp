#pragma once
#include <vector>
#include "trophy.hpp"

class Hunter
{
    private:
        std::string _name;
        int _age;
        std::vector<Trophy*> trophies;
    public:
        Hunter(std::string name, int age) : _name(name), _age(age) {}
        ~Hunter(){ for(Trophy* t : trophies) delete t; }

        std::string getName(){ return _name; }
        int getAge(){ return _age; }
        void addTrophy(Trophy* t) { trophies.push_back(t);} 

        int countMaleLions()
        {
            int c = 0;
            for(Trophy* trop : trophies)
                if(trop->getType() == "Lion" && trop->getSpecial() == "Male")
                        c++;
            return c;
        }
};