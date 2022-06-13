#include "DataStatistic.h"

DataStatistic::DataStatistic(const std::string &name)
{
    db.init();
    getUsersAllStatistic();
    getUserStatisticForTask(name);
    getUsersFromDb();
}

DataStatistic::DataStatistic()
{
    db.init();
    getUsersAllStatistic();
    getUsersFromDb();
}

// вытаскиваем данные для общей статистики из таблицы
void DataStatistic::getUsersAllStatistic()
{
    const std::string query = "select name,email,sum(correctCount), sum(all_count) from users_result group by name,email;" ;
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str() , 200);
    if (!ptr->eof()) {
        for (int i = 0; i< countUsersFromResult();++i) {
            (*ptr)>>all_statistic[i].name;
            (*ptr)>>all_statistic[i].email;
            (*ptr)>>all_statistic[i].right;
            (*ptr)>>all_statistic[i].all_count;
        }
    }
}

// Вытаскиваем данные для конкретного юзера по заданиям
void DataStatistic::getUserStatisticForTask(const std::string &fio)
{
    const std::string query = "select id,name,correctCount,uncorrectCount,numberTask,all_count  from users_result where name = " + fio + ";" ;
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str() , 200);
    if (!ptr->eof()) {
        for (int i = 0; i< countUsersFromResult();++i) {
            (*ptr)>>statistic_user[i].id;
            (*ptr)>>statistic_user[i].name;
            (*ptr)>>statistic_user[i].right;
            (*ptr)>>statistic_user[i].incorrect;
            (*ptr)>>statistic_user[i].number_task;
            (*ptr)>>statistic_user[i].all_count;
        }
    }
}

// Получение списка всех пользователей
void DataStatistic::getUsersFromDb()
{
    const std::string query = "select fio from users;" ;
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str() , 200);
    if (!ptr->eof()) {
        for (int i = 0; i< countUsers();++i) {
            (*ptr)>>users[i];
        }
    }
}

int DataStatistic::countUsers()
{
    int count = 0;
    const std::string query = "select count(fio) from users;";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
    if (!ptr->eof()) {
        (*ptr)>>count;
    }
    return count;
}

int DataStatistic::countUsersFromResult()
{
    int count = 0;
    const std::string query = "select count(name) from users_result;";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
    if (!ptr->eof()) {
        (*ptr)>>count;
    }
    return count;
}

std::vector<std::string> DataStatistic::getUsers() const
{
    return users;
}

std::vector<user_statistic> DataStatistic::getUserStatistic() const
{
    return statistic_user;
}

std::vector<users_statistic> DataStatistic::getUsersStatistic() const
{
    return all_statistic;
}

std::string DataStatistic::getTextLabelFromDb(int numberTask)
{
    MySQLDatabase db;
    std::string res;
    db.init();
    const std::string query = "select label from task_label where number_task =" + std::to_string(numberTask) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str() , 200);
    if (!ptr->eof()) {
        (*ptr)>>res;
    }
    return res;
}