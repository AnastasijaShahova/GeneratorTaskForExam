#include "Task1.h"

Task1::Task1(int graphSize)
{
    matrix = std::make_unique<GenerateMatrix>(graphSize);
}

void Task1::solutionTask(Type type)
{
    switch (type) {
        case type1:
        {
            std::vector<int> limitVec = { 0, matrix->getG().getV() };
            //генерируем числа от какой вершины до какой
            genRand(2, limitVec, number_);
            matrix->randomGenerateUndirectedGraph( 0, 15);
            solverType1();
            break;
        }
        case type2:
        {
            std::vector<int> limitVec = { 0, matrix->getG().getV() };
            genRand(2, limitVec, number_);
            matrix->randomGenerateUndirectedGraph( 0,47);
            solverType2();
            break;
        }
        case type3:
        {
            std::vector<int> limitVec = { 0, matrix->getG().getV() };
            genRand(2, limitVec, number_);
            matrix->randomGenerateUndirectedGraph( 0,47);
            solverType3();
            break;
        }
        default:
            break;
    }
}

void Task1::solverType1()
{
    AlgorithmDijkstra sp(&matrix->getG());
    auto path = sp.path(number_.at(0), number_.at(1));
    std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "Path cost: " << sp.pathSize(number_.at(0), number_.at(1)) << std::endl;
}

void Task1::solverType2()
{

}

void Task1::solverType3()
{

}