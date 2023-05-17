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
#include "bill.h"

using namespace std;

Bill :: Bill()
{

}

void Bill :: gen_bill(Cart *cartObj)
{
    system("cls");

    cout << "SHOP\tITEM\tQUANTITY\tPRICE(per item)\n";

    if(cartObj->I->i!=-1)
    {
        for(int j=0; j<=cartObj->I->i ;j++)
        {
            cout << "\n" << cartObj->I[j].shop_name << "\t" << cartObj->I[j].item_name << "\t" << cartObj->I[j].quantity << "\t" << cartObj->I[j].amount;
        }
    }
    cout << "\n\n\tSUBTOTAL: " << cartObj->subtotal;
    cout << "\n\tTOTAL: " << cartObj->total;
    //getch();
    cout << "\nTHANK YOU !! MUST VISIT US AGAIN :)"<<endl;
}
