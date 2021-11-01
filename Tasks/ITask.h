#ifndef UNTITLED5_ITASK_H
#define UNTITLED5_ITASK_H

#include "../Database/DataTask.h"
#include "../Utils/RandomGenerator.h"

#define BIT "битах"
#define BYTE "байтах"
#define MBYTE "мегабайтах"
#define KBYTE "килобайтах"
#define SEC "секундах"
#define MIN "минутах"
#define HOUR "часах"


class ITask {
public:
    virtual void solutionTask(Type type) = 0;
    void genRand(int count, std::vector<int> limitVec, std::vector<int>& number);
    int searchBit(int number);
    bool checkPower2(int number);
    virtual void checkResult(int result) = 0;
    void initializedTable(int num);
    virtual ~ITask() {}

    Distribution generator;
    std::unique_ptr<DataTask> table;
};


#endif //UNTITLED5_ITASK_H
