#include "Headers.h"

int main()
{
    Graph graph;
    
    graph.BuildGraph();

    graph.PrintBfs();

    graph.Print();

    graph.PrintBuildOrder();

    graph.CheckIfCycle();

    graph.DijkstrasAlgo();

    cout << endl << "press any key..." << endl;
    cin.get();
    return 0;
}
