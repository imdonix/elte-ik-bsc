#pragma once

#include <vector>
#include <mutex>
#include <condition_variable>
#include <thread>

#include "labor.h"

class Crew;
class Student;

class System
{
    public:
        System(int n, int m, int c);
        ~System();

        Labor lab;
        std::vector<Crew*> crews;
        std::vector<Student*> students;

        std::mutex _mu;
        std::condition_variable _cond;

    private:
};

