#ifndef SHOP_H_INCLUDED
#define SHOP_H_INCLUDED

#include <iostream>
#include <string>
#include "item.h"

using namespace std;

class Shop
{
    private:
            int shopPin;
            string shopName, shopId, shopNumb;
            Item shopItems[5];

            void set_shopName(string);
            void set_shopId(string);
            void set_shopNumb(string);
            void set_shopPin(int);
            void set_shopItems(Item[]);
            string get_shopName();
            string get_shopId();
            string get_shopNumb();

    public:
        Shop();
        Shop(string, string, int, string, Item[]);

        void write_shopTxt();
        void update_item();
        void disp_listOfItems();
        void modify_details();

        friend class User;
        friend class Admin;
};

#endif // SHOP_H_INCLUDED
