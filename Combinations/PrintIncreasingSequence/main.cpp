#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void PrintIncreasingSequence(int start, int k, int n);
void PrintSequence(int* sequence, int len);

int main()
{
    int k = 4;
    int n = 8;

    for (int i = 1; i <= (n - k + 1); i++)
    {
        PrintIncreasingSequence(i, k, n);
    }

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
    cout << endl << endl;
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