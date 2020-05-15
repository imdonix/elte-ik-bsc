#ifndef ENGINE_H
#define ENGINE_H
#include <thread>
#include <atomic>

#include "threadsafequeue.h"
#include "event.h"
#include "gate.h"

class Engine
{
    public:
        Engine(Gate* g);
        ~Engine();
        enum State {stopped, upward, downward};
        std::string getState() const ;

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
        void processEvent(Event *event);
};

#endif // ENGINE_H
