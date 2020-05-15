#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <sstream>

#include "system.h"

class Crew
{
    public:
        Crew(int i, System *s ) : id(i),life(&Crew::stateMachine, this),sys(s){}
        ~Crew(){ life.join();}

    private:
        int id;
        std::thread life;
        System *sys;

        void stateMachine()
        {
            while(true){
                rest();
                sys->lab.wantWork();

                std::unique_lock<std::mutex> lock(sys->_mu);
                while (!(sys->lab.getUser()==0 && sys->lab.getWork()==0) )
                {
                    sys->_cond.notify_one();
                    sys->_cond.wait(lock);
                }
                sys->lab.startWork();
                lock.unlock();
                maintain();
                sys->lab.finishWork();
                sys->_cond.notify_one();
            }
        }

        void rest(){
            std::ostringstream ss1;
            ss1 << id << ". crew is starting rest.\n";
            std::cout << ss1.str();

            std::this_thread::sleep_for (std::chrono::seconds(id+10));

            std::ostringstream ss2;
            ss2 << id << ". crew has finished resting.\n";
            std::cout << ss2.str();
        }

        void maintain(){
            std::ostringstream ss1;
            ss1 << id << ". crew is entering.\n";
            std::cout << ss1.str();

            std::this_thread::sleep_for (std::chrono::seconds(id+3));

            std::ostringstream ss2;
            ss2 << id << ". crew is exiting.\n";
            std::cout << ss2.str();
        }

};
