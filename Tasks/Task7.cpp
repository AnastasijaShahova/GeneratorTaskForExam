#include "Task7.h"

Task7::Task7(int num)
{
    table = std::make_unique<DataTask>(num);
}

void Task7::solutionTask(Type type)
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

void Task7::solverType1()
{

}

void Task7::solverType2()
{

}

void Task7::solverType3()
{

}

void Task7::solverType4()
{

}