#ifndef UNTITLED5_TASK23_H
#define UNTITLED5_TASK23_H

#include "ITask.h"

class Task23 : public ITask {
public:
    Task23(int num);
    void solutionTask(Type type) override;
    void checkResult(int result) override;
    void solverType1();
    void solverType2();
    void solverType3();
    void solverType4();
    void createTask(int id, int number, std::string& text,int& answer) override;
    void replacementText(std::string& str);
    int getNumber() override;

private:
    //end vector keeps answer
    std::vector<int> number_;
    std::unique_ptr<DataTask> table ;
};


#endif //UNTITLED5_TASK23_H
