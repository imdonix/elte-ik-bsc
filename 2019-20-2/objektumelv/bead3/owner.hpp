#pragma once
#include <vector>
#include "Animal.hpp"

const int ANIMAL_GOOD = 5;

class Owner
{
    private:
        std::string _name;
        std::vector<Animal*> _pets;
        Owner() : _pets() {}
    public:
        static Owner* _instance;
        ~Owner(){ for(Animal* animal : _pets ) delete animal; }
        void addPet(Animal* animal) { _pets.push_back(animal); }

        void clear()
        {
            _pets.clear();
        }

        static Owner* instance()
        {
            if(_instance == nullptr)
                _instance = new Owner();
            return _instance;
        }

        //Összegzés
        void dealPets(OwnerState state) 
        {
            for(Animal* animal : _pets )
                if(animal->isAlive())
                    animal->deal(state);
        }

        //Összegzés | Eldöntés
        bool isAllPetGood()
        {
            bool s = true;
            for(Animal* animal : _pets )
                s = s && (animal->getHP() > ANIMAL_GOOD);
            return s;
        }

        //Feltételes maximumkeresés
        bool FindSaddestAnimalHP(int& min)
        {
            bool l = false;
            for(Animal* animal : _pets)
                if(animal->isAlive())
                    if(!l)
                        l = true, min = animal->getHP();
                    else
                        if(min > animal->getHP())
                            min = animal->getHP();
            return l;
        }
        
        //Összegzés | Kiválogatás
        void CollectAnimalWithHP(int hp, std::vector<Animal*>& dest)
        {
            for(Animal* animal : _pets)
                if(animal->getHP() == hp)
                    dest.push_back(animal);
        }

        friend std::ostream& operator<< (std::ostream& s, const Owner* a)
        {
            for(Animal* animal : a->_pets )
                s << animal;
            return s;
        }
};


Owner* Owner::_instance = nullptr;