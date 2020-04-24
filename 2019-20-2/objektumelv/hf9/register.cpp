#include "register.h"
#include "car.h"

void Register::pay(Car* car, int slotind)
{
    Slot* slot = _station->get_slot(slotind);
    int filled = slot->get_display();
    int to_pay = filled * _station->get_price();
    if(car->get_balance() >= to_pay)
    {
          car->detract(to_pay);
          car->fill(filled);
          slot->clear();
    }
    else
         throw NotEnoughMoney;
}

Register::Register(Station* stat){ _station = stat;}