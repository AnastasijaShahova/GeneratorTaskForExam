#include "Task11.h"
#include <math.h>
#include <string>

#define BIT "битах"
#define BYTE "байтах"
#define MBYTE "мегабайтах"
#define KBYTE "килобайтах"
#define MAX 500
#define MIN 10

const std::string host = "localhost";
const std::string user = "root";
const std::string password = "JzxU8d3s";
const std::string dbName = "ashahowa";
int port = 3306;

Task11::Task11(int num)
{
    db.init(host, user,password,dbName,port);
    getId(num);
    getQueryType();
    getNumberTask();
    getTextTask();
    getTextQuestion();
    generateNumber(getTypeFromString(table->typeTask));
}

Task11::~Task11()
{
}

void Task11::getId(int num)
{
    const std::string query = "select id from task where id = " + std::to_string(num) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
    if (!ptr->eof()) {
        (*ptr)>>table->id;
    }
}

void Task11::getQueryType()
{
    const std::string query = "select type from type_task inner join task on type_task.id_task = " + std::to_string(table->id) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str() , 100);
    if (!ptr->eof()) {
        (*ptr)>>table->typeTask;
    }
}

void Task11::getNumberTask()
{
    const std::string query = "select number_task from task where id =" + std::to_string(table->id) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
    if (!ptr->eof()) {
        (*ptr)>>table->numberTask;
    }
}

void Task11::getTextTask()
{
    const std::string query = "select text_task from task where id =" + std::to_string(table->id) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
    if (!ptr->eof()) {
        (*ptr)>>table->textTask;
    }
}

void Task11::getTextQuestion()
{
    const std::string query = "select text_question from task where id =" + std::to_string(table->id) + ";";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
    if (!ptr->eof()) {
        (*ptr)>>table->textQuestion;
    }
}

void Task11::genRand(int kol)
{
    for(int i = 0; i < kol ; ++i)
    {
        number_.push_back(rand() % (MAX - MIN + 1) + MIN);
    }
}

void Task11::generateNumber(Type type)
{
    switch (type) {
        case type1:
        {
            genRand(2);
            break;
        }
        case type2:
        {
            genRand(3);
            break;
        }
        case type3:
        {
            //поставить другие знач
            genRand(2);
            break;
        }
        case type4:
        {
            //поставить другие знач
            genRand(2);
            break;
        }
        default:
            break;
    }
}

void Task11::solutionTask(Type type, const std::string &stringSize)
{
    switch (type) {
        case type1:
        {
            solverType1();
            break;
        }
        case type2:
        {
            solverType2();
            break;
        }
        case type3:
        {
            solverType3();
            break;
        }
        case type4:
        {
            solverType4();
            break;
        }
        default:
            break;
    }
}

int Task11::searchBit(int number)
{
    return  ceil(log2(number));
}

void Task11::checkBit(int result)
{
    if (result % 8 == 0) {
        if (result % 1024 == 0) {
            number_.push_back(result / 8192);
            table->sizeType = KBYTE;
        }
        else {
            number_.push_back(result / 8);
            table->sizeType = BYTE;
        }
    }
    else {
        number_.push_back(result);
        table->sizeType = BIT;
    }
    putTableAnswer();
}

void Task11::solverType1()
{
    int sizeBit = searchBit(number_.front());
    int result = (number_.front() + 1) * sizeBit;
    checkBit(result);
}

void Task11::solverType2()
{
    //считаем кол-во алфавита
    int count = 10 + number_.front() + 1;

    int result;
    //определяем кол-во бит
    int sizeBit = searchBit(count);
    int res = sizeBit * number_.front();
    if (res % 8 != 0) {
        do {
            res++;
        } while (res % 8 != 0);
    }
    result = res *  number_.back();
//    number_.push_back(res *  number_.back());
    checkBit(result);
}

void Task11::solverType3()
{

}

void Task11::solverType4()
{

}

void Task11::putTableAnswer()
{
    const std::string query = "insert into answer_task values(" + std::to_string(table->id) + "," + std::to_string(table->id) + "," + std::to_string(number_.back()) + "," +  " ' " + std::to_string(number_.front()) + " " + std::to_string(number_.front() + 1 ) + " ' " + "," + " ' " + table->sizeType + " ' " + ");";
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 100);
}

Type Task11::getTypeFromString(const std::string &strType)
{
    if (strType.find("type1")) {
        return type1;
    }
    else if (strType.find("type2")) {
        return type2;
    }
    else if (strType.find("type3")) {
        return type3;
    }
    else if (strType.find("type4")) {
        return type4;
    }
    return typeDefault;
}


