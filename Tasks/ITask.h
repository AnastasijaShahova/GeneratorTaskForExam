#ifndef UNTITLED5_ITASK_H
#define UNTITLED5_ITASK_H

#include "../Database/DataTask.h"
#include "../Utils/RandomGenerator.h"
#include "../Utils/StrFormat.h"

#define BIT " битах"
#define BYTE " байтах"
#define MBYTE " мегабайтах"
#define KBYTE " килобайтах"
#define SEC " секундах"
#define MIN " минутах"
#define HOUR " часах"


class ITask {
public:
    virtual void solutionTask(Type type) = 0;
    void genRand(int count, std::vector<int> limitVec, std::vector<int>& number);
    int searchBit(int number);
    bool checkPower2(int number);
    virtual void checkResult(int result) = 0;
    virtual void createTask(int id, int number, std::string& text, int& answer) = 0;
    void genRandMin(int count, std::vector<int> limitVec,std::vector<int> mintVec, std::vector<int>& number);
    virtual ~ITask() {}
    virtual int getNumber() = 0;

    Distribution generator;
    std::vector<int> vectorId;
};


#endif //UNTITLED5_ITASK_H
