#include "Task16.h"
#include <string>

static  char * CODE_TYPE1= "int main() {"
                           "int s,n;"
                           "s = %1%;"
                           "n = %2%; "
                           "while (  %3%  ) {"
                           "s = s %4% %5% ;"
                           "n = n %6% %7%;"
                           "}"
                           "cout<<%8%<<endl; }";

Task16::Task16(int num)
{
    table = std::make_unique<DataTask>(6);
    vectorId = table->getVectorId(num);
    //    initializedTable(num);
}

int GetRandomNumber(int min, int max)
{
    srand(time(NULL));

    int num = min + rand() % (max - min + 1);

    return num;
}

void Task16::solutionTask(Type type)
{
    switch (type) {
        //
        case type1:
        {
            std::vector<int> limitVec = { 300, 7, 1 , 12, 8 };
            std::vector<int> minVec = { 6, 1, 0, 2,2 };
            genRandMin(5,  limitVec,minVec, number_);
            solverType1();
            break;
        }
        //
        case type2:
        {
            std::vector<int> limitVec = { 10, 33, 400, 3 };
            genRand(5, limitVec, number_);
            solverType2();
            break;
        }
        //
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

void Task16::checkResult(int result)
{
    table->putTableAnswer(number_);
}

void Task16::solverType1()
{


}

void Task16::solverType2()
{

}

void Task16::solverType3()
{

}

void Task16::createTask(int id, int number, std::string& text, int& answer)
{
    table = std::make_unique<DataTask>(number, id);
    number_.clear();
    solutionTask(table->getTypeFromString(table->getTypeTask()));
    answer = number_.back();
    std::string textTaskString = table->getTextTask();
    // сгенерирована строка с заданием
    text = textTaskString + (StrFormat(CODE_TYPE1) % number_.at(0) % number_.at(1) % number_.at(2) % number_.at(3) % number_.at(4) % number_.at(5)).str();
}

int Task16::getNumber()
{
    return number_.back();
}
