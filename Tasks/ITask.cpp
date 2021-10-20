#include "ITask.h"

#define BIT "битах"
#define BYTE "байтах"
#define MBYTE "мегабайтах"
#define KBYTE "килобайтах"
#define MBYTE "мегобайтах"

void ITask::genRand(int count, std::vector<int> limitVec)
{
    for(int i = 0; i < count ; ++i)
    {
        number_.push_back(generator.random(2, limitVec[i]).Mt19937());
    }
}

int ITask::searchBit(int number)
{
    return  ceil(log2(number));
}

