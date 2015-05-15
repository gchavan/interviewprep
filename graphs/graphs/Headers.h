#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <list>
#include <map>
#include <set>
using namespace std;

class vertex;
class edge
{
public:
    edge(shared_ptr<vertex> neighbor, float weight) :
        neighbor(neighbor),
        weight(weight)
    {}

    float weight;

    shared_ptr<vertex> neighbor;
};

class vertex
{
public:
    vertex(string label) :
        visited(false),
        label(label),
        discoverTime(0),
        finishTime(0)
    {}

    bool visited;
    string label;
    int discoverTime;
    int finishTime;

    vector<shared_ptr<edge>> neighbors;

    void AddNeighbor(shared_ptr<vertex> neighbor, float weight = 0)
    {
        neighbors.push_back(make_shared<edge>(neighbor, weight));
    }

    void PrintDFS()
    {
        if (visited)
            return;

        visited = true;
        cout << label.c_str() << " ";
        for each (auto e in neighbors)
        {
            e->neighbor->PrintDFS();
        }
    }
};

class Graph
{
public:
    void BuildGraph();
    void Print();

    void PrintBfs();
    void PrintBfs(shared_ptr<vertex> node);

    void PrintBuildOrder();
    void PrintBuildOrder(shared_ptr<vertex> node, list<shared_ptr<vertex>>& chain);

    void CheckIfCycle();
    bool CheckIfCycle(shared_ptr<vertex> begin, shared_ptr<vertex> curr);

    void DijkstrasAlgo();

private:
    vector<shared_ptr<vertex>> nodes;

    shared_ptr<vertex> source;
    shared_ptr<vertex> destination;

    int time;

    void ResetVisitedFlag();
};
