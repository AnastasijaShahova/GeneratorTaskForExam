#ifndef UNTITLED5_TASK1_H
#define UNTITLED5_TASK1_H
#include "ITask.h"
#include "../Utils/GenerateMatrix.h"


class Task1 : public ITask{
public:
    Task1(int graphSize);
    void solutionTask(Type type) override;
    void solverType1();
    void solverType2();
    void solverType3();



private:
    std::unique_ptr<GenerateMatrix> matrix;
    std::vector<int> number_;
};


#endif //UNTITLED5_TASK1_H
