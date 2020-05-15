#include "server.h"
#include "client.h"

System::System(int n) {
    _server = new Server;
    for(int i = 0; i<n; ++i) {
        _clients.push_back(new Client(i+1, this));
    }
}

System::~System() {
    for(unsigned int i = 0; i<_clients.size(); ++i) {
        delete _clients[i];
    }
    delete _server;
}
