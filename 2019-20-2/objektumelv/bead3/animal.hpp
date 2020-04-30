#pragma once

enum OwnerState{ Sad, Avarage, Happy };

class Animal
{
    private:
        std::string _name;
        int _hp;
    protected:
        Animal(std::string name, int hp) : _name(name), _hp(hp) {}
        void modHP(int mod) { _hp+=mod; }
    public:
        std::string getName() const { return _name; }
        int getHP() const { return _hp; }
        bool isAlive() const { return _hp > 0; }

        virtual void deal(OwnerState state){}
        virtual std::string getType() const{}
        
        friend std::ostream& operator<< (std::ostream& s, const Animal* a)
        {
            return s << a->getType() << " | " << a->getName() << " | " << a->getHP() << std::endl; 
        }
};