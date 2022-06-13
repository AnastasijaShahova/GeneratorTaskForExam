#ifndef UNTITLED5_STATISTICS_H
#define UNTITLED5_STATISTICS_H

#include "DataStatistic.h"

struct allStatistic {
    std::string name;
    std::string email;
    int all_count;
    int persent;
};

struct user_stat {
    int number_task;
    std::string label;
    int present;
};

class Statistics {
public:
    Statistics(const std::string &name);
    Statistics();
    const std::vector<allStatistic> &getAll() const;
    const std::vector<user_stat> &getStatTask() const;

// считает процент выполнения
void countPersentDone();
// считает процент неверных ответов
void countPersentIncorrect();

private:
    std::vector<allStatistic> all;
    std::vector<user_stat> stat_task;
    DataStatistic statistic;
};


#endif //UNTITLED5_STATISTICS_H
