#ifndef UNTITLED5_ALGORITHMDIJKSTRA_H
#define UNTITLED5_ALGORITHMDIJKSTRA_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <limits>
#include <utility>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <random>

struct GraphAttributes
{
    int vertex;
    int weight;
    GraphAttributes(int v) : vertex(v) {}
    GraphAttributes(int v, int w) : vertex(v), weight(w) {}
};

/*t "vertex_type" is used
* as node's value (number, string), "weight_type" is used as edge distance
*/
class IGraph
{
    IGraph(const IGraph&) = delete;  // protect copy constructor
    void operator=(const IGraph&) = delete; // protect assignment

public:
    virtual ~IGraph() {}
    IGraph() {}

    virtual int E() const = 0; // returns the number of edges in the graph
    virtual int V() const = 0; // returns the number of vertices in the graph

    virtual std::vector< GraphAttributes> neighbors(int x) const = 0; // return list of all vertices which have edge with "x"
    virtual bool adjacent(int x, int y) const = 0; // tests whether there is an edge from node "x" to node "y"

    virtual void deleteEdge(int x, int y) = 0; // removes the edge from x to y, if it is there
    virtual void addEdge(int x, int y) = 0; // adds to graph the edge from x to y, if it is not there

    virtual void set_node_value(int x, int value) = 0; // sets the value associated with the node x to a
    virtual int get_node_value(int x) const = 0; // returns the value associated with the node x

    virtual void set_edge_value(int x, int y, int v) = 0; // sets the value associated to the edge (x,y) to v
    virtual int get_edge_value(int x, int y) = 0; // returns the value associated to the edge (x,y)
};

class AdjListGraph : public IGraph
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

    int get_node_value(int x) const;
    void set_node_value(int x, int value);

    int get_edge_value(int x, int y);
    void set_edge_value(int x, int y, int w);
    void print();

private:
    int numVertex;
    int numEdge;
    std::vector< std::vector<GraphAttributes> > adjacencyList;
    std::vector<int> vertices; // store nodes values
};

class AlgorithmDijkstra
{
public:
    AlgorithmDijkstra(IGraph *_g) : g(_g) {}
    std::vector<int> path(int source, int target);
    int path_size(int source, int target);

private:
    IGraph *g;
    std::vector<int> min_distance;
    std::vector<int> previous; // store history of visiting, helps to restore the shortest path
    std::vector<int> _path; // store shortest path
};

#endif //UNTITLED5_ALGORITHMDIJKSTRA_H
