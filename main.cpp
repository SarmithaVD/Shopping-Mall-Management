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
#include "admin.h"

using namespace std;

void delay(unsigned int mseconds)
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}
COORD coord1={0,0};
void Gotoxy(int x,int y)
{
    coord1.X=x;
    coord1.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord1);
}

Admin a;
User u;
Shop s;
string name,pwd,num;
int pwd1;

void funWelcome()
{
    int i;
    for(i=1;i<120;i++)  //the topmost line
    {
        Gotoxy(i,1);
        cout<<"-";
        delay(10);
    }
    for(i=2;i<25;i++)  //the rightmost line
    {
        Gotoxy(119,i);
        cout<<"|";
        delay(10);
    }
    for(i=119;i>=1;i--)  //the bottom line
    {
        Gotoxy(i,24);
        cout<<"-";
        delay(10);
    }
    for(i=23;i>1;i--)   //the leftmost line
    {
        Gotoxy(1,i);
        cout<<"|";
        delay(10);
    }
}

void write()
{
    int pin[12], i;
    ofstream outFile("user.txt");
    Item rmkv[5], hm[5], trends[5], maxfash[5], haribhav[5], kfc[5], keven[5], dom[5], apple[5], oneplus[5], hp[5], dell[5];

    rmkv[0].read_values("Silk_Saree", 8000.00);
    rmkv[1].read_values("Benaras_Cotton_Saree", 4000.00);
    rmkv[2].read_values("Casual_Shirt", 800.00);
    rmkv[3].read_values("Formal_Shirt", 950.00);
    rmkv[4].read_values("Kurta", 1500.00);

    hm[0].read_values("Ladies_Top", 500.00);
    hm[1].read_values("Ladies_Dress", 1500.00);
    hm[2].read_values("Men_T-shirt", 750.00);
    hm[3].read_values("Men_Shirt", 1200.00);
    hm[4].read_values("Ladies_Sportswear", 700.00);

    trends[0].read_values("Kurti", 550.00);
    trends[1].read_values("Jean", 600.00);
    trends[2].read_values("Palazzo", 350.00);
    trends[3].read_values("Shirt", 300.00);
    trends[4].read_values("Kurta_Set", 1100.00);

    maxfash[0].read_values("T-shirt", 500.00);
    maxfash[1].read_values("Bottom", 700.00);
    maxfash[2].read_values("Jumpsuit", 900.00);
    maxfash[3].read_values("Women_Footwear", 600.00);
    maxfash[4].read_values("Men_Footwear", 800.00);

    haribhav[0].read_values("Mutton_Biriyani", 190.00);
    haribhav[1].read_values("Chicken_Roast", 145.00);
    haribhav[2].read_values("Egg_Kothu_Parotta", 70.00);
    haribhav[3].read_values("Vanjaram_Fish_Fry", 160.00);
    haribhav[4].read_values("Chicken_65", 185.00);

    kfc[0].read_values("Chicken_Bucket", 460.00);
    kfc[1].read_values("Pepsi", 60.00);
    kfc[2].read_values("TripleTreat", 640.00);
    kfc[3].read_values("Mingles_Bucket", 290.00);
    kfc[4].read_values("KFC_Meal", 380.00);

    keven[0].read_values("CaramelloReg", 180.00);
    keven[1].read_values("RoseBadham", 110.00);
    keven[2].read_values("KitKat_Shake", 150.00);
    keven[3].read_values("Oreo_Shake", 170.00);
    keven[4].read_values("Dark_Sundae", 210.00);

    dom[0].read_values("Margherita_(Medium)", 240.00);
    dom[1].read_values("Cheese_n_Corn_(Medium)", 380.00);
    dom[2].read_values("Peppy_Paneer_(Medium)", 460.00);
    dom[3].read_values("Spiced_Double_Chicken_(Medium)", 560.00);
    dom[4].read_values("Paneer_Tikka_Stuffed_Garlic_Bread_(Medium)", 170.00);

    apple[0].read_values("iPhone_13_Pro", 120000.00);
    apple[1].read_values("iPad_air", 55000.00);
    apple[2].read_values("MacBook_Pro_13", 130000.00);
    apple[3].read_values("AirPod_Pro", 26500.00);
    apple[4].read_values("Apple_Watch_Series_7", 42000.00);

    oneplus[0].read_values("OnePlus_10R_5G", 39000.00);
    oneplus[1].read_values("OnePlus_TV_Y_Series_Y15_Pro", 30000.00);
    oneplus[2].read_values("OnePlus_Buds_Pro", 10000.00);
    oneplus[3].read_values("OnePlus_Band", 2000.00);
    oneplus[4].read_values("OnePlus_Watch", 14000.00);

    hp[0].read_values("Pavilion_Aero", 82000.00);
    hp[1].read_values("Pavilion_31.5_All-in-one_Desktop_PC", 126000.00);
    hp[2].read_values("M27_Webcam_Monitor", 29000.00);
    hp[3].read_values("Large_Format/DesignJet_Printer", 83000.00);
    hp[4].read_values("680_2-pack_Tricolor_Catridges", 1650.00);

    dell[0].read_values("Inspiron_14_2-in-1_Laptop", 80800.00);
    dell[1].read_values("Inspiron_3910_Desktop", 90000.00);
    dell[2].read_values("Alienware_M15_R7_Gaming_Laptop", 27000.00);
    dell[3].read_values("Multi-device_Wireless_Mouse", 2700.00);
    dell[4].read_values("Premier_Multi-device_Wireless_and_Mouse", 7300.00);

    for(i=0; i<13; i++)
    {
        cout << setfill('0') << setw(5);
        pin[i] = rand()%99999;
    }

    Shop RmKV("RmKV", "RmKV@11", pin[0], "A01", rmkv);
    RmKV.write_shopTxt();

    Shop HM("H&M", "H&M@22", pin[1], "B02", hm);
    HM.write_shopTxt();

    Shop Trends("Trends", "Trends@33", pin[2], "C03", trends);
    Trends.write_shopTxt();

    Shop Max("Max", "Max@44", pin[3], "D01", maxfash);
    Max.write_shopTxt();

    Shop Haribhavanam("Haribhavanam", "HB@55", pin[4], "A02", haribhav);
    Haribhavanam.write_shopTxt();

    Shop KFC("KFC", "KFC@66", pin[5], "B03", kfc);
    KFC.write_shopTxt();

    Shop Keventers("Keventers", "Keventers@77", pin[6], "C01", keven);
    Keventers.write_shopTxt();

    Shop Dominos("Dominos", "Dominos@88", pin[7], "D02", dom);
    Dominos.write_shopTxt();

    Shop Apple("Apple", "Apple@99", pin[8], "A03", apple);
    Apple.write_shopTxt();

    Shop OnePlus("OnePlus", "OnePlus@1010", pin[9], "B01", oneplus);
    OnePlus.write_shopTxt();

    Shop HP("HP", "HP@1111", pin[10], "C02", hp);
    HP.write_shopTxt();

    Shop Dell("Dell", "Dell@1212", pin[11], "D03", dell);
    Dell.write_shopTxt();

    a.write_shops();

    outFile << "Harini" << "\t" << "123456" << "9898989898" << endl;
    outFile << "Sarmitha" << "\t" << "654321" << "8989898989" << endl;
    outFile.close();
}

