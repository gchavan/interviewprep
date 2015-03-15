#include "Heap.h"

void PerformHeapOperations(shared_ptr<IHeap> heap, int* arr, int n)
{
    heap->BuildHeap(arr, n);

    cout << "heap array (before)   : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "heap array (after)    : ";
    heap->Print();

    cout << "heap array (sorted)   : ";
    heap->Sort();
}

int main()
{
    int minHeapArr[] = { 7, 9, 2, 5, 1, 6, 3, 8, 10, 4 };
    int maxHeapArr[] = { 7, 9, 2, 5, 1, 6, 3, 8, 10, 4 };
    int n = sizeof(minHeapArr) / sizeof(minHeapArr[0]);
    auto min = make_shared<MinHeap>();

    auto max = make_shared<MaxHeap>();

    cout << "perform min-heap operations..." << endl;    
    PerformHeapOperations(min, minHeapArr, n);

    cout << endl << endl;
    PerformHeapOperations(max, maxHeapArr, n);

    cout << endl << endl;
    cout << "press any key to continue..." << endl;
    cin.get();
    return 0;
}