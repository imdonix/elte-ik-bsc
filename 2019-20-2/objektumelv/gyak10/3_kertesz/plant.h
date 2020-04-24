#pragma once

/**********************************************/

class Plant
{
    protected:
        int _ripeningTime;
        Plant(int i) : _ripeningTime(i) {}
    public:
        getRipeningTime() const { return _ripeningTime; }
        virtual ~Plant() {}
};

/***********************************************/

class Vegetable : public Plant
{
    protected:
        Vegetable(int i) : Plant(i) {}
};

class Flower : public Plant
{
    protected:
        Flower(int i) : Plant(i) {}
};

/************************************************/

class Potatoe : public Vegetable
{
    public:
        Potatoe() : Vegetable(5) {}
};

class Pea : public Vegetable
{
    public:
        Pea() : Vegetable(3) {}
};

class Onion : public Vegetable
{
    public:
        Onion() : Vegetable(4) {}
};

class Rose : public Flower
{
    public:
        Rose() : Flower(8) {}
};

class Carnation : public Flower
{
    public:
        Carnation() : Flower(10) {}
};

class Tulip : public Flower
{
    public:
        Tulip() : Flower(7) {}
};
