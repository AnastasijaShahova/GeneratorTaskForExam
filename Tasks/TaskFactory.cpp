#include "TaskFactory.h"

void TaskFactory::createTask(std::unique_ptr<ITask> task, int number)
{
    int randId;
    std::string text;
    int answer;
    for( int i = 0; i < 5; ++i ) {
        randId = task->generator.random(1, task->vectorId.size()).Mt19937();
        task->createTask(task->vectorId[randId - 1], number, text, answer);
        tskStr.emplace_back(randId, text, number, answer);
    }
}

std::vector<taskStruct>& TaskFactory::getTskStr()
{
    return tskStr;
}


