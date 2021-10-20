#ifndef UNTITLED5_TASK7_H
#define UNTITLED5_TASK7_H

#include "../Database/DataTask.h"
#include "../Utils/RandomGenerator.h"

class Task7 {
public:
    Task7(int num);
    void solutionTask(Type type);
    void solverType1();
    void solverType2();
    void solverType3();
    void solverType4();


private:
    std::vector<int> number_;
    Distribution generator;
    std::unique_ptr<DataTask> table;
};


#endif //UNTITLED5_TASK7_H