void funAdminMenu()
{
    int opt;
    Gotoxy(40,10);
    cout<<"WELCOME TO SAHAR SHOPPING MALL";
    Gotoxy(30,12);
    cout<<"\t1.Delete Shop\n";
    Gotoxy(30,14);
    cout<<"\t2.Delete User\n";
    Gotoxy(30,16);
    cout<<"\t3.Exit\n";
    Gotoxy(40,20);
    cout<<"\nEnter your option: ";
    cin>>opt;
    system("cls");
    switch(opt)
    {
        case 1: a.dlt_shop();
                break;
        case 2: a.dlt_user();
                break;
        case 3: exit(0);
        default: system("cls");
                 exit(0);
    }
}

void funUser()
{
    int ch2;
    Gotoxy(40,10);
    cout<<"WELCOME TO SAHAR SHOPPING MALL";
    Gotoxy(30,12);
    cout<<"1.Place an order";
    Gotoxy(30,14);
    cout<<"2.Modify your account";
    Gotoxy(30,16);
    cout<<"3.Exit";
    Gotoxy(40,20);
    cout<<"Choose your option:";
    cin>>ch2;
    system("cls");
    switch(ch2)
    {
        case 1: u.place_order();
                break;
        case 2: u.modify_account();
                break;
        case 3: exit(0);
        default:cout<<"\nInput Error!!";
                delay(2000);
                exit(0);
    }
}

