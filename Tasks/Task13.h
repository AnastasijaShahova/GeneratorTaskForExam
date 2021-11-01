#ifndef UNTITLED5_TASK13_H
#define UNTITLED5_TASK13_H
#include "ITask.h"
#include "../Utils/GenerateMatrix.h"

class Task13 : public ITask {
public:
    Task13(int graphSize, int num);
    void solutionTask(Type type) override;
    void solverType1();
    void solverType2();
    void solverType3();
    void checkResult(int result) override;
    int algorithmD(int number1, int number2);

private:
    std::unique_ptr<GenerateMatrix> matrix;
    std::vector<int> number_;
};

#endif //UNTITLED5_TASK13_H
