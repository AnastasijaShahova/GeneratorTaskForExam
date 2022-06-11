#ifndef UNTITLED5_TASK22_H
#define UNTITLED5_TASK22_H

#include "ITask.h"

class Task22 : public ITask{
public:
    Task22(int num);
    void solutionTask(Type type) override;
    void solverType1();
    void solverType2();

    void checkResult(int result) override;
    void createTask(int id, int number, std::string& text, int& answer) override;
    int getNumber() override;

    int twentytwo_max(int n);
    int twentytwo_min(int n);

private:
    std::vector<int> number_;
    std::vector<std::string> sign_vec;
    std::unique_ptr<DataTask> table;
};


#endif //UNTITLED5_TASK22_H
