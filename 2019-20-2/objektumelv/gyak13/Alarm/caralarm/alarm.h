#ifndef ALARM_H
#define ALARM_H

//#include "system.h"
#include <iostream>
#include <thread>
#include "sensor.h"
#include <iostream>

class Alarm
{
    public:
        Alarm(System *sys): _sys(sys) { }
        ~Alarm() { try { _thread.join(); } catch (std::exception e){ } delete _sys; }
        void send(Signal s)
        {
            if (_active && (s==OPEN || s==SENSE)) alarm();
        }
        bool on()
        {
            if ( _sys->openDoors() ) return false;
            _active = true;
            _sys->sensor->on();
            return true;
        }
        void off() { _active = false; _sys->sensor->off(); try { _thread.join(); }  catch (std::exception e){}}

    private:
        bool _active;
        System *_sys;
        std::thread _thread;

        void scream() { while (_active) { std::cout << "BEEP!!! "; std::this_thread::sleep_for(std::chrono::milliseconds(500)); } }
        void alarm() { _thread = std::thread(&Alarm::scream, this); }
};

#endif // ALARM_H
