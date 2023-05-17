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

#include "item.h"

using namespace std;

Item :: Item()
{

}

Item& Item :: operator =(const Item& item)
{
    if(this != &item)
    {
        itemName = item.itemName;
        itemRate = item.itemRate;
    }

    return *this;
}

void Item :: read_values(string name, float rate)
{
    itemName = name;
    itemRate = rate;
}

float Item :: get_itemRate()
{
    return itemRate;
}

string Item :: get_itemName()
{
    return itemName;
}
