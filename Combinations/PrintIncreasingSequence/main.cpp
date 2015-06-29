#include <iostream>
#include <memory>
#include <vector>
#include <stack>
using namespace std;

void PrintIncreasingSequence(int start, int k, int n);
void PrintSequence(int* sequence, int len);
void PrintCombinationsToNumber(int n, int currSum, vector<int>& combinations);
void PrintCoinCombinationsRecursive(int* arr, int len, int amount, int index, int* result, int currentSum);
void PrintCoinCombinationsIterative(int* arr, int len, int amount);

int main()
{
    int k = 3;
    int n = 7;

    for (int i = 1; i <= (n - k + 1); i++)
    {
        PrintIncreasingSequence(i, k, n);
    }

    n = 4;
    vector<int> combinations;
    cout << "Print combinations..." << endl;
    PrintCombinationsToNumber(n, 0, combinations);

    int amount = 5;
    int arr[] = {1, 3, 5};
    int len = 3;
    int* result = new int[len]();

    cout << endl << "Print combinations to reach " << amount << endl;
    PrintCoinCombinationsRecursive(arr, len, amount, 0, result, 0);
    delete[] result;

    result = new int[len]();
    PrintCoinCombinationsIterative(arr, len, amount);

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}

void PrintCoinCombinationsRecursive(int* arr, int len, int amount, int index, int* result, int currentSum)
{
    if (currentSum > amount)
        return;

    if (currentSum == amount)
    {
        cout << "Combination: ";
        for (int i = 0; i < len; i++)
            cout << "\t" << arr[i] << " = " << result[i] << " ";
        cout << endl;
    }

    for (int i = index; i < len; i++)
    {
        result[i]++;
        PrintCoinCombinationsRecursive(arr, len, amount, i, result, currentSum + arr[i]);
        result[i]--;
    }
}

void PrintCoinCombinationsIterative(int* arr, int len, int amount)
{
    int* table = new int[amount + 1]();

    memset(table, 0, sizeof(table));

    table[0] = 1;

    for (int i = 0; i < len; i++)
    {
        int prevJ = 0;
        for (int j = arr[i]; j <= amount; j++)
        {
            table[j] += table[j - arr[i]];
            prevJ = j;
        }
    }

    cout << endl << "# of combinations: " << table[amount] << endl;

    delete table;
}

void PrintSequence(int* sequence, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << sequence[i] << " ";
    }
    cout << endl;
}

void PrintIncreasingSequence(int start, int k, int n)
{
    int* sequence = new int[k];
    sequence[0] = start;
    int writeIndex = 1;
    for (int i = start + 1; i <= (n - (k - 1) + 1); i++)
    {
        writeIndex = 1;
        int nextNum = i;
        while (writeIndex < k)
        {
            sequence[writeIndex++] = nextNum++;
        }

        PrintSequence(sequence, k);
    }

    delete[] sequence;
}

void PrintCombinationsToNumber(int n, int currSum, vector<int>& combinations)
{
    if (n == currSum)
    {
        for (auto item : combinations)
            cout << item << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= (n - currSum); i++)
    {
        if ((currSum + i) <= n)
        {
            combinations.push_back(i);
            PrintCombinationsToNumber(n, currSum + i, combinations);
            combinations.pop_back();
        }
    }
}