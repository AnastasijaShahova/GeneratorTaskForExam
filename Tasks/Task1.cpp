#include "Task1.h"

Task1::Task1(int graphSize, int num)
{
    matrix = std::make_unique<GenerateMatrix>(graphSize);
    initializedTable(num);
}

void Task1::solutionTask(Type type)
{
    switch (type) {
        case type1:
        {
            std::vector<int> limitVec = { matrix->getG().getV() - 1, matrix->getG().getV() - 1 };
            //генерируем числа от какой вершины до какой
            genRand(2, limitVec, number_);
            matrix->randomGenerateUndirectedGraph( 0, 15);
            matrix->getG().print();
            solverType1();
            break;
        }
        case type2:
        {
            std::vector<int> limitVec = { matrix->getG().getV() - 1, matrix->getG().getV() - 1 };
            genRand(2, limitVec, number_);
            matrix->randomGenerateUndirectedGraph( 0,47);
            matrix->getG().print();
            solverType2();
            break;
        }
        case type3:
        {
            std::vector<int> limitVec = { matrix->getG().getV() - 1, matrix->getG().getV() - 1 };
            genRand(2, limitVec, number_);
            matrix->randomGenerateUndirectedGraph( 0,47);
            matrix->getG().print();
            solverType3();
            break;
        }
        default:
            break;
    }
}

int Task1::algorithmD(int number1, int number2)
{
    AlgorithmDijkstra sp(&matrix->getG());
    return sp.pathSize(number1, number2);
}

void Task1::solverType1()
{
    int result = algorithmD(number_.at(0), number_.at(1));
    std::cout << "Path cost: " << result << std::endl;
    checkResult(result);
}

void Task1::solverType2()
{
    int result = algorithmD(number_.at(0), number_.at(1));
    std::cout << "Path cost: " << result << std::endl;
    checkResult(result);
}

void Task1::solverType3()
{
    int result = algorithmD(number_.at(0), number_.at(1));
    std::cout << "Path cost: " << result << std::endl;
    checkResult(result);
}

void Task1::checkResult(int result)
{
    if (result == -1)
    {
        genRand(2, { matrix->getG().getV(),  matrix->getG().getV() }, number_);
        result = algorithmD(number_.at(0), number_.at(1));
        checkResult(result);
    }
    number_.push_back(result);
    table->putTableAnswer(number_);
}