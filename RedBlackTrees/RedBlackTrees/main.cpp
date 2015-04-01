#include "Headers.h"

int main()
{
    RBTree rbTree;
    // int arr[] = { 1, 2, 3, 4, 5, 6 };
    int arr[] = { 41, 38, 31, 12, 19, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        rbTree.Insert(arr[i]);
    }
    rbTree.Print();

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}