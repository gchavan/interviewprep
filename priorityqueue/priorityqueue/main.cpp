#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

template<typename T>
class Compare
{
private:
    double value;

public:
    bool operator()(const T& a, const T& b)
    {
        return fabs(a - value) < fabs(b - value);
    }
};

vector<char> getNumberToCharMap()
{
    return vector<char>({'a', 'b', 'c'});
}

int main()
{
    map<char, int> hashMap;
    cout << hashMap['a'] << endl;
    /*hashMap

    for (auto i : getNumberToCharMap())
        cout << i  << endl;*/

    int arr[] = {1, 2, 3, 4, 5};

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;

    for (auto i: arr)
    {
        maxHeap.push(i);
        minHeap.push(i);
    }

    maxHeap.emplace(6);
    minHeap.emplace(6);

    cout << "Max Heap.." << endl;
    while (!maxHeap.empty())
    {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    cout << "Min Heap.." << endl;
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}