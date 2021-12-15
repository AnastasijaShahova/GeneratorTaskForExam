#ifndef UNTITLED5_LOGIN_H
#define UNTITLED5_LOGIN_H

#include <string>
#include "../Database/MySqlDatabase.h"

struct users {
    int id;
    std::string name;
    std::string password;
    bool loginSuccesfull = false;
    std::string message;
};

class LogIn {
public:
    LogIn();
    LogIn(const std::string& password_, const std::string& login_);
    void checkLogin();

    const users &getUsersData() const;
    void setUsersData(const std::string& login_,const std::string& password);


private:
    users usersData;
    MySQLDatabase db;
};


#endif //UNTITLED5_LOGIN_H
