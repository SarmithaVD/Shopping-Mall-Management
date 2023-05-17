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

#include "admin.h"
#include "user.h"
#include "shop.h"

using namespace std;

Admin :: Admin()
{
    nShop = 12;
}

void Admin :: write_shops()
{
    ofstream outFile("shops.txt");

    outFile << "RmKV" << endl;
    outFile << "H&M" << endl;
    outFile << "Trends" << endl;
    outFile << "Max" << endl;
    outFile << "Haribhavanam" << endl;
    outFile << "KFC" << endl;
    outFile << "Keventers" << endl;
    outFile << "Dominos" << endl;
    outFile << "Apple" << endl;
    outFile << "OnePlus" << endl;
    outFile << "HP" << endl;
    outFile << "Dell";

    outFile.close();
}

User Admin :: create_user()
{
    int flag, flag_1=1, flag_2=1;
    ifstream inFile;
    ofstream outFile;
    string name, pwd, num;
    User userObj, dummyObj;

    do{
        inFile.open("user.txt");
        flag = 0;
        cout << "\nEnter an username: ";
        cin >> name;
        while(!inFile.eof())
        {
            inFile >> dummyObj.userName >> dummyObj.userPwd >> dummyObj.userPhNum;
            if(inFile.eof())
                break;
            if(dummyObj.get_userName() == name)
            {
                cout << "***The Chosen User-Id is already Taken. Try another.***" << endl;
                flag = 1;
                break;
            }
        }
        inFile.close();
    }while(flag);

    userObj.set_userName(name);
    outFile.open("user.txt", ios::out|ios::app);

    cout << "Enter a six character password: ";
    cin >> pwd;
    while(flag_1)
    {
        try
        {
            if(pwd.length()!=6)
                throw pwd;
            flag_1=0;
        }
        catch(string p)
        {
            cout<<"***Invalid Password***\nEnter a valid six character password : ";
            cin>>pwd;
        }
    }
    userObj.set_userPwd(pwd);

    cout << "Enter your Mobile Number: ";
    cin >> num;
    while(flag_2)
    {
        try
        {
            if(num.length()>10 || num.length()<10)
                throw num;
            flag_2=0;
        }
        catch(string p)
        {
            cout<<"***Invalid Phone Number***\nEnter a valid Phone Number : ";
            cin>>num;
        }
    }
    userObj.set_userPhNum(num);

    outFile << userObj.userName << "\t" << userObj.userPwd << "\t" << userObj.userPhNum << "\n";
    outFile.close();

    cout<<"\n>>> Account created successfully!";

    return userObj;
}

bool Admin :: check_user(string u, string p, User &user)
{
    int cnt=0;
    ifstream inFile;
    User userObj;

    inFile.open("user.txt", ios::in);

    while(!inFile.eof())
    {
        cnt = 0;
        inFile >> userObj.userName >> userObj.userPwd >> userObj.userPhNum;
        while(userObj.userName == u)
        {
            if(userObj.userPwd == p)
            {
                user.set_userName(userObj.userName);
                user.set_userPwd(userObj.userPwd);
                user.set_userPhNum(userObj.userPhNum);
                inFile.close();

                return true;
            }
            else
            {
                cnt++;
                if(cnt>3)
                {
                    cout<<"\n***Password wrong for three times!!!***";

                    exit(0);
                }
                cout << "***Wrong Password!***\n Re-enter : ";
                cin >> p;
            }
        }
    }
    inFile.close();
    return false;
}

void Admin :: dlt_user()
{
    ifstream inFile;
    ofstream outFile;
    string name;
    User userObj;

    cout << "Enter the user-id of the user to be deleted: ";
    cin >> name;

    inFile.open("user.txt");
    outFile.open("newUser.txt");

    while(!inFile.eof())
    {
        inFile >> userObj.userName >> userObj.userPwd >> userObj.userPhNum;
        if(userObj.userName!=name)
        {
            outFile << userObj.userName << "\t" << userObj.userPwd << "\t" << userObj.userPhNum << "\n";
        }
    }

    inFile.close();
    outFile.close();

    remove("user.txt");
    rename("newUser.txt", "user.txt");

    cout << ">>> User Deleted Successfully" << endl;
}

