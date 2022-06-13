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

struct for_teacher {
    std::string name;
    std::string email;
    std::string color;
};

class Statistics {
public:
    Statistics(const std::string &name);
    Statistics();
    const std::vector<allStatistic> &getAll() const;
    const std::vector<user_stat> &getStatTask() const;
    const std::vector<for_teacher> &getForTeach() const;

// считает процент выполнения
void countPersentDone();
// считает процент неверных ответов
void countPersentIncorrect();

void countColor();

private:
    std::vector<allStatistic> all;
    std::vector<user_stat> stat_task;
    std::vector<for_teacher> for_teach;
    DataStatistic statistic;
};


#endif //UNTITLED5_STATISTICS_H
