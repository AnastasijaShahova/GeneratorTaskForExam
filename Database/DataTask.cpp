#include "DataTask.h"



DataTask::DataTask(int num)
{
    db.init();
}

DataTask::DataTask(int numberTask, int id)
{
    db.init();
    passId(id);
    passQueryType();
    passNumberTask();
    passTextTask();
    passTextQuestion();
}

void DataTask::passId(int id)
{
    this->id = id;
}

std::vector<int> DataTask::getVectorId(int num)
{
    std::vector<int> vec;
    const std::string query = "select id from task where number_task=" + std::to_string(num) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
    if (!ptr->eof()) {
        for ( int i = 1 ; i <= countTypeTask(num); ++i) {
            (*ptr)>>id;
            vec.push_back(id);
        }
    }
    return vec;
}

void DataTask::passQueryType()
{
    const std::string query = "select type from type_task inner join task on type_task.id_task = " + std::to_string(id) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str() , 100);
    if (!ptr->eof()) {
        (*ptr)>>typeTask;
    }
}

void DataTask::passNumberTask()
{
    const std::string query = "select number_task from task where id =" + std::to_string(id) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
    if (!ptr->eof()) {
        (*ptr)>>numberTask;
    }
}

void DataTask::passTextTask()
{
    const std::string query = "select text_task from task where id =" + std::to_string(id) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
    if (!ptr->eof()) {
        (*ptr)>>textTask;
    }
}

void DataTask::passTextQuestion()
{
    const std::string query = "select text_question from task where id =" + std::to_string(id) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
    if (!ptr->eof()) {
        (*ptr)>>textQuestion;
    }
}

Type DataTask::getTypeFromString(const std::string &strType)
{
    if (strType.find("type1") != std::string::npos) {
        return type1;
    }
    else if (strType.find("type2") != std::string::npos) {
        return type2;
    }
    else if (strType.find("type3") != std::string::npos) {
        return type3;
    }
    else if (strType.find("type4") != std::string::npos) {
        return type4;
    }
    return typeDefault;
}

void DataTask::putTableAnswer(std::vector<int> vectorNumber)
{
    std::string query = "insert into answer_task(id_task, answer, parametrs,size_question) values(" + std::to_string(id) + "," + std::to_string(vectorNumber.back()) + "," + " ' ";
    for (int i = 0; i < vectorNumber.size() - 1; ++i) {
        query = query + std::to_string(vectorNumber.at(i)) + " ";
    }
    query = query + " ' " + "," + + " ' " + sizeType + " ' " + ");";
    std::unique_ptr<MySQLStatement> ptr = db.compileStatement(query.c_str(), 200);
}

int DataTask::getId() const
{
    return id;
}

int DataTask::getNumberTask() const
{
    return numberTask;
}

std::string DataTask::getTextQuestion() const
{
    return textQuestion;
}

std::string DataTask::getTextTask() const
{
    return textTask;
}

std::string DataTask::getTypeTask() const
{
    return typeTask;
}

void DataTask::setSizeType(const std::string &sizeType)
{
    DataTask::sizeType = sizeType;
}

int DataTask::countTypeTask(int num)
{
    int count = 0;
    const std::string query = "select count(id) from task where number_task = " + std::to_string(num) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
    if (!ptr->eof()) {
        (*ptr)>>count;
    }
    return count;
}

const std::string &DataTask::getSizeType()
{
    return sizeType;
}



