#include "LogIn.h"

LogIn::LogIn(std::string password_, std::string login_)
{
    usersData.name = login_;
    usersData.password = password_;

}

//проверить корректность
void LogIn::checkLogin()
{
    const std::string query = "select id from users where name = " + usersData.name + " and passwordUser = " + usersData.password + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str() , 100);
    if (!ptr->eof()) {
        (*ptr)>>usersData.id;
        usersData.loginSuccesfull = true;
        usersData.message = "Successfully";
    }
    else {
        usersData.message = "Incorrect login or password";
    }
}

const users &LogIn::getUsersData() const
{
    return usersData;
}

void LogIn::setUsersData(const std::string& login_, const std::string& password)
{
    usersData.name = login_;
    usersData.password = password;
}

