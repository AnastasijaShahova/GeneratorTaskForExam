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

    void genRand(int kol);
    void generationAlphabet(int count);

    DataTask getTable();

private:
    //end vector keeps answer
    std::vector<int> number_;
    std::unique_ptr<DataTask> table = std::make_unique<DataTask>();
};

#endif //UNTITLED5_TASK11_H
