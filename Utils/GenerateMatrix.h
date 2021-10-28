#ifndef UNTITLED5_GENERATEMATRIX_H
#define UNTITLED5_GENERATEMATRIX_H
#include "AlgorithmDijkstra.h"

class GenerateMatrix
{
public:
    GenerateMatrix(double min_dist, double max_dist) : distance_distribution_(min_dist, max_dist) {}

    void randomGenerateUndirectedGraph(int graph_size, double edge_dens, double min_dist, double max_dist)
    {
        AdjListGraph<int, double> g(graph_size);
        std::random_device rd;
        std::mt19937 gen(rd());
        for (int i = 0; i < graph_size; ++i)
        {
            for (int j = 0; j < graph_size; j++)
            {
                if (edge_distribution(gen) <= edge_dens)
                {
                    if (!(g.adjacent(i,j) && g.adjacent(j,i)))
                    {
                        double dist = distance_distribution(gen);
                        g.addEdge(i,j, dist); 
                        g.addEdge(j,i, dist);
                    }
                }
            }
        }

        AlgorithmDijkstra<int,double> sp(&g);
        double sum = 0;
        int count = 0;
        for (int i = 1; i < graph_size; i++)
        {
            int path_len = sp.pathSize(0, i);
            if (path_len != -1)
            {
                sum += path_len;
                count++;
            }
        }
        std::cout << "Average path length: " << sum / count << std::endl;
    }

private:
    std::uniform_real_distribution<> distance_distribution_;
    std::uniform_real_distribution<> edge_distribution_(0.0, 1.0);
};

#endif //UNTITLED5_GENERATEMATRIX_H
