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

/* Store the end of the edge and weight of the edge */
template <typename Wtype>
struct GraphAttributes
{
    int vertex;
    Wtype weight;
    GraphAttributes(int v) : vertex(v) {}
    GraphAttributes(int v, Wtype w) : vertex(v), weight(w) {}
};


/* Abstract graph class provides general interface for derived list
 * and matrix based classes. Template's argument "vertex_type" is used
 * as node's value (number, string), "WType" is used as edge distance (double)
*/
template <typename vertex_type, typename WType>
class IGraph
{
    IGraph(const IGraph&) = delete;  // protect copy constructor
    void operator=(const IGraph&) = delete; // protect assignment

public:
    virtual ~IGraph() {}
    IGraph() {}

    virtual int E() const = 0; // returns the number of edges in the graph
    virtual int V() const = 0; // returns the number of vertices in the graph

    virtual std::vector< GraphAttributes<WType> > neighbors(int x) const =0; // return list of all vertices which have edge with "x"
    virtual bool adjacent(int x, int y) const =0; // tests whether there is an edge from node "x" to node "y"

    virtual void deleteEdge(int x, int y) =0; // removes the edge from x to y, if it is there
    virtual void addEdge(int x, int y) =0; // adds to graph the edge from x to y, if it is not there

    virtual void set_node_value(int x, vertex_type value) =0; // sets the value associated with the node x to a
    virtual vertex_type get_node_value(int x) const =0; // returns the value associated with the node x

    virtual void set_edge_value(int x, int y, WType v) =0; // sets the value associated to the edge (x,y) to v
    virtual WType get_edge_value(int x, int y) =0; // returns the value associated to the edge (x,y)
};

/* Adjacency list-based implementation of graph ADT */
template <typename vertex_type, typename weight_type>
class AdjListGraph : public IGraph<vertex_type, weight_type>
{
            int numVertex, numEdge;
            std::vector< std::vector<GraphAttributes<weight_type> > > AdjacencyList;
            std::vector<vertex_type> vertices; // store nodes values

        public:
            AdjListGraph() {}
            AdjListGraph(int numVert) : numVertex(numVert), numEdge(0)
            {
                vertices.reserve(numVertex);
                AdjacencyList.reserve(numVertex);

                for (int i = 0; i < numVertex; i++)
                {
                    AdjacencyList.push_back(std::vector< GraphAttributes<weight_type> >());
                    AdjacencyList[i].reserve(numVertex);
                }
            }
            ~AdjListGraph() { }

            int V() const { return numVertex; }
            int E() const { return numEdge; }

            bool adjacent(int x, int y) const
            {
                // return true if adjacency list for "x" node contains "y" node
                return std::find_if(AdjacencyList[x].begin(), AdjacencyList[x].end(), [&y](GraphAttributes<weight_type> elem){
                    return elem.vertex == y;
                }) != AdjacencyList[x].end();
            }

            std::vector<GraphAttributes<weight_type> > neighbors(int x) const
            {
                return AdjacencyList[x];
            }

            void addEdge(int x, int y)
            {
                assert(x >= 0 || y >= 0);
                addEdge(x,y,weight_type()); // cannot predict default value for "WType", use possible default constructor
                // it's assumed WType = double, it's just 0.0
            }

            void addEdge(int x, int y, weight_type w)
            {
                assert(x >= 0 || y >= 0 || w >= 0);
                for (auto &it : AdjacencyList[x])
                {
                    if (it.vertex == y)
                    {
                        it.weight = w;
                        return;
                    }
                }
                numEdge++;
                AdjacencyList[x].push_back(GraphAttributes<weight_type>(y, w));
            }

            void deleteEdge(int x, int y)
            {
                assert(x >= 0 || y >= 0);
                // look for the "y" vertex in the adj list
                auto nit = std::find_if(AdjacencyList[x].begin(), AdjacencyList[x].end(), [&y](GraphAttributes<weight_type> elem){
                    return elem.vertex == y;
                });
                if (nit != AdjacencyList[x].end()) // if find - erase
                    {
                    numEdge--;
                    AdjacencyList[x].erase(nit);
                    }
            }

            vertex_type get_node_value(int x) const
            {
                assert(x >= 0);
                return vertices[x];
            }

