#ifndef UNTITLED5_DATASTATISTIC_H
#define UNTITLED5_DATASTATISTIC_H

#include "MySqlDatabase.h"

struct users_statistic {
    std::string name;
    std::string email;
    int right;
    int all_count;
};

struct user_statistic {
    int id;
    std::string name;
    int right;
    int incorrect;
    int number_task;
    int all_count;
};

class DataStatistic {
public:
    DataStatistic(const std::string &name);
    DataStatistic();
    void getUsersAllStatistic();
    int countUsersFromResult();
    int countUsers();
    void getUserStatisticForTask(const std::string &fio);
    void getUsersFromDb();
    std::vector<std::string> getUsers() const;
    std::vector<user_statistic> getUserStatistic() const;
    std::vector<users_statistic> getUsersStatistic() const;
    std::string getTextLabelFromDb(int numberTask);



private:
    std::vector<users_statistic> all_statistic;
    std::vector<user_statistic> statistic_user;
    std::vector<std::string> users;
    MySQLDatabase db;
};


#endif //UNTITLED5_DATASTATISTIC_H
