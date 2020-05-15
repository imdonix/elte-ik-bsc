#pragma once

#include <atomic>
#include <iostream>
#include <sstream>

class Labor
{
    public:
        Labor(int c): _cap(c), _user(0), _work(0), _requiring(0){}
        ~Labor(){}

        int getUser() const { return _user; }
        int getWork() const { return _work; }
        int getReq()  const { return _requiring; }
        int getCapacity() const { return _cap; }

        void enterUser() { ++_user; }
        void exitUser()  { --_user; }
        void startWork() { --_requiring; ++_work; }
        void finishWork(){ --_work; }
        void wantWork()  { ++_requiring; }

        void report(int id){
            std::ostringstream ss;
            ss  << id << " :: users in: " << getUser()
                << " ; crew requesting: " << getReq()
                << " ; crew in: " << getWork() << std::endl;
            std::cout << ss.str();
        }

    private:
        int _cap;
        std::atomic_int _user;
        std::atomic_int _work;
        std::atomic_int _requiring;
};
