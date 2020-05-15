#include "engine.h"
#include "sensor.h"

#include <sstream>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <chrono>

Engine::Engine(Gate *g):_gate(g),_life(Engine::stateMachine, this), _working()
{
    _currentState = stopped;
}

Engine::~Engine()
{
    _life.join();
}

void Engine::stateMachine()
{

    while(_working)
    {
        Event* event = nullptr;
        _eventQueue.dequeue(event);
        if(event != nullptr)
        {
            processEvent(event);
        }
        switch (_currentState) {
            case stopped:  break;
            case upward:   _gate->up();   break;
            case downward: _gate->down(); break;
		}

    // ez a rész itt az animáció miatt kell
		std::condition_variable _cond;
		std::mutex mu;
		std::unique_lock<std::mutex> lock(mu);
		_cond.wait_for(lock, std::chrono::milliseconds(1000));

		std::ostringstream ss;
		ss << getState() << " length: " << _gate->getLength() << " sensor: " << _gate->_sensor->getState() << std::endl;
		std::cout << ss.str();
    }
}

void Engine::processEvent(Event *event)
{
	switch (event->ev) {
        case up:
            switch (_currentState) {
                case stopped: _gate->_sensor->send(new Event(moving)); _currentState = upward; break;
                case upward:  break;
                case downward: _currentState = upward; break;
            }
            break;
        case down:
            switch (_currentState) {
                case stopped: _gate->_sensor->send(new Event(moving)); _currentState = downward; break;
                case upward:  _currentState = downward; break;
                case downward:  break;
            }
            break;
        case stop: case blockage:
            switch (_currentState) {
                case upward: case downward: _gate->_sensor->send(new Event(Signal::standing)); _currentState = stopped; break;
                case stopped:  break;
            }
            break;
        case coiled:
            switch (_currentState) {
                case upward: _gate->_sensor->send(new Event(Signal::standing)); _currentState = stopped; break;
                case downward: case stopped:  break;
            }
            break;
        case unrolled:
            switch (_currentState) {
                case downward: _gate->_sensor->send(new Event(Signal::standing)); _currentState = stopped; break;
                case upward: case stopped:  break;
            }
            break;
        default: ; //hiba
    }
}

std::string Engine::getState() const
{
    switch (_currentState) {
        case stopped: return "standing"; break;
        case upward:  return "moving up"; break;
        case downward:return "moving down"; break;
    }
    return "";
}
