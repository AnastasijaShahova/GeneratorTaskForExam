#ifndef UNTITLED5_TASK14_H
#define UNTITLED5_TASK14_H

#include "ITask.h"

class Task14 : public ITask {
public:
    Task14(int num);
    void solutionTask(Type type) override;
    int getResult(int number1, int number2);
    void checkResult(int result) override;
    void solverType1();
    void solverType2();
    void solverType3();
    void solverType4();
    void generationAlphabet(int count,  std::vector<char> &alphabet);
    void createTask(int id, int number, std::string& text,int& answer) override;
    int getNumber() override;
    void replacementText(std::string& str);

private:
    //end vector keeps answer
    std::vector<int> number_;
    std::unique_ptr<DataTask> table ;
    std::vector<int> base = {2,4,8};
};


#endif //UNTITLED5_TASK14_H
