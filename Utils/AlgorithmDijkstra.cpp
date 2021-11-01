#include "AlgorithmDijkstra.h"

MatrixGraph::MatrixGraph(int numVert) : numVertex(numVert), numEdge(0)
{
    matrix.reserve(numVertex);
    for (int i = 0; i < numVertex; i++)
    {
        matrix.push_back(std::vector<int>());
        matrix[i].reserve(numVertex);
        for (int j = 0; j < numVertex; j++)
        {
            matrix[i].push_back(0); // initialize by zero
        }
    }
}

bool MatrixGraph::adjacent(int x, int y) const
{
    assert(x >= 0 || y >= 0);
    return matrix[x][y] != 0.0;
}

std::vector<GraphAttributes> MatrixGraph::neighbors(int x) const
{
    assert(x >= 0);
    std::vector<GraphAttributes> nbrs;
    for (int i = 0; i < numVertex; i++)
        if (matrix[x][i] != 0)
            nbrs.push_back(GraphAttributes(i,matrix[x][i]));
        return nbrs;
}

void MatrixGraph::addEdge(int x, int y)
{
    assert(x >= 0 || y >= 0);
    addEdge(x,y,0);
}

void MatrixGraph::addEdge(int x, int y, int w)
{
    assert(x >= 0 || y >= 0);
    if (matrix[x][y] == 0.0)
        numEdge++;
    matrix[x][y] = w;
}

void MatrixGraph::deleteEdge(int x, int y)
{
    assert(x >= 0 || y >= 0);
    if (matrix[x][y] != 0)
        numEdge--;
    matrix[x][y] = 0;
}

int MatrixGraph::getEdgeValue(int x, int y)
{
    assert(x >= 0 || y >= 0);
    return matrix[x][y];
}

void MatrixGraph::setEdgeValue(int x, int y, int w)
{
    assert(x >= 0 || y >= 0 || w >= 0);
    matrix[x][y] = w;
}

int MatrixGraph::getNodeValue(int x) const
{
    assert(x >= 0);
    return vertices[x];
}

void MatrixGraph::setNodeValue(int x, int value)
{
    assert(x >= 0);
    vertices[x] = value;
}

void MatrixGraph::print()
{
    std::cout << "Matrix-based graph\n";
    std::cout << "Number of vertices: " << numVertex << std::endl;
    std::cout << "Number of edges: " << numEdge << std::endl;
    std::cout << "   ";
    for (int i = 0; i < numVertex; i++)
    {
        std::cout.width(3);
        std::cout << "V" << i ;
    }
    std::cout <<  std::endl;
    for (int i = 0; i < numVertex; i++)
    {
        std::cout << "V" << i << ": ";
        for (int j = 0; j < numVertex; j++)
        {
            std::cout.width(3);
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Calculate the cost as sum of distances between path vertices
int AlgorithmDijkstra::pathSize(int source, int target)
{
    path(source, target);
    int sum = 0;

    for (int i = 0; i < _path.size() - 1; i++)
    {
        sum += g->getEdgeValue(_path[i], _path[i + 1]);
    }
    if (sum == 0) return -1;
    return sum;
}

std::vector<int> AlgorithmDijkstra::path(int source, int target)
{
    int n = g->getV(); // number of vertices
    minDistance.clear();
    minDistance.resize(n, std::numeric_limits<double>::infinity()); // set distances to infinity
    minDistance[source] = 0;

    previous.clear();
    previous.resize(n, -1); // store vertices to reproduce the shortest path
    _path.clear();

    std::priority_queue< std::pair<int, int>,
    std::vector<std::pair<int, int> >,
    std::greater<std::pair<int, int> > > vertex_queue; // min-heap
    vertex_queue.push(std::make_pair(minDistance[source], source)); // put the start vertice to queue

    // iterate until queue is empty
    while (!vertex_queue.empty())
    {
        int dist = vertex_queue.top().first; // distance
        int u = vertex_queue.top().second; // vertex
        vertex_queue.pop();

        if (dist < minDistance[u])
            continue;

        const std::vector<GraphAttributes> &neighbors = g->neighbors(u); // get all neighbors of "u"
        for (auto &neighbor : neighbors) // iterate over neighbors
        {
            int v = neighbor.vertex;
            int weight = neighbor.weight;
            int distance_through_u = dist + weight; // calcualate the cost
            if (distance_through_u < minDistance[v])
            {
                minDistance[v] = distance_through_u;
                previous[v] = u;
                vertex_queue.push(std::make_pair(minDistance[v], v)); // push on top of heap the most "effective" vertex
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