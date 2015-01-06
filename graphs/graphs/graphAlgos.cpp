#include "Headers.h"

void Graph::BuildGraph()
{
    time = 0;

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
    //  undershorts->AddNeighbor(shirt, 2);

    pants->AddNeighbor(belt, 5);
    pants->AddNeighbor(shoes, 10);

    belt->AddNeighbor(jacket, 3);

    shirt->AddNeighbor(belt, 11);
    shirt->AddNeighbor(tie, 11);

    tie->AddNeighbor(jacket, 4);

    socks->AddNeighbor(shoes, 4);

    /*auto a = make_shared<vertex>('a');
    auto b = make_shared<vertex>('b');
    auto c = make_shared<vertex>('c');
    auto d = make_shared<vertex>('d');
    auto e = make_shared<vertex>('e');
    auto f = make_shared<vertex>('f');

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

    e->AddNeighbor(d, 4);*/
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

void Graph::PrintDfs()
{
    cout << endl << "Printing Depth First Order..." << endl;
    ResetVisitedFlag();

    list<shared_ptr<vertex>> chain;
    for each (auto node in nodes)
    {
        if (!node->visited)
            PrintDfs(node, chain);
    }
    cout << endl;

    /*for each (auto node in nodes)
    {
        cout << node->discoverTime << "/" << node->finishTime << " ";
    }*/

    for each (auto node in chain)
    {
        cout << node->label.c_str() << " ";
    }
    cout << endl;
}

void Graph::PrintDfs(shared_ptr<vertex> node, list<shared_ptr<vertex>>& chain)
{
    cout << node->label.c_str() << " ";
    node->visited = true;

    time++;
    node->discoverTime = time;

    for each(auto i in node->neighbors)
    {
        if (!i->neighbor->visited)
        {
            PrintDfs(i->neighbor, chain);
        }
    }

    time++;
    node->finishTime = time;

    chain.push_front(node);
}
