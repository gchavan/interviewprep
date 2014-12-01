#include <iostream>
#include <vector>

using namespace std;

// #define DEBUG 0

void PrintWaysToReachBasketballScore(int curr, int n, vector<int>& points);

int main()
{
    int n = 5;

    vector<int> points;
    PrintWaysToReachBasketballScore(0, n, points);

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}

void PrintWaysToReachBasketballScore(int currStep, int n, vector<int>& points)
{
    if (currStep > n)
    {
        return;
    }

    if (currStep == n)
    {
        for (unsigned int i = 0; i < points.size() - 1; i++)
        {
            cout << points[i] << " -> ";
        }
        cout << points.back() << "." << endl;
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        points.push_back(currStep + i);

        PrintWaysToReachBasketballScore(currStep + i, n, points);

        points.pop_back();
    }
}