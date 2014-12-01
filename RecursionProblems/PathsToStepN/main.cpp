#include <iostream>
#include <vector>

using namespace std;

// #define DEBUG 0

void PrintPathsToStepN(int currStep, int n, vector<int>& path);

int main()
{
    int n = 4;

    vector<int> path;
    PrintPathsToStepN(0, n, path);

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}

void PrintPathsToStepN(int currStep, int n, vector<int>& path)
{
    if (currStep > n)
    {
        return;
    }

    if (currStep == n)
    {
        for (unsigned int i = 0; i < path.size() - 1; i++)
        {
            cout << path[i] << " -> ";
        }
        cout << path.back() << "." << endl;
        return;
    }

    for (int i = 1; i <= 2; i++)
    {
        path.push_back(currStep + i);

        PrintPathsToStepN(currStep + i, n, path);

        path.pop_back();
    }
}