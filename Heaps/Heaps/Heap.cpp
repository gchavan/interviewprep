#include "Heap.h"

IHeap::IHeap()
    : data(nullptr),
      size(0)
{
}

void IHeap::Sort()
{
    tempSize = size;
    while (tempSize > 0)
    {
        int min = data[0];
        int left = 1;
        int right = 2;
        int last = tempSize - 1;

        data[0] = data[last];
        data[last] = min;
        tempSize--;

        Heapify(0, tempSize);
    }

    tempSize = size;
}

void IHeap::Print()
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

void MinHeap::BuildHeap(int* arr, int n)
{
    if (data)
    {
        throw new exception("The heap can be built only once.");
    }

    if (!arr || n <= 0)
    {
        throw new exception("Invalid args.");
    }

    tempSize = size = n;
    data = new int[size];
    for (int i = 0; i < n; i++)
    {
        data[i] = arr[i];
    }

    for (int i = n/2; i >= 0; i--)
    {
        Heapify(i, size);
    }
}

void MinHeap::Heapify(int curr, int max)
{
    int left = 2 * curr + 1;
    int right = 2 * curr + 2;
    int swap = curr;

    if (left < max && data[left] < data[curr])
        swap = left;

    if (right < max && data[right] < data[swap])
        swap = right;

    if (swap != curr)
    {
        int temp = data[curr];
        data[curr] = data[swap];
        data[swap] = temp;

        Heapify(swap, max);
    }
}

void MinHeap::Sort()
{
    IHeap::Sort();

    reverse(data, data + size);
    this->Print();
}

void MaxHeap::BuildHeap(int* arr, int n)
{
    if (size != 0)
    {
        throw new exception("The heap can be built only once.");
    }

    if (!arr || n <= 0)
    {
        throw new exception("Invalid args.");
    }

    tempSize = size = n;
    data = new int[size];
    for (int i = 0; i < n; i++)
    {
        data[i] = arr[i];
    }

    for (int i = n / 2; i >= 0; i--)
    {
        Heapify(i, size);
    }
}

void MaxHeap::Heapify(int curr, int max)
{
    int left = 2 * curr + 1;
    int right = 2 * curr + 2;
    int swap = curr;

    if (left < max && data[left] > data[curr])
        swap = left;

    if (right < max && data[right] > data[swap])
        swap = right;

    if (swap != curr)
    {
        int temp = data[curr];
        data[curr] = data[swap];
        data[swap] = temp;

        Heapify(swap, max);
    }
}

void MaxHeap::Sort()
{
    IHeap::Sort();

    this->Print();
}