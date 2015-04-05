#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

//#define DEBUG 0

#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

enum Direction
{
    Up,
    Left,
    Diagonal
};

void PrintLongestIncreasingSequence(int* arr, int len);
void PrintLongestCommonSubsequence(char* str1, char* str2);
void PrintLongestCommonSubsequence(int** matrix, Direction** direction, char* str1, char* str2, int row, int col);

void PrintMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void PrintLongestIncreasingSequence(int* arr, int n)
{
    int *lis, i, j, max = 0;
    lis = (int*)malloc(sizeof(int) * n);

    for (int k = 0; k < n; k++)
        cout << setfill('0') << setw(2) << arr[k] << "  ";
    cout << endl << endl;

    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++)
        lis[i] = 1;

    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }

        // cout << setfill('0') << setw(2) << arr[i] << "   ";
        for (int k = 0; k < n; k++)
            cout << setfill('0') << setw(2) << lis[k] << "  ";
        cout << endl;
    }       

    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++)
        if (max < lis[i])
            max = lis[i];

    /* Free memory to avoid memory leak */
    free(lis);

    cout << "Length of LIS is " << max << endl;
}

int main()
{
    /*char* str1 = "XMJYAUZ";
    char* str2 = "MZJAWXU";*/
    char* str1 = "ABCBDAB";
    char* str2 = "BDCABA";
        
    PrintLongestCommonSubsequence(str1, str2);

    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    // int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    PrintLongestIncreasingSequence(arr, ARRAY_SIZE(arr));

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}

void PrintLongestCommonSubsequence(char* str1, char* str2)
{
    int len1 = strlen(str1) + 1;
    int len2 = strlen(str2) + 1;
    int** matrix = new int*[len1];
    Direction** direction = new Direction*[len1];

    for (int i = 0; i < len1; i++)
    {
        matrix[i] = new int[len2]();
        direction[i] = new Direction[len2]();
    }

    for (int i = 1; i < len1; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                matrix[i][j] = matrix[i-1][j-1] + 1;
                direction[i][j] = Direction::Diagonal;
            }
            else if (matrix[i - 1][j] >= matrix[i][j - 1])
            {
                matrix[i][j] = matrix[i - 1][j];
                direction[i][j] = Direction::Up;
            }
            else
            {
                matrix[i][j] = matrix[i][j - 1];
                direction[i][j] = Direction::Left;
            }
        }
    }

    PrintMatrix(matrix, len1, len2);

    cout << endl << "The longest common subsequence is ";
    PrintLongestCommonSubsequence(matrix, direction, str1, str2, len1 - 1, len2 - 1);

    cout << endl << endl;
}

void PrintLongestCommonSubsequence(int** matrix, Direction** direction, char* str1, char* str2, int row, int col)
{
    if (row == 0 || col == 0)
        return;

    if (direction[row][col] == Direction::Diagonal)
    {
        PrintLongestCommonSubsequence(matrix, direction, str1, str2, row - 1, col - 1);
        cout << str1[row - 1];
    }
    else if (direction[row][col] == Direction::Up)
        PrintLongestCommonSubsequence(matrix, direction, str1, str2, row - 1, col);
    else
        PrintLongestCommonSubsequence(matrix, direction, str1, str2, row, col - 1);
}