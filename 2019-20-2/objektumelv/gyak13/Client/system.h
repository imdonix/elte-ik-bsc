#pragma once

#include <mutex>
#include <vector>
#include <condition_variable>
#include <atomic>

class Client;
class Server;

class System
{
public:
    System(int n);
    ~System();

    void schedule();

    Server *_server;
    std::vector<Client*> _clients;

    std::mutex _mu;
    std::condition_variable _cond;
};

