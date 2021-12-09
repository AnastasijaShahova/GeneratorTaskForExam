#include "LogIn.h"

LogIn::LogIn(std::string password_, std::string login_)
{
    usersData.name = login_;
    usersData.password = password_;

}

bool LogIn::checkLogin()
{
    const std::string query = "select id from users where name = " + usersData.name + " and passwordUser = " + usersData.password + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str() , 100);
    if (!ptr->eof()) {
        (*ptr)>>usersData.id;
        loginSuccesfull = true;
    }
    else {
        throw "Incorrect password or login";
    }
    return loginSuccesfull;
}