            void set_node_value(int x, vertex_type value)
            {
                if (x >= 0) return;
                vertices[x] = value;
            }

            weight_type get_edge_value(int x, int y)
            {
                assert(x >= 0 || y >= 0);
                auto nit = std::find_if(AdjacencyList[x].begin(), AdjacencyList[x].end(), [&y](GraphAttributes<weight_type> elem){
                    return elem.vertex == y;
                });
                if (nit != AdjacencyList[x].end())
                    return nit->weight;
                return weight_type(); // return 0.0 if there's no edge
            }

            void set_edge_value(int x, int y, weight_type w)
            {
                assert(x >= 0 || y >= 0);
                auto nit = std::find_if(AdjacencyList[x].begin(), AdjacencyList[x].end(), [&y](GraphAttributes<weight_type> elem){
                    return elem.vertex == y;
                });
                if (nit != AdjacencyList[x].end())
                    nit->weight = w;
            }

            void print()
            {
                std::cout << "Adjacency list graph\n";
                std::cout << "Number of vertices: " << numVertex << std::endl;
                std::cout << "Number of edges: " << numEdge << std::endl;
                for (int i = 0; i < numVertex; i++)
                {
                    std::cout << "V" << i << ": ";
                    for (auto &elem : AdjacencyList[i])
                        std::cout << "[" << elem.vertex << ", w" << elem.weight << "] ";
                    std::cout << std::endl;
                }
            }
        };

/* Class containing implementation of Dijkstra algorithm */
template <typename vertex_type, typename weight_type>
class AlgorithmDijkstra
{
    IGraph<vertex_type, weight_type> *g;
    std::vector<weight_type> min_distance; // store distances from source veritice
    std::vector<int> previous; // store history of visiting, helps to restore the shortest path
    std::vector<int> _path; // store shortest path
public:
    AlgorithmDijkstra(IGraph<vertex_type, weight_type> *_g) : g(_g) {}

    std::vector< int > path(int source, int target)
    {
                int n = g->V(); // number of vertices
                min_distance.clear();
                min_distance.resize(n, std::numeric_limits<double>::infinity()); // set distances to infinity
                min_distance[source] = 0;

                previous.clear();
                previous.resize(n, -1); // store vertices to reproduce the shortest path
                _path.clear();

                std::priority_queue< std::pair<weight_type, int>,
                std::vector<std::pair<weight_type, int> >,
                std::greater<std::pair<weight_type, int> > > vertex_queue; // min-heap
                vertex_queue.push(std::make_pair(min_distance[source], source)); // put the start vertice to queue

                // iterate until queue is empty
                while (!vertex_queue.empty())
                {
                    weight_type dist = vertex_queue.top().first; // distance
                    int u = vertex_queue.top().second; // vertex
                    vertex_queue.pop();

                    if (dist < min_distance[u])
                        continue;

                    const std::vector<GraphAttributes<weight_type>> &neighbors = g->neighbors(u); // get all neighbors of "u"
                    for (auto &neighbor : neighbors) // iterate over neighbors
                        {
                        int v = neighbor.vertex;
                        weight_type weight = neighbor.weight;
                        weight_type distance_through_u = dist + weight; // calcualate the cost
                        if (distance_through_u < min_distance[v])
                        {
                            min_distance[v] = distance_through_u;
                            previous[v] = u;
                            vertex_queue.push(std::make_pair(min_distance[v], v)); // push on top of heap the most "effective" vertex
                        }
                        }
                }
                // retrieve the path vertices
                int targetVertex = target;
                for (; target != -1; target = previous[target])
                {
                    _path.push_back(target);
                }
                std::reverse(_path.begin(), _path.end()); // set correct order for path vertices
                if (_path.size() < 2)
                    std::cout << "There's no path to " << targetVertex << ".\n";
                return _path;
    }

            // Calculate the cost as sum of distances between path vertices
            weight_type path_size(int source, int target)
            {
                path(source, target);
                weight_type sum = 0;

                for (int i = 0; i < _path.size() - 1; i++)
                {
                    sum += g->get_edge_value(_path[i], _path[i+1]);
                }
                if (sum == 0) return -1;
                return sum;
            }
};

#endif //UNTITLED5_ALGORITHMDIJKSTRA_H