void funShop()
{
    int ch2;
    Gotoxy(40,10);
    cout<<"WELCOME TO SAHAR SHOPPING MALL";
    Gotoxy(30,12);
    cout<<"1.Update Items";
    Gotoxy(30,14);
    cout<<"2.Modify Details of Items";
    Gotoxy(30,16);
    cout<<"3.Exit";
    Gotoxy(40,18);
    cout<<"Choose your option:";
    cin>>ch2;
    system("cls");
    switch(ch2)
    {
        //case 1: s.update_item();
               // break;
        case 2: s.modify_details();
                break;
        case 3: exit(0);
        default:cout<<"\nInput Error!!";
                delay(2000);
                exit(0);
    }
}

int main()
{
    write();
    int ch, ch1, ch2;
    cout<<"\nWELCOME TO SAHAR SHOPPING MALL";
    cout<<"\n\t1.Users";
    cout<<"\n\t2.Shop Management";
    cout<<"\n\t3.Admin";
    cout<<"\n\t4.Exit";
    cout<<"\nChoose your login: ";
    do
    {
        cin>>ch;
        if(ch==1)
        {
            system("cls");
            cout<<"\n\t1.Hello Customer!Login using your account";
            cout<<"\n\t2.New User?Create a new account";
            cout<<"\nChoose to enjoy our service... \nChoice : ";
            do
            {
                cin>>ch1;
                if(ch1==1)
                {
                    do
                    {
                        cout<<"\nEnter your user-id:";
                        getchar();
                        getline(cin,name);
                        cout<<"Enter your password:";
                        cin>>pwd;
                        if(a.check_user(name,pwd,u))
                        {
                            cout<<"\nLogin Success!!";
                            break;
                        }
                        else
                        {
                            cout<<"\nUser doesn't exist!\nEnter 1 to re-enter and 2 to create new account : ";
                            do
                            {
                                cin>>ch2;
                                if(ch2==2)
                                    ch1=2;
                                else if(ch1!=1 && ch1!=2)
                                    cout<<"\nInvalid choice!!\nRe-Enter : ";
                            }while(ch1!=1 && ch1!=2);
                        }
                    }while(ch2==1);
                }
                if(ch1==2)
                    u=a.create_user();
                if(ch1!=1 && ch1!=2)
                    cout<<"***Invalid choice***\nRe-Enter : ";
            }while(ch1!=1 && ch1!=2);
            delay(1000);
            system("cls");
            funWelcome();
            funUser();
        }
        else if(ch==2)
        {
            system("cls");
            cout<<"Shop Login"<<endl;
            cout<<"\n\t1.Login into your Shop account.";
            cout<<"\n\t2.Add your Shop.";
            cout<<"\nChoose to enjoy our service... :";
            do
            {
                cin>>ch1;
                if(ch1==1)
                {
                    do
                    {
                        cout<<"\nEnter your Shop number: ";
                        cin>>num;
                        cout<<"Enter your password:";
                        cin>>pwd1;
                        if(a.check_shop(num,pwd1,s))
                        {
                            cout<<"\nLogin Success!!";
                            break;
                        }
                        else
                        {
                            cout<<"\nShop doesn't exist!\nEnter 1 to re-enter and 2 to create new Shop : ";
                            cin>>ch2;
                            do
                            {
                                cin>>ch2;
                                if(ch2==2)
                                    ch1=2;
                                else if(ch1!=1 && ch1!=2)
                                    cout<<"\nInvalid choice!!\nRe-Enter : ";
                            }while(ch1!=1 && ch1!=2);
                        }
                    }while(ch2==1);
                }
                if(ch1==2)
                    s=a.add_shop();
                if(ch1!=1 && ch1!=2)
                    cout<<"***Invalid choice***\nRe-Enter : ";
            }while(ch1!=1 && ch1!=2);
            delay(1000);
            system("cls");
            funWelcome();
            funShop();
        }
        else if(ch==3)
        {
            system("cls");
            string name1, pwd2;
            cout<<"Enter the User Name: ";
            cin>>name1;
            cout<<"Enter the Password: ";
            cin>>pwd2;
            if (name1=="admin" && pwd2=="admin")
            {
                delay(1000);
                system("cls");
                funWelcome();
                funAdminMenu();
            }
        }
        else if(ch==4)
            exit(0);
        else
            cout<<"Invalid Choice!!Re.Enter: ";
    }while(ch!=1 && ch!=2 && ch!=3 && ch!=4);
    return 0;
}

