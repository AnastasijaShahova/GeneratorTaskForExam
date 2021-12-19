#include "LogIn.h"


LogIn::LogIn(std::tuple<std::string, std::string> turple)
{
    usersData.email = get<0>(turple);
    usersData.password = get<1>(turple);
}

void LogIn::checkLogin()
{
    MySQLDatabase db;
    db.init();
    const std::string query = "select id,fio,role from users where name = '" + usersData.email + "' " + " and passwordUser = '" + usersData.password + "' " + ";";

    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str() , 200);
    if (!ptr->eof()) {
        (*ptr)>>usersData.id;
        (*ptr)>>usersData.name;
        (*ptr)>>usersData.role;
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


