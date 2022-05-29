#include "ITask.h"

void ITask::genRand(int count, std::vector<int> limitVec, std::vector<int>& number)
{
    for(int i = 0; i < count ; ++i)
    {
        number.push_back(generator.random(1, limitVec[i]).Mt19937());
    }
}

int ITask::searchBit(int number)
{
    return  ceil(log2(number));
}

bool ITask::checkPower2(int number)
{
    return (number & (number - 1) == 0);
}



