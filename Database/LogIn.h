#ifndef UNTITLED5_LOGIN_H
#define UNTITLED5_LOGIN_H

#include <string>
#include "MySqlDatabase.h"

struct users {
    int id;
    std::string name;
    std::string email;
    std::string password;
    std::string role;
    bool loginSuccesfull = false;
    std::string message;
};

class LogIn {
public:
    LogIn(std::tuple<std::string, std::string> tyrple);
    void checkLogin();
    const users &getUsersData() const;

private:
    users usersData;
};


#endif //UNTITLED5_LOGIN_H
