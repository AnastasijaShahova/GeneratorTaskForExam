#include "Task7.h"

Task7::Task7(int num)
{
//    initializedTable(num);
}

void Task7::solutionTask(Type type)
{
    switch (type) {
        //хранение изображений
        case type1:
        {
            //проверка на то, чтобы все было в степенях двойки
            std::vector<int> limitVec = { 1024, 1024, 512 };
            genRand(3, limitVec, number_);
            solverType1();
            break;
        }
        //хранение звук файлов
        case type2:
        {
            std::vector<int> limitVec = { 100, 64, 100 };
            genRand(3, limitVec, number_);
            solverType2();
            break;
        }
        //определение времени перадачи
        case type3:
        {
            std::vector<int> limitVec = { 20, 15, 12, 1024 };
            genRand(4, limitVec, number_);
            solverType3();
            break;
        }
        //сравнение двух способов
        case type4:
        {
            std::vector<int> limitVec = { 20, 20, 80, 25, 10 };
            genRand(5, limitVec, number_);
            solverType4();
            break;
        }
        default:
            break;
    }
}

void Task7::solverType1()
{
    if (!checkPower2(number_.at(0)) || !checkPower2(number_.at(1))) {
        number_.at(0) = pow(2, generator.random(2, 10).Mt19937());
        number_.at(1) = pow(2, generator.random(2, 10).Mt19937());
    }
    int result = number_.at(0) * number_.at(1) * searchBit(number_.at(2));
}

void Task7::solverType2()
{
    if (number_.at(1) % 8) {
        number_.at(1) = pow(8, generator.random(2, 4).Mt19937());
    }
    int byte = number_.at(1) / 8;
    double result = (number_.at(2) * pow(2, 20)) / (byte * number_.at(0) * 1000);
    checkResult(round(result));
}

void Task7::solverType3()
{
    int t0 = ( number_.at(3) * pow(2, 20) ) /  pow(2, number_.at(0));
    int t1 = ( number_.at(2) * pow(2, 23) ) /  pow(2, number_.at(0));
    checkResult(t0 + t1);
}

void Task7::solverType4()
{
    int result = 0;
    int methodA = number_.at(0) *  number_.at(0)  * pow(2, 23) / (100 * pow(2, number_.at(1)) + number_.at(3) + number_.at(4));
    int methodB = number_.at(0) * pow(2, 23) / pow(2, number_.at(1));
    if (methodA > methodB) {
        result = methodA - methodB;
    }
    else {
        result = methodB - methodA;
    }
    checkResult(result);
}

void Task7::checkResult(int result)
{
    if (table->getTypeFromString(table->getTypeTask()) == type1) {
        if (fmod(result, 8) == 0) {
            if (fmod(result, 1024) == 0) {
                number_.push_back(result / 8192);
                table->setSizeType(KBYTE);
            }
        }
        else {
                number_.push_back(result / 8);
                table->setSizeType(BYTE);
            }
    }
    else if (fmod(result, 60) == 0) {
        if (fmod(result, 60) == 0) {
            number_.push_back(result / 3600);
            table->setSizeType(HOUR);
        }
        else {
            number_.push_back(result / 60);
            table->setSizeType(MIN);
        }
    }
    else {
        number_.push_back(result);
        table->setSizeType(SEC);
    }
    table->putTableAnswer(number_);
}

void Task7::createTask(int id, int number, std::string& text, int& answer)
{

}

int Task7::getNumber()
{
    return number_.back();
}