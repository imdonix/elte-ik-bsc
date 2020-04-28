#pragma once
#include "trophy.hpp"

class ElephantTrophy : public Trophy
{
    private:
        int _leftTusk;
        int _rightTusk;
    public:
        ElephantTrophy(std::string place, std::string time, int weight, int left, int right) :
        Trophy(place,time,weight), _leftTusk(left), _rightTusk(right) {}

        std::string getType() { return "Elephant"; }
        std::string getSpecial() { return _leftTusk + "is the left tusk and the right" + _rightTusk; }
};

class RhinoTrophy : public Trophy
{
    private:
        int _tusk;
    public:
        RhinoTrophy(std::string place, std::string time, int weight, int tusk) :
        Trophy(place,time,weight), _tusk(tusk) {}

        std::string getType() { return "Rhino"; }
        std::string getSpecial() { return _tusk + "is the tusk length"; }
};

class LionTrophy : public Trophy
{
    private:
        bool _isMale;
    public:
        LionTrophy(std::string place, std::string time, int weight, bool isMale) :
        Trophy(place,time,weight), _isMale(isMale) {}

        std::string getType() { return "Lion"; }
        std::string getSpecial() { return _isMale ? "Male" : "Female"; }
};