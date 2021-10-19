#include "Task11.h"
#include <math.h>

#define BIT "битах"
#define BYTE "байтах"
#define MBYTE "мегабайтах"
#define KBYTE "килобайтах"

Task11::Task11(int num)
{
    table->initCurrentDataTask(num);
}

void Task11::genRand(int kol)
{

    RandomGenerator<1, 500 > generator;
    for(int i = 0; i < kol ; ++i)
    {
        Distribution gen;
        number_.push_back(gen.random(1,100).Mt19937());
    }

}


void Task11::solutionTask(Type type)
{
    switch (type) {
        case type1:
        {
            genRand(2);
            solverType1();
            break;
        }
        case type2:
        {
            genRand(3);
            solverType2();
            break;
        }
        case type3:
        {
            genRand(3);
            solverType3();
            break;
        }
        case type4:
        {
            genRand(4);
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

DataTask Task11::getTable()
{
    return *table;
}





