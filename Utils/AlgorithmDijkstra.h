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

class AdjListGraph
{
public:
    AdjListGraph() {}
    AdjListGraph(int numVert);
    ~AdjListGraph() { }

    int V() const { return numVertex; }
    int E() const { return numEdge; }

    bool adjacent(int x, int y) const;
    std::vector<GraphAttributes> neighbors(int x) const;

    void addEdge(int x, int y);
    void addEdge(int x, int y, int w);
    void deleteEdge(int x, int y);

    int getNodeValue(int x) const;
    void setNodeValue(int x, int value);

    int getEdgeValue(int x, int y);
    void setEdgeValue(int x, int y, int w);
    void print();

private:
    int numVertex;
    int numEdge;
    std::vector<std::vector<GraphAttributes>> adjacencyList;
    std::vector<int> vertices; // store nodes values
};

class AlgorithmDijkstra
{
public:
    AlgorithmDijkstra(AdjListGraph *_g) : g(_g) {}
    std::vector<int> path(int source, int target);
    int path_size(int source, int target);

private:
    AdjListGraph *g;
    std::vector<int> min_distance;
    std::vector<int> previous; // store history of visiting, helps to restore the shortest path
    std::vector<int> _path; // store shortest path
};

#endif //UNTITLED5_ALGORITHMDIJKSTRA_H