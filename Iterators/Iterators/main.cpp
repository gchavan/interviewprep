#include "Headers.h"

#define PrintContainer(str, c) \
    cout << endl << str << endl; \
    for (auto i : c) \
        cout << i << " "; \
    cout << endl; \

int main()
{
    int arr[] = { 1, 9, 7, 4, 8, 5, 2, 10, 6, 3, 8, 4, 10, 3, 1 };

    set<int> s(begin(arr), end(arr));
    cout << "Set size: " << s.size() << endl;

    vector<int> v(begin(arr), end(arr));
    cout << "Vector size: " << v.size() << endl;

    sort(begin(arr), end(arr));
    PrintContainer("Sorting Array... ", arr);

    PrintContainer("Printing Set... ", s);

    PrintContainer("Printing Vector... ", v);

    sort(rbegin(v), rend(v));
    PrintContainer("Reverse Sorting Vector... ", v);

    auto start = unique(begin(v), end(v));
    v.erase(start, v.end());
    PrintContainer("Removing Duplicates from Vector... ", v);

    cout << endl << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}