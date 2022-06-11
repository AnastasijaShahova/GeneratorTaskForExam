#include "Task16.h"
#include <string>

static const char *CODE_TYPE3_0 = "F(%1%) = %2%;"
                               "F(%3%) = %4%;"
                               "F(n) = F(n - %5%)* %6% + F(n - %7%)* %8% ;";

static const char *CODE_TYPE3_1= "F(%1%) = %2%;"
                                 "F(%3%) = %4%;"
                                 "F(n) = F(n - %5%)* %6% + F(n - %7%)* %8% + F(n - %5%)* %6%;";

static const char *CODE_TYPE4_0= "F(%1%) = %2%;"
                                 "F(%3%) = %4%;"
                                 "F(n) = F(n - %5%) * F(n - %6%) * %7% ;";

static const char *CODE_TYPE4_1= "F(%1%) = %2%;"
                                 "F(%3%) = %4%;"
                                 "F(n) = F(n - %5%) * F(n - %6%) + %7% ;";

static const char *CODE_TYPE12= "int F(int n) {"
                                "if ( n > %1%)"
                                "   return F(n - %2% ) + G(n - %3%)"
                                "else return 1; }"
                                "int G(int n) {"
                                "if ( n > %1%)"
                                "   return G(n - %2% ) + F(n - %5%)"
                                "else return 1; }";

Task16::Task16(int num)
{
    table = std::make_unique<DataTask>(16);
    vectorId = table->getVectorId(num);
}

void Task16::solutionTask(Type type)
{
    switch (type) {
        //Рекурсивный алгоритм с двумя рек функицями при вызове F
        case type1:
        {
            std::vector<int> limitVec = { 4, 3, 3 , 4, 3, 3 ,6 };
            std::vector<int> minVec = { 2, 1, 1,2, 1, 1, 2};
            genRandMin(7,  limitVec,minVec, number_);
            solverType1();
            break;
        }
        //Рекурсивный алгоритм с двумя рек функицями при вызове G
        case type2:
        {
            std::vector<int> limitVec = { 4, 3, 3 , 4, 3, 3 ,6 };
            std::vector<int> minVec = { 2, 1, 1,2, 1, 1, 2};
            genRandMin(7,  limitVec,minVec, number_);
            solverType2();
            break;
        }
        //опирающиеся на два пред значения с суммой
        case type3:
        {
            //самое первое  определяет типо
            std::vector<int> limitVec = {1, 3, 4, 3 ,5, 3, 4,6,8 };
            std::vector<int> minVec = {0, 1, 1, 1, 2, 1, 2, 3,4};
            genRandMin(9,  limitVec,minVec, number_);
            solverType3();
            break;
        }
        //опирающиеся на два пред значения с произведением
        case type4:
        {
            std::vector<int> limitVec = {1, 3, 4, 3 ,5, 3, 4,3,5,6,7 };
            std::vector<int> minVec = {0, 1, 1, 1, 2, 1, 2,1,2, 3,3};
            genRandMin(10,  limitVec,minVec, number_);
            solverType4();
            break;
        }
        default:
            break;
    }
}

void Task16::checkResult(int result)
{

}

void Task16::solverType1()
{
    int result = F(number_.at(3));
    number_.push_back(result);
    table->putTableAnswer(number_);
}

void Task16::solverType2()
{
    int result = G(number_.at(3));
    number_.push_back(result);
    table->putTableAnswer(number_);
}

void Task16::solverType3()
{
    int result = func_sum(number_.at(8));
    number_.push_back(result);
    table->putTableAnswer(number_);
}

void Task16::solverType4()
{
    int result = func_mult(number_.at(8));
    number_.push_back(result);
    table->putTableAnswer(number_);
}

void Task16::createTask(int id, int number, std::string& text, int& answer)
{
    table = std::make_unique<DataTask>(number, id);
    number_.clear();
    solutionTask(table->getTypeFromString(table->getTypeTask()));
    answer = number_.back();
    std::string textTaskString = table->getTextTask();
    // сгенерирована строка с заданием
    int found = textTaskString.find('0');
    if (found != std::string::npos) {
        if (table->getTypeTask() == "type2" || table->getTypeTask() == "type1") {
            textTaskString.replace(found, 1, std::to_string(number_.at(6)));
        }

        else if (table->getTypeTask() == "type3"){
            textTaskString.replace(found, 1, std::to_string(number_.at(8)));
        } else {
            textTaskString.replace(found, 1, std::to_string(number_.at(10)));
        }
    }
    if (table->getTypeTask() == "type1") {
        text = textTaskString + (StrFormat(CODE_TYPE12) % number_.at(0) % number_.at(1) % number_.at(2) % number_.at(3) ).str();
    } else if (table->getTypeTask() == "type2") {
        text = textTaskString + (StrFormat(CODE_TYPE12) % number_.at(0) % number_.at(1) % number_.at(2) % number_.at(3) ).str();

    } else if (table->getTypeTask() == "type3") {
        if (number_.at(0) == 0) {
            text = textTaskString + (StrFormat(CODE_TYPE3_0) % number_.at(1) % number_.at(2) % number_.at(3) % number_.at(4) % number_.at(5) % number_.at(6) % number_.at(7) % number_.at(8)).str();

        } else {
            text = textTaskString + (StrFormat(CODE_TYPE3_1) % number_.at(1) % number_.at(2) % number_.at(3) % number_.at(4) % number_.at(5) % number_.at(6) % number_.at(7) % number_.at(8)).str();
        }

    } else if (table->getTypeTask() == "type4") {
        if (number_.at(0) == 0) {
            text = textTaskString + (StrFormat(CODE_TYPE4_0) % number_.at(1) % number_.at(2) % number_.at(3) % number_.at(4) % number_.at(5) % number_.at(6) % number_.at(7) ).str();

        } else {
            text = textTaskString + (StrFormat(CODE_TYPE4_1) % number_.at(1) % number_.at(2) % number_.at(3) % number_.at(4) % number_.at(5) % number_.at(6) % number_.at(7)).str();

        }
    }


}

int Task16::getNumber()
{
    return number_.back();
}

int Task16::F(int n)
{
    if (n > number_.at(0))
        return F(n - number_.at(1)) + G(n - number_.at(2));
    else return 1;
}

int Task16::G(int n)
{
    if (n > number_.at(0))
        return G(n - number_.at(1)) + F(n -number_.at(2));
    else return 1;
}

int Task16::func_sum(int n)
{
    if (n > 2)
        if (number_.at(0) == 0)
            return func_sum(n- number_.at(3)) * number_.at(4) +
            func_sum(n- number_.at(5)) * number_.at(6);
        else
            return func_sum(n- number_.at(3)) * number_.at(4) +
            func_sum(n- number_.at(5)) * number_.at(6) +
            func_sum(n- number_.at(3)) * number_.at(4);
        if (n == 1)
            return number_.at(1);
        if (n == 2)
            return number_.at(2);
        return 0;
}

int Task16::func_mult(int n)
{
    if (n > 2)
        if (number_.at(0) == 0) {
            return func_sum(n - number_.at(3)) *
            func_sum(n - number_.at(4)) * number_.at(5);
        }
    else {
        return func_sum(n -number_.at(3)) *
        func_sum(n - number_.at(4))  + number_.at(5);
    }
    if (n == 1)
        return number_.at(1);
    if (n == 2)
        return number_.at(2);
    return 0;
}