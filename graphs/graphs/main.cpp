#include "Headers.h"

int main()
{
    Graph graph;
    
    graph.BuildGraph();

    graph.PrintBfs();

    graph.PrintBuildOrder();

    graph.CheckIfCycle();

    cout << endl << "press any key..." << endl;
    cin.get();
    return 0;
}
