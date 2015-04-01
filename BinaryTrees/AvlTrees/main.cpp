#include "Headers.h"

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    int size = sizeof(arr) / sizeof(arr[0]);

    node* root = nullptr;
    for (auto i : arr)
    {
        insert(&root, root, i);
        // insert(&root, i);
    }

    cout << "Print tree level wise..." << endl;
    printByLevel(root);

    deleteTree(&root);

    cout << endl;
    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}