#include <iostream>

using namespace std;

// #define DEBUG 0

#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

#define PRINT_ARR(arr) \
    std::cout << "Array: "; \
    for (auto val: arr) \
        std::cout << val << " "; \
    std::cout << std::endl;

void Swap(int& a, int& b);
int Partition(int* arr, int begin, int end, int partionIndex, bool ascending = true);
void PrintKthSmallest(int* arr, int arrSize, int k);
void PrintKthLargest(int* arr, int arrSize, int k);

int main()
{
    int originalArr[] = { 12, 11, 8, 5, 4, 2, 1, -1, -2, -3, -4, -6 };
    int arr[] = { 12, 11, 8, 5, 4, 2, 1, -1, -2, -3, -4, -6};
    int arrSize = ARRAY_SIZE(arr);
    int k = 0;

    PRINT_ARR(arr);

    for (int i = 0; i <= arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
            arr[j] = originalArr[j];
        PrintKthSmallest(arr, arrSize, i + 1);
    }

    for (int i = 0; i < arrSize; i++)
    {
        PrintKthLargest(arr, arrSize, i + 1);
    }

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}

void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int* arr, int begin, int end, int partionIndex, bool ascending)
{
    if (end <= 0)
    {
        return 0;
    }

    if (begin < 0 || partionIndex >= end)
    {
        throw exception("Invalid partition index.");
    }

    int partitionElement = arr[partionIndex];

    // Swap the partition element with the last element
    Swap(arr[partionIndex], arr[end - 1]);

    int swapIndex = begin;
    for (int i = begin; i < end; i++)
    {
        if (ascending && arr[i] < partitionElement)
        {
            Swap(arr[i], arr[swapIndex]);
            swapIndex++;
        }
        else if (!ascending && arr[i] > partitionElement)
        {
            Swap(arr[i], arr[swapIndex]);
            swapIndex++;
        }
    }

    Swap(arr[end-1], arr[swapIndex]);

    return swapIndex;
}

void PrintKthSmallest(int* arr, int arrSize, int k)
{
    if (k <= 0 || k > arrSize)
    {
        throw exception("Invalid 'k' value.");
    }

    int partitionIndex = 0;
    int begin = 0, end = arrSize;
    do
    {
        partitionIndex = Partition(arr, begin, end, (begin+end)/2);

        begin = partitionIndex > k-1 ? 0 : partitionIndex;
        end = partitionIndex > k-1 ? partitionIndex : end;

    } while (k-1 != partitionIndex);

    cout << endl << k << "'th smallest element is " << arr[k-1] << endl;    
}

void PrintKthLargest(int* arr, int arrSize, int k)
{
    if (k < 0 || k > arrSize)
    {
        throw exception("Invalid 'k' value.");
    }

    int partitionIndex = 0;
    int begin = 0, end = arrSize;
    do
    {
        partitionIndex = Partition(arr, begin, end, (begin + end) / 2, false);

        begin = partitionIndex > k-1 ? 0 : partitionIndex;
        end = partitionIndex > k-1 ? partitionIndex : end;

    } while (k-1 != partitionIndex);

    cout << endl << k << "'th largest element is " << arr[k - 1] << endl;
}