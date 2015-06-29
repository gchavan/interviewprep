#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

void PrintPaths(char grid[3][3], int rows, int cols, int currRow, int currCol, int endRow, int endCol, vector<char>& path)
{
    if (currRow < 0 || currRow >= rows)
        return;

    if (currCol < 0 || currCol >= cols)
        return;

    if (currRow == endRow && currCol == endCol)
    {
        path.push_back(grid[currRow][currCol]);

        for (auto c : path)
            cout << c << " ";
        cout << endl;

        path.pop_back();

        return;
    }

    path.push_back(grid[currRow][currCol]);

    PrintPaths(grid, rows, cols, currRow, currCol + 1, endRow, endCol, path);

    PrintPaths(grid, rows, cols, currRow + 1, currCol, endRow, endCol, path);

    path.pop_back();
}



int main()
{
    char grid[3][3] = {
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
    };

    vector<char> path;
    PrintPaths(grid, 3, 3, 0, 0, 2, 2, path);

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}
