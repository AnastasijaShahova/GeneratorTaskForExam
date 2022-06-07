#include "Task6.h"
#include <map>

std::map<std::string,std::string> map = {{"<","+"},
                                         {"<=", "+"},
                                         {">", "-"},
                                         {">=", "-"},
                                         };

Task6::Task6(int num)
{
    table = std::make_unique<DataTask>(6);
    vectorId = table->getVectorId(num);
//    initializedTable(num);
}

void Task6::solutionTask(Type type)
{
    switch (type) {
        case type1:
        {
            std::vector<int> limitVec = { 7, 80, 10, 5 };
            genRand(4, limitVec, number_);
            solverType1();
            break;
        }
        // арифмет прогрессия
        case type2:
        {
            std::vector<int> limitVec = { 10, 33, 400, 3 };
            genRand(5, limitVec, number_);
            solverType2();
            break;
        }
        case type3:
        {
            std::vector<int> limitVec = { 4, 20, 1000, 256, 55, 3 };
            genRand(6, limitVec, number_);
            solverType3();
            break;
        }
        default:
            break;
    }
}

void Task6::checkResult(int result)
{

    table->putTableAnswer(number_);
}

void Task6::solverType1()
{
    int n, s,min;
    n = number_.at(0);
    for (int i = 0; i < number_.at(1) ; ++i) {
        while(s <= number_.at(1)) {
            switch (number_.back()) {
                case 1: {


                }
                case 2: {

                }
                case 3: {

                }

            }
        }
        if (n == 64) {
            min = i;
        }
    }
    number_.push_back(min);

}

void Task6::solverType2()
{

}

void Task6::solverType3()
{

}

void Task6::createTask(int id, int number, std::string& text, int& answer)
{

}

int Task6::getNumber()
{
    return number_.back();
}