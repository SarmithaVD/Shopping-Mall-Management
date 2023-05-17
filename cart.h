#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Cart
{
    private:
        float subtotal, total;

        struct cart_items
        {
            string shop_name;
            string item_name;
            float amount;
            int quantity;
            static int i;
        }I[20];

    public:
        Cart();

        void disp_items();
        void add_item(string, string, float, int);
        void dlt_item(string);
        void confirm_order();

        friend class Bill;
};

#endif // CART_H_INCLUDED
