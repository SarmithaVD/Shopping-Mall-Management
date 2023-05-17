#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Item
{
    private:
        float itemRate;
        string itemName;

        friend class Shop;
        friend class Admin;
        friend class User;

    public:
        Item();
        Item(const Item[]);

        Item& operator =(const Item&);

        void read_values(string, float);

        float get_itemRate();
        string get_itemName();
};

#endif // ITEM_H_INCLUDED
