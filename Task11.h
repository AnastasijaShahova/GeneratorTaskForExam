#ifndef UNTITLED5_TASK11_H
#define UNTITLED5_TASK11_H
#include <vector>
#include <string>
#include "MySqlDatabase.h"

enum Type {
    type1 = 1,
    type2,
    type3,
    type4,
    typeDefault
};


struct TaskTable {
    int id;
    int numberTask;
    std::string textTask;
    std::string textQuestion;
    std::string typeTask;
    std::string sizeType;
};

class Task11 {
public:
    Task11(int num);
    ~Task11();
    void getQueryType();
    void getId(int num);
    void getNumberTask();
    void getTextTask();
    void getTextQuestion();
    void generateNumber(Type type);
    void solutionTask(Type type);
    int searchBit(int number);
    void checkBit(int result);
    void solverType1();
    void solverType2();
    void solverType3();
    void solverType4();
    void putTableAnswer(Type type);
    void genRand(int kol);
    Type getTypeFromString(const std::string &strType);
    int getResult(int number1, int number2);
    void generationAlphabet(int count);

private:
    //end vector keeps answer
    std::vector<int> number_;
    std::unique_ptr<TaskTable> table = std::make_unique<TaskTable>();
    MySQLDatabase db;
};


#endif //UNTITLED5_TASK11_H
