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
    //здесь сделать проверку на ограничение по рандому
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
            genRand(3);
            break;
        }
        case type4:
        {
            genRand(4);
            break;
        }
        default:
            break;
    }
}

void Task11::solutionTask(Type type)
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

int Task11::getResult(int number1, int number2)
{
    return number1 * searchBit(number2);
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
    putTableAnswer(getTypeFromString(table->typeTask));
}

void Task11::solverType1()
{
    checkBit(getResult((number_.at(1)), number_.at(0)));
}

void Task11::solverType2()
{
    //считаем кол-во алфавита
    int count = 10 + number_.at(1);

    //определяем кол-во бит
    int res = getResult(number_.at(0), count);
    if (res % 8 != 0) {
        do {
            res++;
        } while (res % 8 != 0);
    }
    checkBit(res *  number_.back());
}

void Task11::solverType3()
{
    int resBit = getResult(number_.at(0), number_.at(1));
    if (resBit % 8 != 0) {
        do {
            resBit++;
        } while (resBit % 8 != 0);
    }
        int res = ( resBit / 8) * number_.back();
    checkBit(res * 8);
}

void Task11::solverType4()
{
    int resBit = getResult(number_.at(0), number_.at(1));
    int oneUser = 8 * ( number_.at(3) / number_.at(2) );
    checkBit(oneUser - resBit);
}

//generate vector alphabet for type3 and type4 task
void Task11::generationAlphabet(int count)
{
    std::vector<char> alphabet;
    for(int i = 0; i < count; ++i) {
        alphabet.push_back((rand() % ( 'z'-'a' +1)) +'a');
    }
}

void Task11::putTableAnswer(Type type)
{
    std::string query = "insert into answer_task values(" + std::to_string(table->id) + "," + std::to_string(table->id) + "," + std::to_string(number_.back()) + ",";
    switch (type) {
        case type1: {
            query = query + " ' " + std::to_string(number_.at(0)) + " " + std::to_string(number_.at(1)) + " ' " + "," + " ' " + table->sizeType + " ' " + ");";
            break;
        }
        case type2: {
            query = query + " ' " + std::to_string(number_.at(0)) + " " + std::to_string(number_.at(1)) + " " + std::to_string(number_.at(2)) + " ' " + "," + " ' " + table->sizeType + " ' " + ");";
            break;
        }
        case type3: {
            query = query + " ' " + std::to_string(number_.at(0)) + " " + std::to_string(number_.at(1)) + " " + std::to_string(number_.at(2)) + " ' " + "," + " ' " + table->sizeType + " ' " + ");";
            break;
        }
        case type4: {
            query = query + " ' " + std::to_string(number_.at(0)) + " " + std::to_string(number_.at(1)) + " " + std::to_string(number_.at(2)) + " " + std::to_string(number_.at(3)) + " ' " + "," + " ' " + table->sizeType + " ' " + ");";
            break;
        }
        default:
            break;
    }
    const std::string constQuery = query;
    std::unique_ptr<MySQLStatement> ptr =  db.compileStatement(query.c_str(), 200);
}

Type Task11::getTypeFromString(const std::string &strType)
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


