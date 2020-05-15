#include <iostream>
#include <chrono>

#include "system.h"
#include <thread>

using namespace std;

int main()
{
    System sys(5);
    cout << "Parking complete...\n";
    std::this_thread::sleep_for (std::chrono::seconds(1));
    cout << "Opening the 1st door...\n";
    sys.open(3);
    std::this_thread::sleep_for (std::chrono::seconds(1));
    cout << "Opening the 3rd door...\n";
    sys.open(3);
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Closing the 1st door... (3rd door is not closed well)\n";
    sys.close(1);
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Setting the alarm...\n";
    std::this_thread::sleep_for (std::chrono::seconds(1));
    sys.on();
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Son! You haven't closed the door well!\n";
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Closing the 3rd door...\n";
    sys.close(3);
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Setting the alarm... again...\n";
    std::this_thread::sleep_for (std::chrono::seconds(1));
    sys.on();
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Forgot the coat!\n";
    std::this_thread::sleep_for (std::chrono::seconds(1));
    cout << "Opening the 2nd door...\n";
    std::this_thread::sleep_for (std::chrono::seconds(1));
    sys.open(2);
    std::this_thread::sleep_for (std::chrono::seconds(4));
    cout << "\n\nSwitch off!\n";
    sys.off();
    std::this_thread::sleep_for (std::chrono::seconds(1));
    cout << "Getting the coat...\n";
    std::this_thread::sleep_for (std::chrono::seconds(1));
    cout << "(Meanwhile, the child opens the 3rd door and does not close it well.)\n";
    sys.open(3);
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Closing the 2nd door...\n";
    sys.close(2);
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Setting the alarm... again...\n";
    std::this_thread::sleep_for (std::chrono::seconds(1));
    sys.on();
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "I love my son :)\n";
    std::this_thread::sleep_for (std::chrono::seconds(1));
    cout << "Closing the 3rd door...\n";
    sys.close(3);
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Setting the alarm... AGAIN!\n";
    std::this_thread::sleep_for (std::chrono::seconds(1));
    sys.on();
    std::this_thread::sleep_for (std::chrono::seconds(3));
    cout << "--- MEOW! MEOW!---\n";
    std::this_thread::sleep_for (std::chrono::seconds(1));
    sys.move_inside();
    std::this_thread::sleep_for (std::chrono::seconds(3));
    cout << "\n\nSwitch off!\n";
    sys.off();
    std::this_thread::sleep_for (std::chrono::seconds(1));
    cout << "Oh Gooosh! Forgot the cat!!\n";
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Opening the 3rd door...\n";
    sys.open(3);
    std::this_thread::sleep_for (std::chrono::seconds(1));
    cout << "GETTING THE CAT.\n";
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Closing the 3rd door...\n";
    sys.close(3);
    std::this_thread::sleep_for (std::chrono::seconds(1));
    cout << "Setting the alarm... AGAIN!!!\n";
    std::this_thread::sleep_for (std::chrono::seconds(1));
    sys.on();
    std::this_thread::sleep_for (std::chrono::seconds(2));
    cout << "Finally!\n";
    return 0;
}
