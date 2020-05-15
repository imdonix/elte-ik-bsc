#ifndef SENSOR_H
#define SENSOR_H

#include <thread>
#include <atomic>

#include "threadsafequeue.h"
#include "event.h"
#include "gate.h"

class Sensor
{
    public:
        Sensor(Gate *g);
        ~Sensor();
        enum State {active, passive};
        std::string getState() const;

        void send(Event* event) { _eventQueue.enqueue(event); }
        void switch_on()  { _working = true; }
        void switch_off() { _working = false; }

    private:
        Gate   *_gate;
        State _currentState;
        std::thread _life;
        ThreadSafeQueue<Event*> _eventQueue;
        std::atomic_bool _working;

        void stateMachine();
        void touch();
        void processEvent(Event *event);
};

#endif // SENSOR_H
