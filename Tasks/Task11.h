#ifndef UNTITLED5_TASK11_H
#define UNTITLED5_TASK11_H

#include "../Database/DataTask.h"
#include "../Utils/RandomGenerator.h"

class Task11 {
public:
    Task11(int num);
    void solutionTask(Type type);
    int searchBit(int number);
    int getResult(int number1, int number2);
    void checkBit(int result);
    void solverType1();
    void solverType2();
    void solverType3();
    void solverType4();

    void genRand(int kol, std::vector<int> limitVec);
    void generationAlphabet(int count);

private:
    //end vector keeps answer
    std::vector<int> number_;
    Distribution generator;
    std::unique_ptr<DataTask> table ;
};

#endif //UNTITLED5_TASK11_H
