#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

//#define DEBUG 0

#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

void PrintA(int aPrinted, int aInBuffer, int n, int& maxA)
{
    if (n < 0)
        return;

    if (n == 0)
    {
        if (aPrinted > maxA)
            maxA = aPrinted;
        return;
    }

    if (n >= 1)
    {
        aPrinted += 1;
        n--;
        PrintA(aPrinted, aInBuffer, n, maxA);
        aPrinted -= 1;
        n++;
    }

    if (n >= 1 && aInBuffer > 0)
    {
        aPrinted += aInBuffer;
        n--;
        PrintA(aPrinted, aInBuffer, n, maxA);
        n++;
        aPrinted -= aInBuffer;
    }

    if (n >= 3)
    {
        aInBuffer = aPrinted;
        aPrinted += aPrinted;
        n -= 3;
        PrintA(aPrinted, aInBuffer, n, maxA);
        n += 3;
        aInBuffer = 0;
        aPrinted -= aPrinted;
    }
}

int main()
{ 
    int maxA = 0;
    for (int i = 1; i <= 20; i++)
    {
        PrintA(0, 0, i, maxA);
        cout << endl << "Maximum Number of A's with " << i << " keystrokes is " << maxA << endl;
    }

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}
