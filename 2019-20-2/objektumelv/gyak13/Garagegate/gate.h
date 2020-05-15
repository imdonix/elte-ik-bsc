#ifndef GATE_H
#define GATE_H

class Engine;
class Sensor;
class Controller;

class Gate
{
    public:
        Gate(int m);
        ~Gate();

        Engine *_engine;
        Sensor *_sensor;
        Controller *_controller;

        void up();
        void down();
        int getLength() const { return _cur_length; }

    private:
        int _max_length;
        int _cur_length;
};

#endif // GATE_H
