#ifndef SENSOR_H
#define SENSOR_H

#include <thread>
#include "system.h"

class Sensor
{
    public:
        Sensor(System *sys);
        ~Sensor();
        void on();
        void off();
        void sense();

    private:
        bool _active;
        std::thread _thread;
        bool _sense;
        System* _sys;

        void stateMachine();
};

#endif // SENSOR_H
