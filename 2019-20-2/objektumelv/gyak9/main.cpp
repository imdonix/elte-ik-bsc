#include <iostream>
#include <vector>
#include "item.hpp"
#include "shop.hpp"
#include "customer.hpp"

using namespace std;

int main(){
    Shop *shop = new Shop("food.txt", "technical.txt");
    Customer *c = new Customer("shoplist.txt");
    c->shopAt(shop);

    vector<Item> basket;
    c->collectBasket(basket);

    int sum = 0;

    cout << "Kosar tartalma: " << endl;
    for(Item i : basket){
        cout << i << endl;
        sum += i.price;
    }
    cout << endl;
    cout << "fizetendo: " << sum << endl;
    cout << endl;

    vector<ListItem> notfound;
    c->collectNotFound(notfound);
    cout << "meg nem talalt tetelek: " << endl;
    for(ListItem i : notfound){
        cout << i.name << endl;
    }
    cout << endl;

    delete shop;
    delete c;

}