#include "Headers.h"

void Graph::BuildGraph()
{
    time = 0;

    /*
    // Check Build Order
    auto undershorts = make_shared<vertex>("undershorts");
    auto pants = make_shared<vertex>("pants");
    auto belt = make_shared<vertex>("belt");
    auto shirt = make_shared<vertex>("shirt");
    auto tie = make_shared<vertex>("tie");
    auto jacket = make_shared<vertex>("jacket");
    auto socks = make_shared<vertex>("socks");
    auto shoes = make_shared<vertex>("shoes");
    auto watch = make_shared<vertex>("watch");

    nodes.push_back(undershorts);
    nodes.push_back(shirt);
    nodes.push_back(tie);
    nodes.push_back(jacket);
    nodes.push_back(belt);
    nodes.push_back(watch);
    nodes.push_back(pants);
    nodes.push_back(socks);
    nodes.push_back(shoes);    

    undershorts->AddNeighbor(pants, 4);
    undershorts->AddNeighbor(shoes, 2);

    pants->AddNeighbor(belt, 5);
    pants->AddNeighbor(shoes, 10);

    belt->AddNeighbor(jacket, 3);

    shirt->AddNeighbor(belt, 11);
    shirt->AddNeighbor(tie, 11);

    tie->AddNeighbor(jacket, 4);

    socks->AddNeighbor(shoes, 4);
    */

    auto a = make_shared<vertex>("a");
    auto b = make_shared<vertex>("b");
    auto c = make_shared<vertex>("c");
    auto d = make_shared<vertex>("d");
    auto e = make_shared<vertex>("e");
    auto f = make_shared<vertex>("f");

    nodes.push_back(a);
    nodes.push_back(b);
    nodes.push_back(c);
    nodes.push_back(d);
    nodes.push_back(e);
    nodes.push_back(f);

    a->AddNeighbor(b, 4);
    a->AddNeighbor(c, 2);

    b->AddNeighbor(c, 5);
    b->AddNeighbor(d, 10);

    c->AddNeighbor(e, 3);

    d->AddNeighbor(f, 11);

    e->AddNeighbor(d, 4);

    source = a;
    destination = f;
}

void Graph::ResetVisitedFlag()
{
    for each (auto node in nodes)
    {
        node->visited = false;
    }
}

void Graph::PrintBfs()
{
    cout << "print breadth first" << endl;

    ResetVisitedFlag();    

    for each(auto node in nodes)
    {
        PrintBfs(node);
    }

    cout << endl;
}

void Graph::PrintBfs(shared_ptr<vertex> node)
{
    if (!node || node->visited)
        return;

    queue<shared_ptr<vertex>> q;
    q.push(node);

    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            auto n = q.front();
            q.pop();

            if (!n->visited)
            {
                n->visited = true;
                cout << n->label.c_str() << " ";

                for (auto i : n->neighbors)
                {
                    q.push(i->neighbor);
                }
            }
        }
    }
}

void Graph::Print()
{
    for each (auto node in nodes)
    {
        cout << node->label.c_str() << " ==> ";
        for each (auto neighbor in node->neighbors)
        {
            cout << "(" << neighbor->neighbor->label.c_str() << ")" << "  ";
        }
        cout << endl;
    }
}

void Graph::PrintBuildOrder()
{
    cout << endl << "Printing Depth First Order..." << endl;
    ResetVisitedFlag();

    list<shared_ptr<vertex>> chain;
    for each (auto node in nodes)
    {
        if (!node->visited)
            PrintBuildOrder(node, chain);
    }
    cout << endl;

    /*for each (auto node in nodes)
    {
        cout << node->discoverTime << "/" << node->finishTime << " ";
    }
    cout << endl;*/

    for each (auto node in chain)
    {
        cout << node->label.c_str() << " ";
    }
    cout << endl;
}

void Graph::PrintBuildOrder(shared_ptr<vertex> node, list<shared_ptr<vertex>>& chain)
{
    // cout << node->label.c_str() << " ";
    node->visited = true;

    time++;
    node->discoverTime = time;

    for each(auto i in node->neighbors)
    {
        if (!i->neighbor->visited)
        {
            PrintBuildOrder(i->neighbor, chain);
        }
    }

    time++;
    node->finishTime = time;

    chain.push_front(node);
}

void Graph::CheckIfCycle()
{
    for each (auto node in nodes)
    {
        if (CheckIfCycle(node, node))
        {
            cout << "There is a cycle." << endl;
            return;
        }
    }

    cout << "There is NO cycle." << endl;
}

bool Graph::CheckIfCycle(shared_ptr<vertex> begin, shared_ptr<vertex> curr)
{
    for each (auto edge in curr->neighbors)
    {
        if (edge->neighbor == begin)
        {
            return true;
        }

        if (!edge->neighbor->visited)
        {
            edge->neighbor->visited = true;
            if (CheckIfCycle(begin, edge->neighbor))
            {
                return true;
            }
            edge->neighbor->visited = false;
        }
    }

    return false;
}

struct classcomp
{
    bool operator() (pair<shared_ptr<vertex>, int> lhs, pair<shared_ptr<vertex>, int> rhs) const
    {
        return lhs.second > rhs.second;
    }
};

void Graph::DijkstrasAlgo()
{
    int vertices = nodes.size();
    map<shared_ptr<vertex>, int> distance;
    map<shared_ptr<vertex>, shared_ptr<vertex>> previous;

    priority_queue<pair<shared_ptr<vertex>, int>, vector<pair<shared_ptr<vertex>, int>>, classcomp> q;

    for (auto node: nodes)
    {
        if (node == source)
            distance[node] = 0;
        else
            distance[node] = INT_MAX;

        previous[node] = nullptr;

        q.push(make_pair(node, distance[node]));
    }

    while (!q.empty())
    {
        auto min = q.top();
        q.pop();

        auto u = min.first;
        for (auto neighbor : u->neighbors)
        {
            auto v = neighbor->neighbor;
            int alt = distance[u] + static_cast<int>(neighbor->weight);
            if (alt < distance[v])
            {
                distance[v] = alt;
                previous[v] = u;
            }
        }
    }

    for (auto node : nodes)
    {
        cout << node->label.c_str() << " ==> "
            << (previous[node] ? previous[node]->label.c_str() : "nullptr") << " , "
            << distance[node] << endl;
    }

    auto parent = destination;
    while (parent)
    {
        cout << parent->label.c_str();

        if (previous[parent])
            cout << " ==> ";
        parent = previous[parent];
    }
    cout << endl;
}