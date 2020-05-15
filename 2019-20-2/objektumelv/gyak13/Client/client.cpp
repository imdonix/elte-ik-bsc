#include "client.h"
#include "server.h"

void Client::stateMachine() {
    while(true) {
        otherjob();
        std::unique_lock<std::mutex> lock(_sys->_mu);
        while (_sys->_server->getUsed()) {
            std::cout << _id << ". waiting\n";
//            sys->_cond.notify_one();
            _sys->_cond.wait(lock);
            std::cout << _id << ". restarts\n";
        }
        _sys->_server->use_ent();
        lock.unlock();
        use();
        _sys->_server->use_ex();
        _sys->_cond.notify_one();
    }
}

/*
void Client::stateMachine() {
    while(true) {
        otherjob();
        std::unique_lock<std::mutex> lock(sys->_mu);
        if (sys->server.getUsed()) {
            sys->_cond.wait(lock);
        }
        sys->server.use_ent();
        lock.unlock();
        use();
        sys->server.use_ex();
        sys->_cond.notify_one();
    }
}
*/
void Client::otherjob() {
        std::ostringstream ss1;
        ss1 << _id << ". client starts otherjob.\n";
        std::cout << ss1.str();

        std::this_thread::sleep_for (std::chrono::seconds(3*_id+2));

        std::ostringstream ss2;
        ss2 << _id << ". client finished otherjob.\n";
        std::cout << ss2.str();
}

void Client::use() {
        std::ostringstream ss1;
        ss1 << _id << ". client starts to use the server. * * * * *\n";
        std::cout << ss1.str();

        std::cout << _id << ". using\n";
        std::this_thread::sleep_for (std::chrono::seconds(_id));

        std::ostringstream ss2;
        ss2 << _id << ". client finished using the server.\n";
        std::cout << ss2.str();
}
