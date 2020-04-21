void Register::pay(Car* car, int slotind)
{
    int to_pay = _station->get_slot(slotind)->get_display * _station->get_price();
    if(car->get_balance() >= to_pay)
          car->detract(to_pay);
    else
         throw NotEnoughMoney;
}