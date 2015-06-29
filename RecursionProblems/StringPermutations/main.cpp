#include <iostream>
#include <vector>

using namespace std;

// #define DEBUG 0

void PrintStringPermutationWithoutDuplicates(char* arr, int n, char* output, int outputIndex, bool* used);

int main()
{
    char str[] = "abc";
    // char str[] = "aba";
    int n = 3;
    bool used[3] = { 0 };
    char output[4] = { 0 };

    PrintStringPermutationWithoutDuplicates(str, n, output, 0, used);

     cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}

void PrintStringPermutationWithoutDuplicates(char* arr, int n, char* output, int outputIndex, bool* used)
{
    if (outputIndex == n)
    {
        cout << output << endl;
        return;
    }

    bool usedInPosition[256] = { 0 };
    for (int i = 0; i < n; i++)
    {
        char curr = arr[i];
        if (!used[i] && !usedInPosition[curr])
        {
            usedInPosition[curr] = true;
            used[i] = true;
            output[outputIndex] = arr[i];
            PrintStringPermutationWithoutDuplicates(arr, n, output, outputIndex + 1, used);
            used[i] = false;
        }
    }
}