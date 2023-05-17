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

#include "shop.h"
#include "item.h"

Shop :: Shop()
{

}

Shop :: Shop(string name, string id, int pin, string no, Item items[])
{
    shopName = name;
    shopId = id;
    shopPin = pin;
    shopNumb = no;

    for(int i=0; i<5; i++)
    {
        shopItems[i] = items[i];
    }
}

void Shop :: set_shopName(string name)
{
    shopName = name;
}

void Shop :: set_shopId(string id)
{
    shopId = id;
}

void Shop :: set_shopNumb(string numb)
{
    shopNumb = numb;
}

void Shop :: set_shopPin(int pin)
{
    shopPin = pin;
}

void Shop :: set_shopItems(Item items[])
{
    for(int i=0; i<5; i++)
    {
        shopItems[i] = items[i];
    }
}

string Shop :: get_shopName()
{
    return shopName;
}

string Shop :: get_shopId()
{
    return shopId;
}

string Shop :: get_shopNumb()
{
    return shopNumb;
}

void Shop :: write_shopTxt()
{
    char fileName[50];
    ofstream outFile;

    strcpy(fileName, shopName.c_str());
    strcat(fileName, ".txt");
    outFile.open(fileName);

    outFile << shopName << endl << shopId << endl << shopPin << endl << shopNumb;

    for(int i=0; i<5; i++)
    {
        outFile << endl << shopItems[i].get_itemName() << endl << shopItems[i].get_itemRate();
    }

    outFile.close();
}

void Shop :: disp_listOfItems()
{
    /*cout << "\t\t\tITEMS LIST:-" << endl;
    cout << "\t" << setw(40) << setfill(' ') << left << "\tITEM" << "\t" << "RATE";

    for(int i=0; i<5; i++)
    {
        cout << endl << i+1 << ". " << setw(40) << setfill(' ') << left << shopItems[i].get_itemName() << "\t" << shopItems[i].get_itemRate();
    }*/

    cout << "\t\t\tITEMS LIST" << endl;
    cout << "\n\t \tITEM\t\tRATE" << endl;
    for(int i=0;i<5;i++)
        cout << "\t" << i+1 << ". " << setw(15) << setfill(' ') <<shopItems[i].get_itemName() << "\t" << shopItems[i].get_itemRate() <<endl;

    char fileName[50];
    float rate[50];
    int i=0;
    ifstream inFile;
    string name[50];
    Shop shopObj;

    strcpy(fileName, shopName.c_str());
    strcat(fileName, ".txt");
    inFile.open(fileName);

    inFile >> shopObj.shopName >> shopObj.shopId >> shopObj.shopPin >> shopObj.shopNumb;
    while(!inFile.eof())
    {
       inFile >> name[i] >> rate[i];
       if(inFile.eof())
            break;
        i++;
    }

    inFile.close();

    cout << "\t\t\tITEMS LIST" << endl;
    cout << "\n\t \tITEM\t\tRATE" << endl;
    for(int i=0;i<50;i++)
        cout << "\t" << i+1 << ". " << setw(15) << setfill(' ') << name[i] << "\t" << rate[i] <<endl;
}

