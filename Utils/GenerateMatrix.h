#ifndef UNTITLED5_GENERATEMATRIX_H
#define UNTITLED5_GENERATEMATRIX_H
#include "AlgorithmDijkstra.h"
#include "RandomGenerator.h"

class GenerateMatrix
{
public:
    GenerateMatrix(int graphSize) : matrix_(new MatrixGraph(graphSize)) {}

    void randomGenerateUndirectedGraph(int minDist, int maxDist)
    {
        Distribution generator;

        for (int i = 0; i < matrix_->getV(); ++i) {

            for (int j = 0; j <  matrix_->getV(); j++) {

                int dist = generator.random(minDist, maxDist).Mt19937();
                if (i != j ) {
                    matrix_->addEdge(i, j, dist);
                    matrix_->addEdge(j, i, dist);
                }
                else {
                    matrix_->addEdge(i, j, 0);
                }
            }
        }
    }

    void randomGenerateDirectedGraph(int minDist, int maxDist)
    {
        Distribution generator;
        for (int i = 0; i < matrix_->getV(); ++i) {

            for (int j = 0; j <  matrix_->getV(); j++) {

                int dist = generator.random(minDist, maxDist).Mt19937();
                if (i != j ) {
                    if (i%2 == 0) {
                        matrix_->addEdge(i, j, dist);
                        matrix_->addEdge(j, i, 0);
                    }
                    matrix_->addEdge(j, i, dist);
                }
                else {
                    matrix_->addEdge(i, j, 0);
                }
            }
        }
    }

    MatrixGraph &getG() const
    {
        return *matrix_;
    }

private:

    MatrixGraph *matrix_;
};

#endif //UNTITLED5_GENERATEMATRIX_H
