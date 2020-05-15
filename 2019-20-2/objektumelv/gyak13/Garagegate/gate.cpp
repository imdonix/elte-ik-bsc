#include "gate.h"
#include "engine.h"
#include "sensor.h"
#include "controller.h"

Gate::Gate(int m):_max_length(m), _cur_length(0)
{
    _engine = new Engine(this);
    _sensor = new Sensor(this);
    _controller = new Controller(this);
}

Gate::~Gate()
{
    delete _engine;
    delete _sensor;
    delete _controller;
}

void Gate::up()
{
    if(_cur_length==0) _engine->send(new Event(coiled));
    else --_cur_length;
}

void Gate::down()
{
    if(_cur_length==_max_length) _engine->send(new Event(unrolled));
    else ++_cur_length;
}
