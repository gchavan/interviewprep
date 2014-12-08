#include "Headers.h"

void PrintMatrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setfill('0') << setw(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}