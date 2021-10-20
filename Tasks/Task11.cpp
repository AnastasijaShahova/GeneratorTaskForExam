#include "Task11.h"
#include <math.h>

Task11::Task11(int num)
{
    table = std::make_unique<DataTask>(num);
}

void Task11::solutionTask(Type type)
{
    switch (type) {
        case type1:
        {
            std::vector<int> limitVec = { 700, 500 };
            genRand(2, limitVec);
            if (number_.front() < number_.back()) {
                std::swap(number_[0], number_[1]);
            }
            solverType1();
            break;
        }
        case type2:
        {
            std::vector<int> limitVec = { 10, 33, 400 };
            genRand(3, limitVec);
            solverType2();
            break;
        }
        case type3:
        {
            std::vector<int> limitVec = { 50, 11, 150 };
            genRand(3, limitVec);
            solverType3();
            break;
        }
        case type4:
        {
            std::vector<int> limitVec = { 20, 15, 300, 2000 };
            genRand(4, limitVec);
            solverType4();
            break;
        }
        default:
            break;
    }
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
            table->setSizeType(KBYTE);
        }
        else {
            number_.push_back(result / 8);
            table->setSizeType(BYTE);
        }
    }
    else {
        number_.push_back(result);
        table->setSizeType(BIT);
    }
    table->putTableAnswer(table->getTypeFromString(table->getTypeTask()), number_);
}

void Task11::solverType1()
{
    checkBit(getResult((number_.at(1)), number_.at(0)));
}

void Task11::solverType2()
{
    int count = 10 + number_.at(1);

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





