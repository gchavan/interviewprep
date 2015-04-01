#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void PrintIncreasingSequence(int start, int k, int n);
void PrintSequence(int* sequence, int len);
void PrintCombinationsToNumber(int n, int currSum, vector<int>& combinations);

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

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
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