#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

#define N 6

int gCount = 0;
int memoizedArr[N] = {};

bool IsEvenlySplit(string& str)
{
    int len = str.length();
    int mid = len / 2;

    int leftCount = 0;
    int rightCount = 0;
    for (int i = 0; i < mid; i++)
        leftCount += (int)str[i];

    for (int i = mid; i < len; i++)
        rightCount += str[i];

    return leftCount == rightCount;
}

bool CheckIfArrayIsSplit(string& str, int start)
{
    bool isSplit = false;
    for (unsigned int i = 2; (start + i - 1) < str.length(); i += 2)
    {
        cout << "start = " << start << ". i = " << i << ". " << str.substr(start, i).c_str() << endl;
        string substring = str.substr(start, i);
        if (IsEvenlySplit(substring))
        {
            cout << "'" << str.c_str() << "' is evenly split around '" << substring.c_str() << "'." << endl;
            isSplit = true;
            break;
        }   
    }

    return isSplit;
}

int main()
{
    string str = "1538023";

    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (CheckIfArrayIsSplit(str, i))
            break;
    }

    int arr[7][7] = {};
    for (int i = 0; i < 7; i++)
        arr[i][i] = str[i] - '0';

    for (int i = 0; i < 7; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            int len = j - i;
            int mid = len / 2;

            // cout << arr[i][j - mid] << arr[j - mid + 1][j - mid] << endl;
            arr[i][j] = arr[i][j - mid] + arr[j][i];
            // cout << arr[i][j] << ", " << i << ", " << j << ", " << mid << ", " << len << endl;

            cout << arr[i][j] << " ";
        }
        //cout << endl;
    }   

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}
