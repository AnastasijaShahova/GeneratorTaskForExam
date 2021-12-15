#include "LogIn.h"

LogIn::LogIn(std::tuple<std::string, std::string> turple)
{
    db.init();
    usersData.name = get<0>(turple);
    usersData.password = get<1>(turple);
}

void LogIn::checkLogin()
{
    const std::string query = "select id from users where name = '" + usersData.name + "' " + " and passwordUser = '" + usersData.password + "' " + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str() , 200);
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


