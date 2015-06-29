#include <iostream>
#include <iomanip>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

#define M 4
#define N 4

bool SearchIn2DSortedMatrix(int** matrix, int begin, int end, int m, int n, int item)
{
    int rowBegin = begin;
    int colBegin = end;

    int rowEnd = m - 1;
    int colEnd = n - 1;

    if (rowEnd - rowBegin == 0)
    {
        for (int i = colBegin; i <= colEnd; i++)
        {
            if (matrix[rowBegin][i] == item)
                return true;
        }
    }

    if (colEnd - colBegin == 0)
    {
        for (int i = rowBegin; i <= rowEnd; i++)
        {
            if (matrix[i][colBegin] == item)
                return true;
        }
    }

    while (rowBegin < m && colBegin < n && matrix[rowBegin][colBegin] < item)
    {
        rowBegin++;
        colBegin++;
    }

    while (rowEnd > rowBegin && colEnd > colBegin && matrix[rowEnd][colEnd] > item)
    {
        rowEnd--;
        colEnd--;
    }

    return false;
}

bool SearchIn2DSortedMatrixByEliminatingRowsAndColumnsRecursive(int** matrix, int rowBegin, int colBegin, int m, int n, int item)
{
    if (rowBegin >= m || colBegin >= n)
        return false;

    // If we're looking at only one row, then we just scan that row
    if ((m - rowBegin) == 1)
    {
        for (int i = colBegin; i < n; i++)
        {
            if (matrix[rowBegin][i] == item)
                return true;
        }

        return false;
    }

    // If we're looking at only one column, then we just scan that column
    if ((n - colBegin) == 1)
    {
        for (int i = rowBegin; i < m; i++)
        {
            if (matrix[i][colBegin] == item)
                return true;
        }

        return false;
    }

    int begin = matrix[rowBegin][colBegin];
    int end = matrix[rowBegin][n - 1];
    cout << " ==> " << "Checking if " << item << " is in between "
        << begin << " and " << end << endl;
    if (begin > item || end < item)
    {
        return SearchIn2DSortedMatrixByEliminatingRowsAndColumnsRecursive(matrix, rowBegin + 1, colBegin, m, n, item);
    }

    begin = matrix[rowBegin][colBegin];
    end = matrix[m - 1][colBegin];
    cout << " ==> " << "Checking if " << item << " is in between "
        << begin << " and " << end << endl;
    if (begin > item || end < item)
    {
        return SearchIn2DSortedMatrixByEliminatingRowsAndColumnsRecursive(matrix, rowBegin, colBegin + 1, m, n, item);
    }

    begin = matrix[rowBegin][n - 1];
    end = matrix[m - 1][n - 1];
    cout << " ==> " << "Checking if " << item << " is in between "
        << begin << " and " << end << endl;
    if (begin > item || end < item)
    {
        return SearchIn2DSortedMatrixByEliminatingRowsAndColumnsRecursive(matrix, rowBegin, colBegin, m, n - 1, item);
    }

    begin = matrix[m - 1][colBegin];
    end = matrix[m - 1][n - 1];
    cout << " ==> " << "Checking if " << item << " is in between "
        << begin << " and " << end << endl;
    if (begin > item || end < item)
    {
        return SearchIn2DSortedMatrixByEliminatingRowsAndColumnsRecursive(matrix, rowBegin, colBegin, m - 1, n, item);
    }

    return false;
}

bool SearchIn2DSortedMatrixByEliminatingRowsAndColumnsIterative(int** matrix, int m, int n, int item)
{
    int rowBegin = 0;
    int colBegin = 0;
    int rowEnd = m - 1;
    int colEnd = n - 1;

    bool oneColLeft = false;
    bool oneRowLeft = false;
    while (!oneColLeft && !oneRowLeft)
    {
        if (matrix[rowBegin][colBegin] > item || matrix[rowBegin][colEnd] < item)
            rowBegin++;
        if (matrix[rowBegin][colBegin] > item || matrix[rowEnd][colBegin] < item)
            colBegin++;
        if (matrix[rowBegin][colEnd] > item || matrix[rowEnd][colEnd] < item)
            colEnd--;
        if (matrix[rowEnd][colBegin] > item || matrix[rowEnd][colEnd] < item)
            rowEnd--;

        oneColLeft = colEnd == colBegin;
        oneRowLeft = rowEnd == rowBegin;
    }

    if (oneRowLeft)
    {
        for (int i = colBegin; i <= colEnd; i++)
        {
            if (matrix[rowBegin][i] == item)
                return true;
        }
    }

    // If we're looking at only one column, then we just scan that column
    if (oneColLeft)
    {
        for (int i = rowBegin; i <= rowEnd; i++)
        {
            if (matrix[i][colBegin] == item)
                return true;
        }
    }

    return false;
}

int main()
{
    int mat[M][N] = {   { 10, 20, 29, 40 },
                        { 15, 25, 35, 45 },
                        { 27, 30, 37, 48 },
                        { 32, 33, 39, 50 },
                    };

    int** matrix = new int*[M];
    for (int i = 0; i < N; i++)
    {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            matrix[i][j] = mat[i][j];

    int item = 29;
    cout << "SearchIn2DSortedMatrixByEliminatingRowsAndColumnsRecursive" << endl;
    bool found = SearchIn2DSortedMatrixByEliminatingRowsAndColumnsRecursive(matrix, 0, 0, M, N, item);
    cout << item << ((!found) ? " NOT " : " ") << "found in the matrix." << endl;

    cout << endl << "SearchIn2DSortedMatrixByEliminatingRowsAndColumnsIterative" << endl;
    found = SearchIn2DSortedMatrixByEliminatingRowsAndColumnsIterative(matrix, M, N, item);
    cout << item << ((!found) ? " NOT " : " ") << "found in the matrix." << endl;

    cout << endl << "SearchIn2DSortedMatrix" << endl;
    found = SearchIn2DSortedMatrix(matrix, 0, 0, M, N, item);
    cout << item << ((!found) ? " NOT " : " ") << "found in the matrix." << endl;

    cout << endl << "press any key to continue..." << endl;
    cin.get();
    return 0;
}