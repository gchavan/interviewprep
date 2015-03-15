#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void FindNthNumber(int n1, int n2, int n);
int FindNthNumberUsingRecursion(int n1, int n2, int n);

int main()
{
    int n1 = 3;
    int n2 = 4;
    int n = 25;
    FindNthNumber(n1, n2, n);

    cout << n << "th number: " << FindNthNumberUsingRecursion(n1, n2, n) << endl;

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}

void FindNthNumber(int n1, int n2, int n)
{
    int* numbers = new int[n];
    numbers[0] = n1;
    numbers[1] = n2;
    int index = 0;
    for (int i = 2; i < n; i += 2)
    {
        numbers[i] = numbers[index] * 10 + n1;
        numbers[i + 1] = numbers[index] * 10 + n2;
        index++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << "th number: " << numbers[i] << endl;
    }
}

int FindNthNumberUsingRecursion(int n1, int n2, int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
    {
        cout << n << " ==> " << n1 << endl;
        return n1;
    }

    if (n == 2)
    {
        cout << n << " ==> " << n2 << endl;
        return n2;
    }

    int value = (10 * FindNthNumberUsingRecursion(n1, n2, (n - 1) / 2)) + (n % 2 == 0 ? n2 : n1);

    cout << n << " ==> " << value << endl;

    return value;
}