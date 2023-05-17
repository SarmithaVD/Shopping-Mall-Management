#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class User
{
    private:
        string userName, userPwd, userPhNum;

    public:
        User();
        void place_order();
        void modify_account();

        string get_userName();
        string get_userPwd();
        string get_userPhNum();
        void set_userName(string);
        void set_userPwd(string);
        void set_userPhNum(string);

        friend class Admin;
};

#endif // USER_H_INCLUDED
