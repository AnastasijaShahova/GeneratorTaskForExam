#ifndef UNTITLED5_TASK7_H
#define UNTITLED5_TASK7_H


#include "ITask.h"

class Task7 : public ITask{
public:
    Task7(int num);
    void solutionTask(Type type) override;
    void solverType1();
    void solverType2();
    void solverType3();
    void solverType4();
    void checkResult(int result) override;
    void createTask(int id, int number, std::string& text, int& answer) override;
    int getNumber() override;
    void replacementText(std::string& str);

private:
    std::vector<int> number_;
    std::unique_ptr<DataTask> table;
};

#endif //UNTITLED5_TASK7_H
