#ifndef UNTITLED5_DATATASK_H
#define UNTITLED5_DATATASK_H

#include "MySqlDatabase.h"

enum Type {
    type1 = 1,
    type2,
    type3,
    type4,
    typeDefault
};

class DataTask {
public:
    DataTask(int num);
    void passQueryType();
    void passId(int num);
    void passNumberTask();
    void passTextTask();
    void passTextQuestion();
    Type getTypeFromString(const std::string &strType);
    void putTableAnswer(Type type, std::vector<int> vectorNumber);

    int getId() const;
    int getNumberTask() const;
    std::string getTextQuestion() const;
    std::string getTextTask() const;
    std::string getTypeTask() const;
    void setSizeType(const std::string &sizeType);

private:
    int id;
    int numberTask;
    std::string textQuestion;
    std::string textTask;
    std::string sizeType;
    std::string typeTask;
    MySQLDatabase db;
};


#endif //UNTITLED5_DATATASK_H
