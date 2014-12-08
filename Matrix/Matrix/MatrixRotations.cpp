#include "Headers.h"

void RotateMatrix(int** matrix, int row, int col)
{
    if (!matrix || row < 1 || col < 1)
        return;

    cout << "Rotating the matrix..." << endl;

    for (int i = 0; i < row / 2; i++)
    {
        int start = i;
        int end = row - i - 1;
        int currRow = start;
        int currCol = end;

        while (currRow < end)
        {
            // current row top element
            int temp = matrix[start][currRow];

            // bottom-left to top-left
            matrix[start][currRow] = matrix[currCol][start];

            // bottom-right to bottom-left
            matrix[currCol][start] = matrix[end][currCol];

            // top-right to bottom-right
            matrix[end][currCol] = matrix[currRow][end];

            // top-left to top-right
            matrix[currRow][end] = temp;

            currRow++;
            currCol--;
        }
    }
}

