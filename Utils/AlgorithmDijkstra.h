#ifndef UNTITLED5_ALGORITHMDIJKSTRA_H
#define UNTITLED5_ALGORITHMDIJKSTRA_H

#include <iostream>
#include <vector>
#include <queue>

struct GraphAttributes
{
    int vertex;
    int weight;
    GraphAttributes(int v) : vertex(v) {}
    GraphAttributes(int v, int w) : vertex(v), weight(w) {}
};

class MatrixGraph
{
public:
    MatrixGraph(int numVert);
    ~MatrixGraph() {}

    int getV() const { return numVertex; }
    int getE() const { return numEdge; }

    bool adjacent(int x, int y) const;

    std::vector<GraphAttributes> neighbors(int x) const;

    void addEdge(int x, int y);
    void addEdge(int x, int y, int w);
    void deleteEdge(int x, int y);

    int getEdgeValue(int x, int y);
    void setEdgeValue(int x, int y, int w);

    int getNodeValue(int x) const;
    void setNodeValue(int x, int value);
    void print();

private:
    int numVertex;
    int numEdge;
    std::vector<std::vector<int>> matrix;
    std::vector<int> vertices;
};

class AlgorithmDijkstra
{
public:
    AlgorithmDijkstra(MatrixGraph *_g) : g(_g) {}
    std::vector<int> path(int source, int target);
    int pathSize(int source, int target);

private:
    MatrixGraph *g;
    std::vector<double> minDistance;
    std::vector<int> previous; // store history of visiting, helps to restore the shortest path
    std::vector<int> _path; // store shortest path
};

#endif //UNTITLED5_ALGORITHMDIJKSTRA_H