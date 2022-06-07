#ifndef UNTITLED5_TASK8_H
#define UNTITLED5_TASK8_H

#include "ITask.h"

class Task8 : public ITask {

public:
    Task8(int num);
    void solutionTask(Type type) override;
    int getResult(int number1, int number2);
    void checkResult(int result) override;
    void solverType1();
    void solverType2();
    void solverType3();
    void solverType4();
    void generationAlphabet(int count,  std::vector<char> &alphabet);
    void createTask(int id, int number, std::string& text,int& answer) override;
    void replacementText(std::string& str);
    void replaceChar(std::string& textTaskString, int found_char,  std::vector<char> &alphabet);
    int getNumber() override;
    void generateVectorChar(std::vector<std::string> & vec) ;
    int convertTo10(int number);
    void replacementTextForType4(std::string& textTaskString);



private:
    //end vector keeps answer
    std::vector<int> number_;
    std::unique_ptr<DataTask> table ;
    std::vector<char> alphabet;
    std::string question_word;
};


#endif //UNTITLED5_TASK8_H
