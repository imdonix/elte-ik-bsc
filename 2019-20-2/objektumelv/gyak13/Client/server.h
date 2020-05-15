#pragma once

#include <atomic>

class Server
{
public:
	Server() { _used = false; }

    int getUsed() const { return _used; }

    void use_ent() { _used = true; }
    void use_ex()  { _used = false; }

private:
    std::atomic_bool _used;
};

