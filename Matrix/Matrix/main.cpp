#include "Headers.h"

int main()
{
    int** matrix = new int*[ROW];
    for (int i = 0; i < COL; i++)
    {
        matrix[i] = new int[COL];
    }

    int value = 1;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            matrix[i][j] = value++;
        }
    }

    PrintMatrix(matrix, ROW, COL);

    RotateMatrix(matrix, ROW, COL);

    PrintMatrix(matrix, ROW, COL);

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}
