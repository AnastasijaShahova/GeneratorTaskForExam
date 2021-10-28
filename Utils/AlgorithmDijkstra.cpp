#include "AlgorithmDijkstra.h"

AdjListGraph::AdjListGraph(int numVert) : numVertex(numVert), numEdge(0)
{
    vertices.reserve(numVertex);
    adjacencyList.reserve(numVertex);

    for (int i = 0; i < numVertex; i++)
    {
        adjacencyList.push_back(std::vector< GraphAttributes>());
        adjacencyList[i].reserve(numVertex);
    }

}

bool AdjListGraph::adjacent(int x, int y) const
{
    // return true if adjacency list for "x" node contains "y" node
    return std::find_if(adjacencyList[x].begin(), adjacencyList[x].end(), [&y](GraphAttributes elem){
        return elem.vertex == y;
    }) != adjacencyList[x].end();
}

std::vector<GraphAttributes> AdjListGraph::neighbors(int x) const
{
    return adjacencyList[x];
}

void AdjListGraph::addEdge(int x, int y)
{
    assert(x >= 0 || y >= 0);
    addEdge(x,y, 0);
}

void AdjListGraph::addEdge(int x, int y, int w)
{
    assert(x >= 0 || y >= 0 || w >= 0);
    for (auto &it : adjacencyList[x])
    {
        if (it.vertex == y)
        {
            it.weight = w;
            return;
        }
    }
    numEdge++;
    adjacencyList[x].push_back(GraphAttributes(y, w));
}

void AdjListGraph::deleteEdge(int x, int y)
{
    assert(x >= 0 || y >= 0);
    // look for the "y" vertex in the adj list
    auto nit = std::find_if(adjacencyList[x].begin(), adjacencyList[x].end(), [&y](GraphAttributes elem){
        return elem.vertex == y;
    });
    if (nit != adjacencyList[x].end()) // if find - erase
    {
        numEdge--;
        adjacencyList[x].erase(nit);
    }
}

int AdjListGraph::get_node_value(int x) const
{
    assert(x >= 0);
    return vertices[x];
}

void AdjListGraph::set_node_value(int x, int value)
{
    if (x >= 0) return;
    vertices[x] = value;
}

int AdjListGraph::get_edge_value(int x, int y)
{
    assert(x >= 0 || y >= 0);
    auto nit = std::find_if(adjacencyList[x].begin(), adjacencyList[x].end(), [&y](GraphAttributes elem){
        return elem.vertex == y;
    });
    if (nit != adjacencyList[x].end())
        return nit->weight;
    return 0; // return 0 if there's no edge
}

void AdjListGraph::set_edge_value(int x, int y, int w)
{
    assert(x >= 0 || y >= 0);
    auto nit = std::find_if(adjacencyList[x].begin(), adjacencyList[x].end(), [&y](GraphAttributes elem){
        return elem.vertex == y;
    });
    if (nit != adjacencyList[x].end())
        nit->weight = w;
}

void AdjListGraph::print()
{
    std::cout << "Adjacency list graph\n";
    std::cout << "Number of vertices: " << numVertex << std::endl;
    std::cout << "Number of edges: " << numEdge << std::endl;
    for (int i = 0; i < numVertex; i++)
    {
        std::cout << "V" << i << ": ";
        for (auto &elem : adjacencyList[i])
            std::cout << "[" << elem.vertex << ", w" << elem.weight << "] ";
        std::cout << std::endl;
    }
}

// Calculate the cost as sum of distances between path vertices
int AlgorithmDijkstra::path_size(int source, int target)
{
    path(source, target);
    int sum = 0;

    for (int i = 0; i < _path.size() - 1; i++)
    {
        sum += g->get_edge_value(_path[i], _path[i+1]);
    }
    if (sum == 0) return -1;
    return sum;
}

std::vector<int> AlgorithmDijkstra::path(int source, int target)
{
    int n = g->V(); // number of vertices
    min_distance.clear();
    min_distance.resize(n, std::numeric_limits<double>::infinity()); // set distances to infinity
    min_distance[source] = 0;

    previous.clear();
    previous.resize(n, -1); // store vertices to reproduce the shortest path
    _path.clear();

    std::priority_queue< std::pair<int, int>,
    std::vector<std::pair<int, int> >,
    std::greater<std::pair<int, int> > > vertex_queue; // min-heap
    vertex_queue.push(std::make_pair(min_distance[source], source)); // put the start vertice to queue

    // iterate until queue is empty
    while (!vertex_queue.empty())
    {
        int dist = vertex_queue.top().first; // distance
        int u = vertex_queue.top().second; // vertex
        vertex_queue.pop();

        if (dist < min_distance[u])
            continue;

        const std::vector<GraphAttributes> &neighbors = g->neighbors(u); // get all neighbors of "u"
        for (auto &neighbor : neighbors) // iterate over neighbors
            {
            int v = neighbor.vertex;
            int weight = neighbor.weight;
            int distance_through_u = dist + weight; // calcualate the cost
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