#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void maxProductSubArray(vector<int>& input)
{
    int maxSoFar = 1;
    int maxEndingHere = 1;
    int minEndingHere = 1;

    for (auto i : input)
    {
        if (i > 0)
        {
            maxEndingHere = maxEndingHere * i;
            minEndingHere = min(minEndingHere * i, 1);
        }
        else if (i == 0)
        {
            maxEndingHere = 1;
            minEndingHere = 1;
        }
        else
        {
            int temp = maxEndingHere;
            maxEndingHere = max(minEndingHere * i, 1);
            minEndingHere = temp * i;
        }

        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
    }

    cout << "[";
    for (unsigned int i = 0; i < input.size() - 1; i++)
        cout << input[i] << ", ";
    cout << input[input.size() - 1] << "] = " << maxSoFar << endl;
}

bool threeSum(vector<int>& input, int k)
{
    if (input.size() < 3)
        return false;

    sort(input.begin(), input.end());

    int size = input.size();
    for (int i = 0; i < size - 2; i++)
    {
        int left = i + 1;
        int right = size - 1;
        while (left < right)
        {
            int currSum = input[i] + input[left] + input[right];
            if (currSum == k)
                return true;
            else if (currSum < k)
                left++;
            else
                right--;
        }
    }

    return false;
}

double power(double a, int b)
{
    if (b == 0)
        return 1;

    if (b == 1)
        return a;

    bool isNegative = false;
    if (b < 0)
    {
        isNegative = true;
        b *= -1;
    }

    double result = 0.0;
    if (b % 2 != 0)
    {
        result = a * power(a, b - 1);
    }
    else
    {
        result = power(a, b / 2);
        result *= result;
    }

    if (isNegative)
    {
        result = 1.0 / result;
    }
    
    return result;
}

double SqrtNumber(double num)
{
    double lower_bound = 0;
    double upper_bound = num;
    double temp = 0;

    while (fabs(num - (temp * temp)) > 0.000000001)
    {
        temp = (lower_bound + upper_bound) / 2;
        if (temp*temp >= num)
        {
            upper_bound = temp;
        }
        else
        {
            lower_bound = temp;
        }
    }


    return temp;
}

void maxSubArray(int* arr, int size)
{
    int maxSoFar = arr[0];
    int currMax = arr[0];
    for (int i = 1; i < size; i++)
    {
        currMax = max(arr[i], currMax + arr[i]);
        maxSoFar = max(maxSoFar, currMax);
    }

    cout << "maxSoFar = " << maxSoFar << endl;
}

void kadaneAlgo()
{
    int arr[] = { 2, -3, 2, 4, -5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxStart = 0;
    int sum = 0;
    int start = 0;
    int end = 0;
    int maxSoFar = 0;
    for (int i = 0; i < size; i++)
    {
        maxSoFar += arr[i];
        if (maxSoFar < 0)
        {
            maxSoFar = 0;
            start = i + 1;
        }
        if (sum < maxSoFar)
        {
            maxStart = start;
            sum = maxSoFar;
            end = i;
        }
    }

    cout << sum << "(" << maxStart << "," << end << ")" << endl;

}

void productArray()
{
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int* product = new int[n]{};
    int temp = 1;

    for (int i = 0; i < n; i++)
    {
        product[i] = temp;
        temp *= arr[i];
    }

    temp = 1;

    for (int i = 0; i < n; i++)
        cout << product[i] << " ";
    cout << endl;

    for (int i = n - 1; i >= 0; i--)
    {
        product[i] *= temp;
        temp *= arr[i];
    }

    for (int i = 0; i < n; i++)
        cout << product[i] << " ";
    cout << endl;

    delete product;
}

void wordDiff()
{
    string words[] = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int size = sizeof(words) / sizeof(words[0]);
    unordered_map<string, unordered_set<int>> wordPosition;

    for (int i = 0; i < size; i++)
    {
        if (wordPosition.find(words[i]) == wordPosition.end())
        {
            unordered_set<int> indices;
            indices.insert(i);
            wordPosition[words[i]] = indices;
        }
        else
        {
            wordPosition[words[i]].insert(i);
        }
    }

    string str1 = "lazy";
    string str2 = "the";
    int diff = INT_MAX;
    for (auto it1 : wordPosition[str1])
    {
        for (auto it2 : wordPosition[str2])
        {
            if (diff > abs(it1 - it2))
                diff = abs(it1 - it2);
        }
    }

    cout << "Diff between " << str1.c_str() << " and " << str2.c_str() << " is " << diff << endl;
}

int main()
{
    vector<vector<int>> inputs;
    inputs.push_back({ -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5 });
    inputs.push_back({ 6, -3, -10, 0, 2 });
    inputs.push_back({ -1, -3, -10, 0, 60 });
    inputs.push_back({ -2, -3, 0, -2, -40 });

    /*for (auto input: inputs)
        maxProductSubArray(input);*/

    cout << endl;
    bool isThreeSumPresent = threeSum(vector<int>({ 12, 3, 4, 1, 6, 9 }), 12);
    cout << (isThreeSumPresent ? "Three sum is present!" : "Three sum is NOT present!") << endl;

    /*
    cout << "pow(2.0, -2) = " << pow(2.0, -2) << endl;
    cout << "pow(2.0, -3) = " << pow(2.0, -3) << endl;
    cout << "pow(2.0, -4) = " << pow(2.0, -4) << endl;
    cout << "pow(2.0, 4) = " << pow(2.0, 4) << endl;
    cout << "pow(2.0, 5) = " << pow(2.0, 5) << endl;

    cout << "SqrtNumber(2.0) = " << SqrtNumber(2.0) << endl;
    cout << "SqrtNumber(3.0) = " << SqrtNumber(3.0) << endl;
    cout << "SqrtNumber(4.0) = " << SqrtNumber(4.0) << endl;
    cout << endl;
    char str[] = "- This, a sample string.";
    char* pch = nullptr;
    char* context = nullptr;
    cout << "Splitting string '" << str << "' into tokens..." << endl;
    pch = strtok_s(str, " ,.-", &context);
    while (pch != nullptr)
    {
        cout << pch << endl;
        pch = strtok_s(nullptr, " ,.-", &context);
    }
    */

    int arr[] = {-2, -2, -1, -2, -1, -1, -2};
    int size = sizeof(arr) / sizeof(arr[0]);
    maxSubArray(arr, size);

    productArray();

    wordDiff();

    kadaneAlgo();

    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}