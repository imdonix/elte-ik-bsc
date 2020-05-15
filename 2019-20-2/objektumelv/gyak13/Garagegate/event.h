#ifndef EVENT_H
#define EVENT_H

enum Signal { blockage, up, down, stop, coiled, unrolled, moving, standing };

//az esemény nem tartalmazhat most adattagokat, csak ha létrehozunk egy leszármazott osztályt belőle
struct Event
{
	Event(Signal e) : ev(e) {}
	Signal ev;
};

#endif // EVENT_H
