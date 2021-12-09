#ifndef UNTITLED5_LOGIN_H
#define UNTITLED5_LOGIN_H

#include <string>
#include "../Database/MySqlDatabase.h"

struct users {
    int id;
    std::string name;
    std::string password;
};

class LogIn {
public:
    LogIn(std::string password_, std::string login_);
    bool checkLogin();

private:
    bool loginSuccesfull = false;
    users usersData;
    MySQLDatabase db;
};


#endif //UNTITLED5_LOGIN_H
