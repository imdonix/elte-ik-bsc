#ifndef SYSTEM_H
#define SYSTEM_H

#include <mutex>
#include <condition_variable>
#include <vector>

enum Signal { OPEN , SENSE , CLOSE };

class Door;
class Alarm;
class Sensor;

class System
{
    public:
        System(unsigned int n);
        ~System();

        std::vector<Door*> doors;
        Alarm* alarm;
        Sensor* sensor;

        std::mutex mu;
        std::condition_variable _cond;

        bool openDoors() const;
        void on();
        void off();
        void open (unsigned int i);
        void close (unsigned int i);
        void move_inside();

    private:
};

#endif // SYSTEM_H
