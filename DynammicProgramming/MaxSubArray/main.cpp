#include <iostream>

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

struct MaxSubResult
{
    int sum = 0;
    int start = 0;
    int end = 0;
};

MaxSubResult FindMaxSubarray(int* arr, int size);
MaxSubResult Find2ndMaxSubarray(int* arr, int size);

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4, /*-6, 4, 2, 1, */ };
    // int arr[] = { -2, -3, -4, -1, -2, -1, -5, -3 };
    int arrSize = ARRAY_SIZE(arr);
    PRINT_ARR(arr);

    auto maxSubarray = FindMaxSubarray(arr, arrSize);

    cout << "Max Subarray in the given arr is: " << maxSubarray.sum
        << " from " << maxSubarray.start << "," << maxSubarray.end << endl;

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}

MaxSubResult FindMaxSubarray(int* arr, int arrSize)
{
    MaxSubResult maxSoFar;
    MaxSubResult maxHere;

    MaxSubResult* maxHeres = new MaxSubResult[arrSize];
    MaxSubResult* maxSubs = new MaxSubResult[arrSize];

    maxSoFar.sum = arr[0];
    maxSoFar.start = 0;
    maxSoFar.end = 0;

    for (int i = 1; i < arrSize; i++)
    {
        if ((maxHere.sum + arr[i]) > arr[i])
        {
            maxHere.sum += arr[i];
        }
        else
        {
            maxHere.sum = arr[i];
            maxHere.start = i;
        }

        if (maxSoFar.sum < maxHere.sum)
        {
            maxSoFar = maxHere;
            maxSoFar.end = i;
        }

        maxHeres[i] = maxHere;
        maxSubs[i] = maxSoFar;
    }

#ifdef DEBUG
    for (int i = 0; i < arrSize; i++)
    {
        cout << maxHeres[i].sum << " - " << maxSubs[i].sum << endl;
    }
#endif

    delete[] maxHeres;
    delete[] maxSubs;

    return maxSoFar;
}
