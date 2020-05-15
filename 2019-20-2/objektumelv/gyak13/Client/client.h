#pragma once

#include "system.h"
#include <thread>
#include <sstream>
#include <iostream>

class Client {
public:
    Client(int i, System *s ): _id(i), _life(&Client::stateMachine, this), _sys(s) {}
    ~ Client() { _life.join(); }
private:
    int _id;
    std::thread _life;
    System *_sys;
    void stateMachine();
    void otherjob() ;
    void use() ;
};
