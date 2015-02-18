#include "Headers.h"

struct point
{
    point(int row, int col)
    {
        this->row = row;
        this->col = col;
    }

    int row;
    int col;
};

bool dfs(int **arr, int row, int col, int currRow, int currCol, bool **visited, vector<int>& connected)
{
    if ((currRow < 0 || currRow >= row) || (currCol < 0 || currCol >= col))
        return false;

    if (visited[currRow][currCol] == true)
        return false;

    if (arr[currRow][currCol] == 0)
        return false;

    int longestPath = 0;
    point left(currRow, currCol - 1);
    point right(currRow, currCol + 1);
    point top(currRow - 1, currCol);
    point bottom(currRow + 1, currCol);
    point topLeft(currRow - 1, currCol - 1);
    point topRight(currRow - 1, currCol + 1);
    point bottomLeft(currRow + 1, currCol - 1);
    point bottomRight(currRow + 1, currCol + 1);

    connected.push_back(arr[currRow][currCol]);
    visited[currRow][currCol] = true;

    dfs(arr, row, col, left.row, left.col, visited, connected);

    dfs(arr, row, col, right.row, right.col, visited, connected);
    
    dfs(arr, row, col, top.row, top.col, visited, connected);

    dfs(arr, row, col, bottom.row, bottom.col, visited, connected);

    dfs(arr, row, col, topLeft.row, topLeft.col, visited, connected);

    dfs(arr, row, col, topRight.row, topRight.col, visited, connected);

    dfs(arr, row, col, bottomLeft.row, bottomLeft.col, visited, connected);

    dfs(arr, row, col, bottomRight.row, bottomRight.col, visited, connected);

    return connected.size() > 0;
}

int main()
{
    int arr[5][5] = {
        { 1, 1, 0, 0, 0 },
        { 0, 1, 0, 0, 1 },
        { 1, 0, 0, 1, 1 },
        { 0, 0, 0, 0, 0 },
        { 1, 0, 1, 0, 1 }
    };

    int rows = 5;
    int cols = 5;
    bool** visited = (bool**)malloc(sizeof(bool) * rows);
    int** newArr = (int**)malloc(sizeof(int) * rows);
    for (int i = 0; i < rows; i++)
    {
        newArr[i] = (int*)malloc(sizeof(int) * cols);
        visited[i] = (bool*)malloc(sizeof(bool) * cols);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            newArr[i][j] = arr[i][j];
        }
    }

    vector<int> connected;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dfs(newArr, 5, 5, i, j, visited, connected);

            if (!connected.empty())
            {
                for (int i : connected)
                {
                    cout << i << " ";
                }
                cout << "!" << endl;
                connected.clear();
            }
        }
    }

    cout << endl << "press any key..." << endl;
    cin.get();
    return 0;
}

