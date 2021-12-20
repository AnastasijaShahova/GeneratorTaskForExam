#ifndef UNTITLED5_TASK11_H
#define UNTITLED5_TASK11_H

#include "ITask.h"

class Task11 : public ITask{
public:
    Task11(int num);
    void solutionTask(Type type) override;
    int getResult(int number1, int number2);
    void checkResult(int result) override;
    void solverType1();
    void solverType2();
    void solverType3();
    void solverType4();
    void generationAlphabet(int count);
    void createTask(int id, int number, std::string& text) override;
    void replacementText(std::string& str);


private:
    //end vector keeps answer
    std::vector<int> number_;
    std::unique_ptr<DataTask> table ;
//    std::vector<taskStruct> taskVector;
};

#endif //UNTITLED5_TASK11_H
