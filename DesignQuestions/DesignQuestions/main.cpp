#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

string g_charSet = "abcdefghijklmnopqrstuvwxyz0123456789";
unsigned int g_base = g_charSet.size();
unordered_map<char, int> g_charIndexMap;

void encode(long value)
{
    string encodedString;

    long tempValue = value;
    while (tempValue > 0)
    {
        encodedString.insert(encodedString.begin(), g_charSet[tempValue % g_base]);
        tempValue /= g_base;
    }

    cout << "Encode(" << value << ") = " << encodedString.c_str() << endl;
}

void decode(string value)
{
    long decodedValue = 0;

    for (size_t i = 0; i < value.size(); i++)
    {
        decodedValue = decodedValue * g_base + g_charIndexMap[value[i]];
    }

    cout << "Decode(" << value.c_str() << ") = " << decodedValue << endl;
}

int main()
{
    for (size_t i = 0; i < g_base; i++)
        g_charIndexMap[g_charSet[i]] = i;

    long value = 1234;
    encode(1234);
    decode("8k");

    for (int i = 37; i <= 37; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << i << " * " << j << " = " << (i*j) << endl;
        }

        cout << endl;
    }

    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}