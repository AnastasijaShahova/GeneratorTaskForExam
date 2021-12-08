#include <iostream>
#include "Tasks/Task11.h"
#include "Tasks/Task7.h"
#include "Tasks/Task1.h"
#include "Utils/AlgorithmDijkstra.h"
#include "Utils/GenerateMatrix.h"

int main() {

        //генерируется рандомное число,потом по этому числу определяется тип задания
//        Task11 task(4);
//        task.solutionTask(type2);

//        Task7 task7(6);
//        task7.solutionTask(type2);

//Task1 task1(6,7);
//task1.solutionTask(type1);

        GenerateMatrix gen(6);
        gen.randomGenerateDirectedGraph( 0,47);
        AlgorithmDijkstra sp(&gen.getG());
        gen.getG().print();
                auto path = sp.path(1, 0);
                std::cout << "Path cost: " << sp.pathSize(1, 0) << std::endl;
    return 0;
}