Shop Admin :: add_shop()
{
    char fileName[50], lr;
    float rate;
    int n = nShop+1, i;
    ofstream outFile;
    string name, Name, item_name, numb;
    stringstream ss, strs;
    Shop s;

    nShop++;

    cout << "\nEnter the Shop name: ";
    cin >> name;
    s.set_shopName(name);

    cout << setfill('0') << setw(5);
    s.shopPin = rand()%99999;

    cout << "\nPIN Number: " << s.shopPin;

    ss << n;
    ss >> Name;
    name = name + "@" + Name + Name;
    s.set_shopId(name);
    cout << "\nShop Id: " << s.get_shopId();

    if(n%3==0)
    {
        lr = n/3 + 64;
        numb = lr;
        numb = numb + "03";
    }
    else
    {
        lr = n/3 + 65;
        numb = lr;
        if(n%3==1)
            numb = numb + "01";
        else
            numb = numb + "02";
    }
    s.set_shopNumb(numb);
    cout << "\nShop Number: " << s.get_shopNumb();

    cout << "\n\nEnter the Shop items:-\n";

    Item newShop[5];
    for(i=0; i<5; i++)
    {
        cout << "\nEnter the item name and item rate respectively:\n";
        cin >> item_name >> rate;
        newShop[i].read_values(item_name, rate);
    }
    s.set_shopItems(newShop);

    strcpy(fileName, (s.get_shopName()).c_str());
    strcat(fileName, ".txt");
    outFile.open(fileName, ios::out|ios::app);

    outFile << s.shopName <<endl << s.shopId << endl << s.shopPin << endl << s.shopNumb;
    for(int i=0; i<5; i++)
    {
        outFile << endl << s.shopItems[i].get_itemName() << endl << s.shopItems[i].get_itemRate();
    }

    outFile.close();

    outFile.open("shops.txt", ios::out|ios::app);
    outFile << endl << s.get_shopName();
    outFile.close();

    cout << "\n>>> Shop Added Successfully" << endl;

    return s;
}

bool Admin :: check_shop(string u, int p, Shop &s)
{
    char fileName[50];
    int flag=0, cnt=0;
    ifstream inFile;
    string name;
    Shop S;

    inFile.open("shops.txt");
    while(!inFile.eof())
    {
        inFile >> name;
        if(u==name)
        {
            flag = 1;
            break;
        }
    }
    if(!flag)
        return false;
    inFile.close();

    strcpy(fileName, name.c_str());
    strcat(fileName, ".txt");
    inFile.open(fileName, ios::in);

    inFile >> S.shopName >> S.shopId >> S.shopPin >> S.shopNumb;

    while(1)
    {
        if(S.shopPin==p)
        {
            inFile.close();
            return true;
        }
        else
        {
            cnt++;
            if(cnt>3)
            {
                cout<<"\n***Password wrong for three times!!!***";
                inFile.close();
                return false;
            }
            cout<<"***Wrong Password! Re-enter!***";
            cin>>p;
        }
    }
}

void Admin :: dlt_shop()
{
    char fileName[50];
    ifstream inFile;
    ofstream outFile;
    string id, name, Name;
    Shop shopObj;

    cout << "Enter the name of the shop to be deleted: ";
    cin >> name;

    strcpy(fileName, name.c_str());
    strcat(fileName, ".txt");
    remove(fileName);

    inFile.open("shops.txt");
    outFile.open("updated_shops.txt");

    while(!inFile.eof())
    {
        inFile >> Name;
        if(Name!=name)
        {
            outFile << Name << endl;
        }
    }

    inFile.close();
    outFile.close();

    remove("shops.txt");
    rename("updated_shops.txt", "shops.txt");

    cout << "\n>>> Shop Deleted Successfully" << endl;
    nShop--;
}
