#include <iostream>
#include <vector>

using namespace std;

// #define DEBUG 0

enum Paranthesis
{
    Open,
    Close
};

void OpenParanthesis(int& open, int& close, int& currOpen, int& currClose);
void CloseParanthesis(int& open, int& close, int& currOpen, int& currClose);
void PrintParanthesis(int count, Paranthesis type);

int main()
{
    int open = 3;
    int close = 3;
    int currOpen = 0;
    int currClose = 0;

    OpenParanthesis(open, close, currOpen, currClose);

    cout << endl << "Press any key to continue..." << endl;
    cin.get();

    return 0;
}

void PrintParanthesis(int count, Paranthesis type)
{
    char paranthesis = type == Paranthesis::Open ? '(' : ')';
    for (int i = 0; i < count; i++)
    {
        cout << paranthesis;
    }
}

void OpenParanthesis(int& open, int& close, int& currOpen, int& currClose)
{
    if (open < 1 || currOpen >= open)
    {
        return;
    }

    int maxOpen = open - currOpen;
    for (int i = maxOpen; i > 0 && currOpen < open; i--)
    {
        // PrintParanthesis(i, Paranthesis::Open);

        currOpen += i;
        CloseParanthesis(open, close, currOpen, currClose);

        currOpen = 0;
        currClose = 0;
        cout << endl;
    }
}

void CloseParanthesis(int& open, int& close, int& currOpen, int& currClose)
{
    if (close < 1 || currClose >= close)
    {
        return;
    }

    int tempCurrOpen = currOpen;
    int maxClosed = close - currClose;
    for (int i = 0; i < tempCurrOpen; i++)
    {
        PrintParanthesis(tempCurrOpen, Paranthesis::Open);

        // if (i <= currOpen)
        {
            PrintParanthesis(i, Paranthesis::Close);

            currClose += i;
            OpenParanthesis(open, close, currOpen, currClose);
        }
    }
}