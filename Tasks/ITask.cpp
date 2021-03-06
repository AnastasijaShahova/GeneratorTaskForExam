#include "ITask.h"

void ITask::genRand(int count, std::vector<int> limitVec, std::vector<int>& number)
{
    for(int i = 0; i < count ; ++i)
    {
        number.push_back(generator.random(1, limitVec[i]).Mt19937());
    }
}

void ITask::genRandMin(int count, std::vector<int> limitVec, std::vector<int> mintVec, std::vector<int>& number)
{
    for(int i = 0; i < count ; ++i)
    {
        number.push_back(generator.random(mintVec[i], limitVec[i]).Mt19937());
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

int ITask::GetRandomNumber(int min, int max)
{
    srand(time(NULL));

    int num = min + rand() % (max - min + 1);

    return num;
}


