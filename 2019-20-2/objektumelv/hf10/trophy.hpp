#pragma once

class Trophy
{
    protected:
        std::string _place;
        std::string _time;
        int _weight;
        Trophy(std::string place, std::string time, int weight) 
        : _place(place), _time(time), _weight(weight) {}
    public:
        std::string getPlace(){ return _place; }
        std::string getTime(){ return _time; }
        int getWeight(){ return _weight; }

        virtual std::string getType(){};
        virtual std::string getSpecial(){};
};