#ifndef UNTITLED5_TASK16_H
#define UNTITLED5_TASK16_H


#include "ITask.h"

class Task16 : public ITask {
public:
    Task16(int num);
    void solutionTask(Type type) override;
    void solverType1();
    void solverType2();
    void solverType3();
    void checkResult(int result) override;
    void createTask(int id, int number, std::string& text, int& answer) override;
    int getNumber() override;

private:
    std::vector<int> number_;
    std::unique_ptr<DataTask> table;
};


#endif //UNTITLED5_TASK16_H
