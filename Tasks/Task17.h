#ifndef UNTITLED5_TASK17_H
#define UNTITLED5_TASK17_H


#include "ITask.h"

class Task17 : public ITask {
public:
    Task17(int num);
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
    void writeNumberInFile() ;
private:
    //end vector keeps answer
    std::vector<int> number_;
    std::unique_ptr<DataTask> table ;
    bool chet = 0;
};


#endif //UNTITLED5_TASK17_H
