// Név:         Magyar Tamás
// Neptun:      RNYR2F
// Feladat:     OEP beadandó 3
// Fordító:     gcc version 7.2.0 | windows 64


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "owner.hpp"
#include "pets.hpp"

using namespace std;


enum PlayExeption {BadFile, BadAnimalType, BadStateType};


OwnerState parseState(char c);
Animal* parseAnimal(string line);
void round(OwnerState state, Owner* owner);
void play(string src);


bool play(string src, vector<Animal*>& saddestAnimals )
{
    Owner* owner = Owner::instance();
    ifstream f(src);
    string line;
    if(f.fail()) throw BadFile;

    int n; f >> n; getline(f,line); // clear ednline

    //Összegzés
    getline(f,line);
    for(int i=0; i<n ; i++, getline(f,line))
        owner->addPet(parseAnimal(line));

    //Összegzés
    getline(f,line);
    for(string::iterator it=line.begin(); it!=line.end(); ++it)
        round(parseState(*it), owner);

    bool succes = false;
    int min;
    if(owner->FindSaddestAnimalHP(min))
    {
        owner->CollectAnimalWithHP(min,saddestAnimals);
        succes = true;
    }

    owner->clear();
    return succes;
}

void round(OwnerState state, Owner* owner)
{
    if(state < 2 && owner->isAllPetGood())
        state = (OwnerState)((int)state + 1);
    owner->dealPets(state);
    cout << owner << "---" << endl; 
}

OwnerState parseState(char c)
{
    switch(c) 
    {
        case 'r': return Sad;      break;
        case 'a': return Avarage;  break;
        case 'j':  return Happy;    break;
     }
     throw BadStateType;
}

Animal* parseAnimal(string line)
{
    char type; string name; int hp;
    stringstream ss(line); ss >> type >> name >> hp;

    switch(type) 
    {
        case 'H': return new Fish(name, hp); break;
        case 'M': return new Bird(name, hp); break;
        case 'K': return new Dog(name, hp);  break;
     }

     throw BadAnimalType;
}

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    try
    {
        vector<Animal*> saddestAnimals;
        if(play("inp.txt", saddestAnimals))
        {
            cout << "A legszomorubb allatai Pistinek: " << endl;
            for(Animal* animal : saddestAnimals)
                cout << animal;
        }
        else
            cout << "Nem maradt eletben vagy nem is volt kedvenc" << endl;

    }
    catch(PlayExeption)
    {
        cout << "Hibas adatot adtal meg";
    }

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("no animals", "test1.txt")
{
    vector<Animal*> saddestAnimals;
    CHECK(!play("test1.txt", saddestAnimals));
}

TEST_CASE("no state", "test2.txt")
{
    vector<Animal*> saddestAnimals;
    CHECK(!play("test2.txt", saddestAnimals));
}

TEST_CASE("one animal fish", "test3.txt")
{
    vector<Animal*> saddestAnimals;
    CHECK(play("test3.txt", saddestAnimals));
    CHECK(saddestAnimals[0]->getType() == "Hal");
    CHECK(saddestAnimals[0]->getName() == "Aranyhalacska");
}   

TEST_CASE("one animal bird", "test4.txt")
{
    vector<Animal*> saddestAnimals;
    CHECK(play("test4.txt", saddestAnimals));
    CHECK(saddestAnimals[0]->getType() == "Madar");
    CHECK(saddestAnimals[0]->getName() == "UndokPapagaly");
}   

TEST_CASE("one animal dog", "test5.txt")
{
    vector<Animal*> saddestAnimals;
    CHECK(play("test5.txt", saddestAnimals));
    CHECK(saddestAnimals[0]->getType() == "Kutya");
    CHECK(saddestAnimals[0]->getName() == "Buksi");
}

TEST_CASE("one dead animal", "test6.txt")
{
    vector<Animal*> saddestAnimals;
    CHECK(!play("test6.txt", saddestAnimals));
}   

TEST_CASE("multiple bad", "test7.txt")
{
    vector<Animal*> saddestAnimals;
    CHECK(play("test7.txt", saddestAnimals));
    CHECK(saddestAnimals[0]->getType() == "Hal");
    CHECK(saddestAnimals[0]->getName() == "Aranyhalacska1");
    CHECK(saddestAnimals[1]->getType() == "Hal");
    CHECK(saddestAnimals[1]->getName() == "Aranyhalacska2");
    CHECK(saddestAnimals[2]->getType() == "Hal");
    CHECK(saddestAnimals[2]->getName() == "Aranyhalacska3");
}   

#endif
