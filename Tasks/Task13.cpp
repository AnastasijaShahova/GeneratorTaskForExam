#include "Task13.h"


Task13::Task13(int graphSize, int num)
{
    matrix = std::make_unique<GenerateMatrix>(graphSize);
    initializedTable(num);
}

void Task13::solutionTask(Type type)
{
    switch (type) {
        case type1:
        {
            std::vector<int> limitVec = { 0, matrix->getG().getV() };
            //генерируем числа от какой вершины до какой
            genRand(2, limitVec, number_);
            matrix->randomGenerateDirectedGraph( 0, 1);
            solverType1();
            break;
        }
        case type2:
        {
            std::vector<int> limitVec = { 0, matrix->getG().getV() };
            genRand(3, limitVec, number_);
            matrix->randomGenerateDirectedGraph( 0,1);
            solverType2();
            break;
        }
        case type3:
        {
            std::vector<int> limitVec = { 0, matrix->getG().getV() };
            genRand(4, limitVec, number_);
            matrix->randomGenerateDirectedGraph( 0,1);
            solverType3();
            break;
        }
        default:
            break;
    }
}

int Task13::algorithmD(int number1, int number2)
{
    AlgorithmDijkstra sp(&matrix->getG());
    return sp.pathSize(number1, number2);
}

void Task13::solverType1()
{

}

void Task13::solverType2()
{

}

void Task13::solverType3()
{

}