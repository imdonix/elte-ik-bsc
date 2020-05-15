#include "controller.h"
#include <iostream>
#include "engine.h"
#include "sensor.h"


Controller::Controller(Gate *g):_gate(g)
{
    _gate->_engine->switch_on();
    _gate->_sensor->switch_on();
}

Controller::~Controller()
{
    _gate->_engine->switch_off();
    _gate->_sensor->switch_off();
}

void Controller::control()
{
    int v = 0;
    menuWrite();
    do{
        std::cin >> v;  // ellenőrzés!
        switch(v){
            case 1: _gate->_engine->send(new Event(up));   std::cout << "up\n";   break;
            case 2: _gate->_engine->send(new Event(down)); std::cout << "down\n"; break;
            case 3: _gate->_engine->send(new Event(stop)); std::cout << "stop\n"; break;
        }
    }while(v != 0);
}

void Controller::menuWrite()
{
    std::cout << "Menupoints:\n";
    std::cout << "0 - exit\n";
    std::cout << "1 - up\n";
    std::cout << "2 - down\n";
    std::cout << "3 - stop\n";
}
