#include "system.h"
#include "door.h"
#include "alarm.h"
#include "sensor.h"

System::System(unsigned int n)
{
    doors.clear();
    for (unsigned int i = 0; i < n; i++)
        doors.push_back(new Door(this));
    alarm = new Alarm(this);
    sensor = new Sensor(this);
    alarm->off();
}

System::~System()
{
    for (unsigned int i = 0; i < doors.size(); i++)
        delete doors[i];
    doors.clear();
    delete sensor;
    delete alarm;
}

bool System::openDoors() const
{
    for (Door* d : doors)
        if (d->getOpen())
            return true;
    return false;
}

void System::on()
{
    if (alarm->on()) std::cout << "\n<<< Alarm is set.>>>\n\n";
    else std::cout << "\n<<< Could not set the alarm.>>>\n\n";
}

void System::off()
{
    alarm->off();
}

void System::open(unsigned int i)
{
    if (i<doors.size())
        doors[i]->open();
}

void System::close(unsigned int i)
{
    if (i < doors.size())
        doors[i]->close();
}

void System::move_inside()
{
    sensor->sense();
}
