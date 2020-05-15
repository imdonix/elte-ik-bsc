#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>

class Student
{
    public:
       Student(int i, System *s ) : id(i),life(&Student::stateMachine, this),sys(s){}
        ~Student(){ life.join();}

    private:
        int id;
        std::thread life;
        System *sys;

        void stateMachine()
        {
            while(true){
                off();

                std::unique_lock<std::mutex> lock(sys->_mu);
                while (!(sys->lab.getUser()<sys->lab.getCapacity() && sys->lab.getWork()==0 && sys->lab.getReq()==0) )
                {
                    sys->_cond.notify_one();
                    sys->_cond.wait(lock);
                }
                sys->lab.enterUser();
                lock.unlock();
                use();
                sys->lab.exitUser();sys->_cond.notify_one();
            }
        }

        void off(){
            std::ostringstream ss1;
            ss1 << id << ". student is off.\n";
            std::cout << ss1.str();

            std::this_thread::sleep_for (std::chrono::seconds(id+3));

            std::ostringstream ss2;
            ss2 << id << ". student has returned.\n";
            std::cout << ss2.str();
        }

        void use(){
            std::ostringstream ss1;
            ss1 << id << ". student is entering.\n";
            std::cout << ss1.str();

            std::this_thread::sleep_for (std::chrono::seconds(id+2));

            std::ostringstream ss2;
            ss2 << id << ". student is exiting.\n";
            std::cout << ss2.str();
        }

};
