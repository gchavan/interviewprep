#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

//#define DEBUG 0

#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

#define PRINT_ARR(arr) \
    std::cout << "Array: "; \
    for (auto val: arr) \
        std::cout << val << " "; \
    std::cout << std::endl;

#define MAX(a, b) \
    (a) > (b) ? (a) : (b)

int gSpaceCount = 0;

int MemoizedCutRod(int* prices, int n, map<int, int>& results)
{
    if (n <= 0)
        return 0;

    int q = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int prevCutLen = n - i - 1;
        int prevCut = 0;
        if (results.find(prevCutLen) != results.end())
        {
            prevCut = results[prevCutLen];
        }
        else
        {
            prevCut = MemoizedCutRod(prices, prevCutLen, results);
        }

        int newPrice = prices[i] + prevCut;

        q = (q > newPrice) ? q : newPrice;
    }

    results[n] = q;

    return q;
}

int CutRod(int* prices, int n)
{
    if (n <= 0)
        return 0;

    int q = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int prevCutLen = n - i - 1;
        int prevCut = CutRod(prices, prevCutLen);
        int newPrice = prices[i] + prevCut;

        q = (q > newPrice) ? q : newPrice;
    }

    return q;
}

int BottomUpCutRod(int* prices, int n)
{
    int* results = new int[n+1]();

    for (int i = 1; i <= n; i++)
    {
        int q = INT_MIN;
        for (int j = 0; j < i; j++)
            q = max(q, prices[j] + results[i - j - 1]);
        results[i] = q;
    }

    int price = results[n];
    
    delete[] results;

    return price;
}

int main()
{
    map<int, int> results;
    int prices[] = { 1, 5, 8, 9, 10 };
    int n = 4;

    cout << "Cut rod of size " << n << ": " << CutRod(prices, n) << endl;
    cout << "Cut rod of size " << n << ": " << MemoizedCutRod(prices, n, results) << endl;
    cout << "Cut rod of size " << n << ": " << BottomUpCutRod(prices, n) << endl;

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}
