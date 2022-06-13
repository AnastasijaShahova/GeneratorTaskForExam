#include "Statistics.h"

Statistics::Statistics(const std::string &name) : statistic(name)
{
}

void Statistics::countPersentDone()
{
    int persent;
    for (int i = 0 ; i < statistic.getUsersStatistic().size(); ++i) {
        persent = statistic.getUsersStatistic()[i].right / statistic.getUsersStatistic()[i].all_count;
        allStatistic st = {statistic.getUsersStatistic()[i].name,statistic.getUsersStatistic()[i].email,statistic.getUsersStatistic()[i].all_count,persent};
        all.push_back(st);
    }
    std::sort(all.begin(), all.end(), [](allStatistic &e1, allStatistic &e2){
        return e1.persent > e2.persent;
    });
}

// Для второй страницы статистики
void Statistics::countPersentIncorrect()
{
    int persent;
    std::string label;
    for (int i = 0 ; i < statistic.getUserStatistic().size(); ++i) {
        persent = statistic.getUserStatistic()[i].incorrect / statistic.getUserStatistic()[i].all_count;
        label = statistic.getTextLabelFromDb(statistic.getUserStatistic()[i].number_task);
        user_stat str_usr = {statistic.getUserStatistic()[i].number_task,label, persent};
        stat_task.push_back(str_usr);
    }
}

void Statistics::countColor()
{
    std::string color;
    for (int i = 0 ; i < statistic.getUsersStatistic().size(); ++i) {
        if (statistic.getUserStatistic()[i].incorrect / statistic.getUserStatistic()[i].all_count > 0.7) {
            color = "green";
        } else if (statistic.getUserStatistic()[i].incorrect / statistic.getUserStatistic()[i].all_count > 0.5 && statistic.getUserStatistic()[i].incorrect / statistic.getUserStatistic()[i].all_count < 0.7) {
            color = "yellow";
        } else {
            color = "red";
        }
        for_teacher teach = {statistic.getUsersStatistic()[i].name,statistic.getUsersStatistic()[i].email,color};
        for_teach.push_back(teach);
    }
}

const std::vector<allStatistic> &Statistics::getAll() const {
    return all;
}

const std::vector<user_stat> &Statistics::getStatTask() const {
    return stat_task;
}

const std::vector<for_teacher> &Statistics::getForTeach() const {
    return for_teach;
}