void Shop :: modify_details()
{
    char fileName[50];
    int op, newPin;
    ifstream inFile;
    ofstream outFile;
    string newShop;

    strcpy(fileName, shopName.c_str());
    strcat(fileName, ".txt");

    cout << "\n\n\t1.Change of shop name.";
    cout << "\n\n\t2.Change of password.";
    cout << "\n\tChoose your option: ";

    do
    {
        cin >> op;
        switch(op)
        {
            case 1: inFile.open(fileName, ios::in);
                    outFile.open("file.txt", ios::out);

                    cout << "\n\n\n\t\tEnter the new name of the shop:";
                    cin >> newShop;
                    set_shopName(newShop);

                    outFile << shopName << endl << shopId << endl << shopPin << endl << shopNumb;
                    for(int i=0; i<5; i++)
                    {
                        outFile << endl << shopItems[i].get_itemName() << endl << shopItems[i].get_itemRate();
                    };

                    inFile.close();
                    outFile.close();

                    remove(fileName);
                    rename("file.txt", fileName);

                    break;

        case 3:     inFile.open(fileName, ios::in);
                    outFile.open("file.txt", ios::out);

                    cout << "\n\n\t\tEnter the new password:";
                    cin >> newPin;
                    set_shopPin(newPin);

                    outFile << shopName << endl << shopId << endl << shopPin << endl << shopNumb;
                    for(int i=0; i<5; i++)
                    {
                        outFile << endl << shopItems[i].get_itemName() << endl << shopItems[i].get_itemRate();
                    };

                    inFile.close();
                    outFile.close();

                    remove(fileName);
                    rename("file.txt", fileName);

                    break;
        }
    }while((op!=1||op!=2 ||op!=3 ||op!=4 )&& cout<<"\n\n\t***Invalid entry***"<<"\n\n\tChoose your option again: ");
}

void Shop :: update_item()
{
    int op,j;
    Shop shopObj;
    char opt[4], res[20], fileName[50];
    float rate;
    ifstream fin;
    ofstream fout;
    string item;

    strcpy(fileName, shopName.c_str());
    strcat(fileName, ".txt");

    cout << "\n\t1.Remove an item.";
    cout << "\n\t2.Add new item.";
    cout << "\n\t3.Change in price.";
    cout << "\n\tchoose your option.";
    do{
    cin >> op;
    switch(op)
    {
        case 1:{
                int flag=0;
                fin.open(fileName,ios::in);
                fout.open("file.txt",ios::out);
                cout<<"\n\n\n\t\tEnter the item to be removed:";
                cin>>item;
                fout<<shopName<<endl<<shopId<<endl<<shopPin<<endl<<shopNumb;
                for(int i=0; i<5; i++)
                {
                    if(shopItems[i].get_itemName()!=item)
                        fout << endl << shopItems[i].get_itemName() << endl << shopItems[i].get_itemRate();
                }
                fin.close();
                fout.close();
                remove(fileName);
                rename("file.txt",fileName);
                break;
                }

        case 2: {
                fin.open(fileName,ios::in);
                fout.open("file.txt",ios::out);
                cout<<"\n\n\n\t\tEnter the item name to be added:";
                cin>>item;
                cout<<"\n\n\n\t\tEnter the item rate:";
                cin>>rate;
                fout<<shopName<<endl<<shopId<<endl<<shopPin<<endl<<shopNumb;
                for(int i=0; i<5; i++)
                {
                    fout << endl << shopItems[i].get_itemName() << endl << shopItems[i].get_itemRate();
                }
                fout << endl << item << endl << rate;
                fin.close();
                fout.close();
                remove(fileName);
                rename("file.txt",fileName);
                break;
                }
        case 3: {
                fin.open(fileName,ios::in);
                fout.open("file.txt",ios::out);
                cout<<"\n\n\n\t\tEnter the item name:";
                cin>>item;
                cout<<"\n\n\n\t\tEnter the new rate:";
                cin>>rate;
                fout<<shopName<<endl<<shopId<<endl<<shopPin<<endl<<shopNumb;
                for(int i=0; i<5; i++)
                {
                    if(shopItems[i].get_itemName()!=item)
                        fout << endl << shopItems[i].get_itemName() << endl << shopItems[i].get_itemRate();
                    else
                        fout << endl << item << endl << rate;
                }
                fin.close();
                fout.close();
                remove(fileName);
                rename("file.txt",fileName);
                break;
                }
        }
    cout<<"Do you want to Modify Another Detail? (yes/no) ";
    cin>>opt;
    }while(op>3||op<1||!strcmpi(opt,"yes"));
}
