#ifndef DOOR_H
#define DOOR_H

#include "system.h"
#include "alarm.h"

class Door
{
    public:
        Door(System *sys): _sys(sys) { }
        ~Door() { delete _sys; }
        void open()
        {
            _open = true;
            std::unique_lock<std::mutex> lock(_sys->mu);
            _sys->alarm->send(OPEN);
            lock.unlock();
        }
        void close() { _open = false; }
        bool getOpen() const{ return _open; }

    private:
        bool _open;
        System *_sys;
};

#endif // DOOR_H
