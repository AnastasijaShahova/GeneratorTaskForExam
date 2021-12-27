#include <thread>
#include "Tasks/Task11.h"
#include "Tasks/Task7.h"
#include "Tasks/Task1.h"
#include "Utils/AlgorithmDijkstra.h"
#include "Rest/TaskService.h"
#include "Rest/ServiceSettingFactory.h"


using namespace std;
using namespace restbed;

int main() {

//        Task7 task7(6);
//        task7.solutionTask(type2);

//Task1 task1(6,7);
//task1.solutionTask(type1);

//        GenerateMatrix gen(6);
//        gen.randomGenerateDirectedGraph( 0,47);
//        AlgorithmDijkstra sp(&gen.getG());
//        gen.getG().print();
//                auto path = sp.path(1, 0);
//                std::cout << "Path cost: " << sp.pathSize(1, 0) << std::endl;


TaskService calc_service(std::make_shared<ServiceSettingFactory>());
calc_service.start();


return EXIT_SUCCESS;

}
