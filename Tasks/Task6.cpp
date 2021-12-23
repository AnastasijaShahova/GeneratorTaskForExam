#include "Task6.h"

Task6::Task6(int /*num*/)
{
//    initializedTable(num);
}

void Task6::solutionTask(Type type)
{
    switch (type) {
        case type1:
        {
            std::vector<int> limitVec = { 5, 5, 500, 30, 15, 3 };
            genRand(6, limitVec, number_);
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
    int n, s;
    s = number_.at(0);
    n = number_.at(1);
    while(s <= number_.at(2)) {
        switch (number_.back()) {
            case 1: {


            }
            case 2: {

            }
            case 3: {

            }

        }
    }

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