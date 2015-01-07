#include "LruCache.h"

int main()
{
    LruCache lru(4);

    int arr[] = { 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        lru.Add(arr[i]);
    }

    cout << endl;
    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}