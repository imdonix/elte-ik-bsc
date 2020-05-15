#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gate.h"

class Controller
{
    public:
        Controller(Gate *g);
        ~Controller();

        void control();

    private:
        Gate   *_gate;

        void menuWrite();
};

#endif // CONTROLLER_H
