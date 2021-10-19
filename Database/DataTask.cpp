#include "DataTask.h"

const std::string host = "localhost";
const std::string user = "root";
const std::string password = "JzxU8d3s";
const std::string dbName = "ashahowa";
int port = 3306;

DataTask::DataTask()
{
    db.init(host, user,password,dbName,port);
}

void DataTask::passId(int num)
{
    const std::string query = "select id from task where id = " + std::to_string(num) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
    if (!ptr->eof()) {
        (*ptr)>>id;
    }
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

void DataTask::initCurrentDataTask(int num)
{
    passId(num);
    passQueryType();
    passNumberTask();
    passTextTask();
    passTextQuestion();
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

void DataTask::putTableAnswer(Type type, std::vector<int> vectorNumber)
{
    std::string query = "insert into answer_task values(" + std::to_string(id) + "," + std::to_string(id) + "," + std::to_string(vectorNumber.back()) + "," + " ' ";
    for (int i = 0; i < vectorNumber.size() - 1; ++i) {
        query = query + std::to_string(vectorNumber.at(i)) + " ";
    }
    query = query + " ' " + "," + + " ' " + sizeType + " ' " + ");";
//    switch (type) {
//        case type1: {
//
//            query = query + " ' " + std::to_string(number_.at(0)) + " " + std::to_string(number_.at(1)) + " ' " + "," + " ' " + table->sizeType + " ' " + ");";
//            break;
//        }
//        case type2: {
//            query = query + " ' " + std::to_string(number_.at(0)) + " " + std::to_string(number_.at(1)) + " " + std::to_string(number_.at(2)) + " ' " + "," + " ' " + table->sizeType + " ' " + ");";
//            break;
//        }
//        case type3: {
//            query = query + " ' " + std::to_string(number_.at(0)) + " " + std::to_string(number_.at(1)) + " " + std::to_string(number_.at(2)) + " ' " + "," + " ' " + table->sizeType + " ' " + ");";
//            break;
//        }
//        case type4: {
//            query = query + " ' " + std::to_string(number_.at(0)) + " " + std::to_string(number_.at(1)) + " " + std::to_string(number_.at(2)) + " " + std::to_string(number_.at(3)) + " ' " + "," + " ' " + table->sizeType + " ' " + ");";
//            break;
//        }
//        default:
//            break;
//    }
    const std::string constQuery = query;
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
