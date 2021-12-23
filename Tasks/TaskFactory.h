#ifndef UNTITLED5_TASKFACTORY_H
#define UNTITLED5_TASKFACTORY_H

#include "ITask.h"
#include "iostream"

struct taskStruct {
    int id;
    std::string text;
    int number;
    int answer;
    taskStruct(int id_, std::string txt, int number_, int answer_) :
    id(id_), text(std::move(txt)), number(number_), answer(answer_){}
};

class TaskFactory {
public:
    TaskFactory(){}
    void createTask(std::unique_ptr<ITask> task, int number);
    std::vector<taskStruct>& getTskStr();

private:
    std::vector<taskStruct> tskStr;
};


#endif //UNTITLED5_TASKFACTORY_H
