#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <bits/stdc++.h>

#include "cart.h"
#include "item.h"
#include "bill.h"

COORD coord = {0,0};
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Cart :: cart_items :: i = -1;

Cart :: Cart()
{
    subtotal = 0.0;
    total = 0.0;

    for(int j=0; j<20; j++)
    {
        I[j].shop_name="NULL";
        I[j].item_name="NULL";
        I[j].amount=0.0;
        I[j].quantity=0;
    }
}

void Cart :: add_item(string sName,string iName, float price, int quan)
{
    cart_items :: i=cart_items :: i+1;
    I[cart_items::i].shop_name = sName;
    I[cart_items::i].item_name = iName;
    I[cart_items::i].amount = price;
    I[cart_items::i].quantity = quan;
    subtotal = price * (float)quan + subtotal;
}

void Cart::dlt_item(string iName)
{
    int j;
    for(j=0; j<cart_items::i; j++)
    {
        if(iName == I[j].item_name)
            break;
    }
    subtotal=subtotal-(I[j].amount*(float)I[j].quantity);

    I[j].shop_name = I[cart_items::i].shop_name;
    I[j].item_name = I[cart_items::i].item_name;
    I[j].amount = I[cart_items::i].amount;
    I[j].quantity = I[cart_items::i].quantity;

    cart_items::i = cart_items::i-1;
}

void Cart :: confirm_order()
{
    total = 1.15 * subtotal;
    Bill b;
    b.gen_bill(this);
}

void Cart :: disp_items()
{
    int k=5;

    gotoxy(75,2);
    cout<<"CART";
    gotoxy(55,4);
    cout<<"SHOP\tITEM\tQUANTITY\tPRICE(per item)";

    if(cart_items::i != -1)
    {
        for(int j=0; j<=cart_items::i; j++,k++)
        {
            gotoxy(55, k);
            cout << I[j].shop_name << "\t" << I[j].item_name << "\t" << I[j].quantity << "\t\t" << std::fixed << std::setprecision(2) << std::setfill('0') << I[j].amount;
        }
    }
    gotoxy(85, k+1);
    cout<<"SUBTOTAL: "<<subtotal;
}
