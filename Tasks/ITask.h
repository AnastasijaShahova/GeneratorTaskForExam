#ifndef UNTITLED5_ITASK_H
#define UNTITLED5_ITASK_H

#include "../Database/DataTask.h"
#include "../Utils/RandomGenerator.h"

class ITask {
public:
    virtual void solutionTask(Type type) = 0;
    void genRand(int count, std::vector<int> limitVec);
    int searchBit(int number);

private:
    //end vector keeps answer
    std::vector<int> number_;
    Distribution generator;
};


#endif //UNTITLED5_ITASK_H
