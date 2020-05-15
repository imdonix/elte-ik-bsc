#include <iostream>
#include "gate.h"
#include "controller.h"

using namespace std;

int main()
{
    Gate *g = new Gate(250);

    g->_controller->control();

    return 0;
}
