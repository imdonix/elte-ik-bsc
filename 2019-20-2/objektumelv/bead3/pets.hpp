#pragma once
#include "animal.hpp"

class Fish : public Animal
{
    public:
        Fish(std::string name, int hp) : Animal(name, hp){}
        void deal(OwnerState state)
        {
            switch(state) 
            {
                case Sad:       modHP(-5); break;
                case Avarage:   modHP(-3); break;
                case Happy:     modHP(1); break;
            }
        }
        std::string getType() const { return "Hal"; }
};

class Bird : public Animal
{
    public:
        Bird(std::string name, int hp) : Animal(name, hp){}
        void deal(OwnerState state)
        {
            switch(state) 
            {
                case Sad:       modHP(-3); break;
                case Avarage:   modHP(-1); break;
                case Happy:     modHP(2); break;
            }
        }
        std::string getType() const { return "Madar"; }
};

class Dog : public Animal
{
    public:
        Dog(std::string name, int hp) : Animal(name, hp){}
        void deal(OwnerState state)
        {
            switch(state) 
            {
                case Sad:       modHP(-10); break;
                case Avarage:   modHP(3); break;
                case Happy:     modHP(3); break;
            }
        }
        std::string getType() const { return "Kutya"; }
};