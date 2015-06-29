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

void avoidRoads()
{
    /*
    In the city, roads are arranged in a grid pattern.Each point on the grid represents a corner where two blocks meet.
    The points are connected by line segments which represent the various street blocks.Using the cartesian coordinate system, 
    we can assign a pair of integers to each corner as shown below.

    You are standing at the corner with coordinates 0,0. Your destination is at corner width,height.
    You will return the number of distinct paths that lead to your destination. Each path must use exactly width+height blocks.
    In addition, the city has declared certain street blocks untraversable. These blocks may not be a part of any path.
    You will be given a String[] bad describing which blocks are bad. If (quotes for clarity) "a b c d" is an element of bad, 
    it means the block from corner a,b to corner c,d is untraversable. For example, let's say
    width  = 6
    length = 6
    bad = {"0 0 0 1","6 6 5 6"}
    The picture below shows the grid, with untraversable blocks darkened in black. A sample path has been highlighted in red.
    */

    const int width = 2 + 1;
    const int height = 2 + 1;
    string bad[] = { "0 0 0 1", "6 6 5 6" };

    long long matrix[height][width] = { 0 };
    for (int i = 0; i < height; i++)
        matrix[i][0] = 1;

    for (int i = 0; i < width; i++)
        matrix[0][i] = 1;

    /*for (int i = 1; i < width; i++)
        matrix[0][i] = -1;

    matrix[5][6] = -1;*/

    for (int i = 1; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            if (matrix[i][j] != -1)
            {
                long long top = matrix[i - 1][j] >= 0 ? matrix[i - 1][j] : 0;
                long long left = matrix[i][j - 1] >= 0 ? matrix[i][j - 1] : 0;
                matrix[i][j] = left + top;
                // cout << matrix[i][j] << " ";
            }
        }
        // cout << endl;
    }

    /*for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << "Total paths : " << matrix[height - 1][width - 1] << endl;
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

    avoidRoads();

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}
