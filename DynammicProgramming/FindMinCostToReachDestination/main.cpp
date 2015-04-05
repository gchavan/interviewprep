#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

#define N 6

int gCount = 0;
int memoizedArr[N] = {};

int findMinCost(int arr[][N])
{
    int distance[N] = {};
    for (int i = 1; i < N; i++)
        distance[i] = INT_MAX;
    distance[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (distance[j] > distance[i] + arr[i][j])
                distance[j] = distance[i] + arr[i][j];
        }
    }

    return distance[N-1];
}

int findMinCost(int arr[][N], int start, int end)
{
    if (start >= end || end >= N)
        return 0;

    if (memoizedArr[start] != 0)
        return memoizedArr[start];

    gCount++;

    int minCost = arr[start][end];
    for (int i = start + 1; i < end; i++)
    {
        int cost_start_to_end = arr[start][i] + findMinCost(arr, i, end);
        if (minCost > cost_start_to_end)
        {
            minCost = cost_start_to_end;
        }
    }

    memoizedArr[start] = minCost;

    return minCost;
}

int main()
{
    int arr[N][N] = {
        {0, 15, 80, 90, 11, 200},
        {-1, 0, 40, 50, 85, 122},
        {-1, -1, 0, 70, 150, 75},
        {-1, -1, -1, 0, 75, 100},
        {-1, -1, -1, -1, 0, 80},
        {-1, -1, -1, -1, -1, 0 },
    };

    int start = 0;
    int end = 5;

    int minCost = findMinCost(arr, start, end);
    cout << "The min const from " << start << " to " << end << " is " << minCost << endl;

    minCost = findMinCost(arr);
    cout << "The min const from " << start << " to " << end << " is " << minCost << endl;

    // cout << "gCount = " << gCount << endl;

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}
