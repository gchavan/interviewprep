#include "Headers.h"

int main()
{
    Graph graph;
    
    graph.BuildGraph();

    graph.PrintBfs();

    graph.PrintDfs();

    cout << endl << "press any key..." << endl;
    cin.get();
    return 0;
}
