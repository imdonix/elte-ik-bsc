#include "sensor.h"
#include "alarm.h"

Sensor::Sensor(System *sys): _sys(sys) { }
Sensor::~Sensor()
{
    try
    {
        _thread.join();
    }
    catch (std::exception e) { }
    delete _sys;
}
void Sensor::on()
{
    _active = true;
    _thread = std::thread(&Sensor::stateMachine, this);
}
void Sensor::off()
{
    _active = false;
    try
    {
        _thread.join();
    }
    catch (std::exception e) {}
}
void Sensor::sense()
{
    _sense = true;
}

void Sensor::stateMachine()
{
    while (_active)
    {
        if (_sense)
        {
            std::unique_lock<std::mutex> lock(_sys->mu);
            _sys->alarm->send(SENSE);
            //std::cout << "NO SENSE\n";
            _sense = false;
            lock.unlock();
            //std::cout << "UNLOCK\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
