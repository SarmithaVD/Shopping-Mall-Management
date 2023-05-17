#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <iostream>
#include <string>

#include "user.h"
#include "shop.h"

using namespace std;

class Admin
{
    private:
        int nShop;

    public:
        Admin();

        void write_shops();

        bool check_user(string, string, User&);
        User create_user();
        void dlt_user();

        bool check_shop(string, int, Shop&);
        Shop add_shop();
        void dlt_shop();
};

#endif // ADMIN_H_INCLUDED
