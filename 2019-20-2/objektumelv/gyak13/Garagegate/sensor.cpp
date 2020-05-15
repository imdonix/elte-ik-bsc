#include "sensor.h"
#include "engine.h"
#include <random>
#include <ctime>
#include <mutex>
#include <condition_variable>
#include <chrono>

Sensor::Sensor(Gate *g):_gate(g),_life(Sensor::stateMachine, this), _working()
{
    srand(time(NULL));
    _currentState = passive;
}

Sensor::~Sensor()
{
    _life.join();
}

void Sensor::stateMachine()
{

    while(_working)
    {
        Event* event = nullptr;
        _eventQueue.dequeue(event); //kiveszünk egy eseményt a sorból

        if(event != nullptr)
        {
            processEvent(event);
        }
        if (_currentState == active) touch();

    // ez a rész itt az animáció miatt kell
        std::condition_variable _cond;
		std::mutex mu;
		std::unique_lock<std::mutex> lock(mu);
		_cond.wait_for(lock, std::chrono::milliseconds(1000));
    }
}

void Sensor::touch()
{
    int d = rand()%100;
    if(d<10){
        _gate->_engine->send(new Event(blockage));
    }
}

void Sensor::processEvent(Event *event)
{
	switch (event->ev) {
        case standing:_currentState = passive; break;
        case moving:  _currentState = active;  break;
        default: ; //hiba
	}
}

std::string Sensor::getState() const
{
    switch (_currentState) {
        case active: return "active"; break;
        case passive:  return "passive"; break;
    }
    return "";
}
