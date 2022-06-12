#ifndef UNTITLED5_TASK4_H
#define UNTITLED5_TASK4_H
#include "ITask.h"
#include "../Utils/AlgorithmShannon.h"


class Task4 : public ITask {
public:
    Task4(int num);
    void solutionTask(Type type) override;
    void checkResult(int result) override;
    void solverType1();
    void solverType2();
    void solverType3();
    void solverType4();
    void generationAlphabet(int count);
    void createTask(int id, int number, std::string& text,int& answer) override;
    void replacementText(std::string& str);
    int getNumber() override;
    void generationAlphabet(int count, std::vector<char> &alphabet);


private:
    //end vector keeps answer
    std::vector<int> number_;
    std::unique_ptr<DataTask> table ;
    std::vector<char> alphabet;
    std::vector<std::string> binary;
    std::string question_word;
    AlgorithmShannon *shenon;
};


#endif //UNTITLED5_TASK4_H
