#include "../Utils/AlgorithmDijkstra.h"

void test1()
{
    AdjListGraph g(6);

    g.addEdge(0,1,7);
    g.addEdge(0,2,9);
    g.addEdge(0,5,14);

    g.addEdge(1,0,7);
    g.addEdge(1,2,10);
    g.addEdge(1,3,15);
    // 2
    g.addEdge(2,0,9);
    g.addEdge(2,1,10);
    g.addEdge(2,3,11);
    g.addEdge(2,5,2);
    // 3
    g.addEdge(3,1,15);
    g.addEdge(3,2,11);
    g.addEdge(3,4,6);
    // 4
    g.addEdge(4,3,6);
    g.addEdge(4,5,9);
    // 5
    g.addEdge(5,0,14);
    g.addEdge(5,2,2);
    g.addEdge(5,4,9);

    g.print();

    AlgorithmDijkstra sp(&g);
    auto path = sp.path(0, 4);
    std::cout << "Path: ";
    std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "Path cost: " << sp.path_size(0, 4) << std::endl;
}

