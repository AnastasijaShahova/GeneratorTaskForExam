#include "Task7.h"





Task7::Task7(int num)
{
    table = std::make_unique<DataTask>(num);
}

void Task7::solutionTask(Type type)
{
    switch (type) {
        //хранение изображений
        case type1:
        {
            //проверка на то, чтобы все было в степенях двойки
            std::vector<int> limitVec = { 1024, 1024, 512 };
            genRand(3, limitVec);
            solverType1();
            break;
        }
        //хранение звук файлов
        case type2:
        {
            std::vector<int> limitVec = { 100, 64, 512 };
            genRand(3, limitVec);
            solverType2();
            break;
        }
        //определение времени перадачи
        case type3:
        {
            std::vector<int> limitVec = { 20, 15, 12, 1024 };
            genRand(4, limitVec);
            solverType3();
            break;
        }
        //сравнение двух способов
        case type4:
        {
            std::vector<int> limitVec = { 20, 20, 80, 25, 10 };
            genRand(5, limitVec);
            solverType4();
            break;
        }
        default:
            break;
    }
}

void Task7::solverType1()
{
    int result = number_.at(0) * number_.at(1) * searchBit(number_.at(2));
}

// сделать более гибким под типы
void Task7::solverType2()
{
    //перевести в биты
    int byte = number_.at(1) / 8;
    int result = (number_.at(2) * pow(2, 20)) / (byte * number_.at(0) * 1000);
}

void Task7::solverType3()
{
    //здесь нужно перевести все в биты
    int t0 = ( number_.at(3) * pow(2, 20) ) /  pow(2, number_.at(0));
    int t1 = ( number_.at(2) * pow(2, 23) ) /  pow(2, number_.at(0));
    int result = t0 + t1;
}

void Task7::solverType4()
{
    //перевести только первое число в бит
    int methodA = number_.at(0) *  number_.at(0)  * pow(2, 23) / (100 * pow(2, number_.at(1)) + number_.at(3) + number_.at(4);
    int methodB = number_.at(0) * pow(2, 23) / pow(2, number_.at(1);
    if (methodA > methodB) {
        int reuslt = methodA - methodB;
    }
    else {
        int reuslt = methodB - methodA;
    }

}

void Task7::checkType()
{

}

//написать метод перевода в системы счисления