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

#include "user.h"
#include "shop.h"
#include "cart.h"
#include "item.h"

using namespace std;

void Delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while(goal>clock());
}

COORD coord2 = {0, 0};
void GotoXY(int x, int y)
{
    coord2.X = x;
    coord2.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord2);
}

User :: User()
{
    userName = "NULL";
    userPwd = "NULL";
}

string User :: get_userName()
{
    return userName;
}

string User :: get_userPwd()
{
    return userName;
}

string User :: get_userPhNum()
{
    return userName;
}

void User :: set_userName(string name)
{
    userName = name;
}

void User :: set_userPwd(string pwd)
{
    userPwd = pwd;
}

void User :: set_userPhNum(string ph)
{
    userPhNum = ph;
}

void User :: modify_account()
{
    int opt, flag=1, flag_1=1;
    ifstream inFile;
    ofstream outFile;
    User userObj;

    inFile.open("user.txt");
    outFile.open("updatedUser.txt");

    cout << "Welcome " << userName << "!" << endl << endl;
    do{
        cout << "1. Update Details\n";
        cout << "2. Delete Account\n";
        cout << "Enter your Choice: ";
        cin >> opt;

        if(opt==1)
        {
            Delay(1000);
            system("cls");

            cout << "NOTE:\n\n";
            cout << "Enter '*' (Asterisk) to retain old Details. Enter new details to Update:-\n\n";
            cout << "User-name: ";

            string user;

            cin >> user;
            string i = userName;

            if(user!="*")
            {
                userName = user;
            }

            cout << "Password: ";

            string pass;
            cin >> pass;
            while(flag)
            {
                try
                {
                    if(pass.length()!=6 && pass!="*")
                        throw pass;
                    flag=0;
                }
                catch(string p)
                {
                    cout << "*** Invalid Password ***\nRe-enter : ";
                    cin>>pass;
                }
            }
            if(pass!="*")
            {
                userPwd = pass;
            }

            cout << "Mobile number: ";

            string number;

            cin >> number;
            while(flag_1)
            {
                try
                {
                    if(number.length()!=10 && number!="*")
                        throw number;
                    flag_1=0;
                }
                catch(string p)
                {
                    cout << "*** Invalid Phone Number ***Re-enter : ";
                    cin>>number;
                }
            }
            if(number!="*")
            {
                userPhNum = number;
            }

            while(!inFile.eof())
            {
                inFile >> userObj.userName >> userObj.userPwd >> userObj.userPhNum;
                if(userObj.userName!=i)
                {
                    outFile << userObj.userName << "\t" << userObj.userPwd << "\t" << userObj.userPhNum << "\n";
                }
                else
                {
                    outFile << userName << "\t" << userPwd << "\t" << userPhNum << "\n";
                }
            }

            inFile.close();
            outFile.close();

            remove("user.txt");
            rename("updatedUser.txt","user.txt");
            cout << "\n>>>Account Details Updated" << endl;
        }

        else if(opt==2)
        {
            inFile.open("user.txt");
            outFile.open("updatedUser.txt");

            while(!inFile.eof())
            {
                inFile >> userObj.userName >> userObj.userPwd >> userObj.userPhNum;
                if(userObj.userName!=userName)
                {
                    outFile << userObj.userName << "\t" << userObj.userPwd << "\t" << userObj.userPhNum << "\n";
                }
            }

            inFile.close();
            outFile.close();

            remove("user.txt");
            rename("Updated_User.txt", "user.txt");

            cout << "\n>>>Account Deleted Successfully" << endl << "\nHope to see you soon Again :)" << endl;

            Delay(1000);
            system("cls");
            exit(0);
        }
        else
            cout << "***Invalid Input. Enter Again!***" << endl;
    }while(opt!=1 && opt!=2);
}

void User :: place_order()
{
    char ch1='y', fileName[50];
    float r[50];
    int quan, opt, flag, sNo, opt2;
    ifstream inFile;
    string name, name1, d[50], Name;
    Shop S;
    Cart C;

    do{
        cout << "Available Shops:-\n";
        sNo = 1;
        inFile.open("shops.txt");
        while(!inFile.eof())
        {
            inFile >> name;
            cout << endl << sNo << ". " << name;
            sNo++;

        }
        inFile.close();

        do
        {
            cout << "\nEnter the Shop name: ";
            cin >> name;
            flag = 0;
            Name = name;
            strcpy(fileName, Name.c_str());
            strcat(fileName, ".txt");
            inFile.open(fileName);

            while(!inFile.eof())
            {
                inFile >> S.shopName >> S.shopId >> S.shopPin >> S.shopNumb;
                if(S.shopName==name)
                {
                    flag = 1;

                    for(int i=0; i<5; i++)
                    {
                        inFile >> S.shopItems[i].itemName >> S.shopItems[i].itemRate;
                        if(inFile.eof())
                            break;
                        d[i] = S.shopItems[i].itemName;
                        r[i] = S.shopItems[i].itemRate;
                    }
                    for(int j=5; j<50; j++)
                    {
                        inFile >> d[j] >> r[j];
                        if(inFile.eof())
                            break;
                    }
                    do
                    {
                        system("cls");
                        C.disp_items();
                        GotoXY(2,2);
                        S.disp_listOfItems();
                        cout << "\n1.Add an Item\n2.Delete an Item\n3.Confirm Order";
                        cout << "\n\nEnter your option: ";
                        do
                        {
                        cin >> opt;

                        int i;

                        switch(opt)
                        {
                            case 1: cout << "\nEnter the item to be added to the cart: ";
                                    cin >> name1;

                                    for(i=0;i<5;i++)
                                    {
                                        if(name1==S.shopItems[i].itemName)
                                            break;
                                    }
                                    if(i==5)
                                    {
                                        cout << "\n***Check your spelling!***";
                                        break;
                                    }

                                    cout << "Enter the quantity: ";
                                    cin >> quan;
                                    C.add_item(S.shopName, name1, S.shopItems[i].itemRate, quan);
                                    break;

                            case 2: cout << "\nEnter the item to be deleted from the cart: ";
                                    cin >> name1;
                                    for(i=0; i<5; i++)
                                    {
                                        if(name1 == S.shopItems[i].itemName)
                                            break;
                                    }
                                    if(i==5)
                                    {
                                        cout<<"\nCheck your spelling!!";
                                        break;
                                    }
                                    C.dlt_item(name1);
                                    break;

                            case 3: C.confirm_order();
                                    break;
                            default:cout<<"***Invalid Choice***";
                        }
                        }while(opt!=1 && opt!=2 && opt!=3);
                        ch1 = 'n';
                        if(opt!=3)
                        {
                            cout << "\nWanna shop more here?(Y/N)";
                            cin>>ch1;
                        }
                        if(opt==3)
                            break;
                    }while((ch1=='y' ||ch1=='Y')&& opt!=3);
                    break;
                }
            }
            inFile.close();
        }while(!flag&&cout<<"Check Spelling"<<endl);
        if(opt!=3)
        {
            cout<<"Enter to 1.Move to other shops and 2. Confirm Order\nChoice : ";
            do
            {
                cin>>opt2;
                if(opt2==2)
                {
                    C.confirm_order();
                    break;
                }
                if(opt2!=1 && opt2!=2)
                    cout<<"***Invalid Choice***\nRe-Enter : ";
            }while(opt2!=1 && opt2!=2);
        }
        if(opt==3 || opt2==2)
            break;
        system("cls");
    }while(opt2==1);
}
