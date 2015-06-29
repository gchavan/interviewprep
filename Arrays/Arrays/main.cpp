#include "Headers.h"

/*
Function to find Number of customers who could not get a computer
Write a function “runCustomerSimulation” that takes following two inputs
a) An integer ‘n': total number of computers in a cafe and a string:
b) A sequence of uppercase letters ‘seq': Letters in the sequence occur in pairs.
   The first occurrence indicates the arrival of a customer; the second indicates the departure of that same customer.
*/
int CheckCustomersWithoutComputer(int computersAvailable, const char* customerEntries)
{
    int temp = computersAvailable;
    int customerMap[26] = {};
    int len = strlen(customerEntries);
    int customersWithoutComputers = 0;

    for (int i = 0; i < len; i++)
    {
        int index = customerEntries[i] - 'A';
        if (customerMap[index] == 0)
        {
            customerMap[index] = 1;

            if (temp > 0)
            {
                customerMap[index] = 2;
                temp--;
            }
            else
            {
                customersWithoutComputers++;
            }
        }
        else
        {
            if (customerMap[index] == 2)
                temp++;

            customerMap[index] = 0;
        }
    }

    return customersWithoutComputers;
}

void runCustomerSimulation()
{
    cout << "Running Customer Simulation..." << endl;
    cout << "'" << "ABBAJJKZKZ" << "' Customers without computer " << CheckCustomersWithoutComputer(2, "ABBAJJKZKZ") << endl;
    cout << "'" << "GACCBDDBAGEE" << "' Customers without computer " << CheckCustomersWithoutComputer(3, "GACCBDDBAGEE") << endl;
    cout << "'" << "GACCBGDDBAEE" << "' Customers without computer " << CheckCustomersWithoutComputer(3, "GACCBGDDBAEE") << endl;
    cout << "'" << "ABCBCA" << "' Customers without computer " << CheckCustomersWithoutComputer(1, "ABCBCA") << endl;
    cout << "'" << "ABCBCADEED" << "' Customers without computer " << CheckCustomersWithoutComputer(1, "ABCBCADEED") << endl;
}

/*
Print all possible strings that can be made by placing spaces
Given a string you need to print all possible strings that can be made by placing spaces(zero or one) in between them.

Input:  str[] = "ABC"
    Output : ABC
             AB C
             A BC
             A B C
*/
void PrintStringCombinationsWithSpaces(const char* str, int start, vector<string>& strings)
{
    if (!str)
        throw new exception("Invalid string passed.");

    int len = strlen(str);
    
    if ((len-start) < 2)
        return;

    if ((len - start) == 2)
    {
        string str1;
        str1 += str[start];
        str1 += '_';
        str1 += str[start + 1];
        strings.push_back(str1);
        return;
    }

    PrintStringCombinationsWithSpaces(str, start + 1, strings);

    vector<string> prevStrings;
    for each (auto s in strings)
    {
        prevStrings.push_back(s);
    }

    strings.clear();
    
    char currChar = str[start];

    string tempString;
    for (int i = start + 1; i < len; i++)
        tempString += str[i];

    {
        string newString;
        newString += currChar;
        newString += '_';
        newString.append(tempString);
        strings.push_back(newString);
    }

    for each (auto s in prevStrings)
    {
        string newString;
        newString += currChar;
        newString += '_';
        newString.append(s);
        strings.push_back(newString);
    }

    for each (auto s in prevStrings)
    {
        string newString;
        newString += currChar;
        newString.append(s);
        strings.push_back(newString);
    }
}

void PrintStrings(vector<string>& strings)
{
    for each (auto s in strings)
    {
        cout << " ==> " << s.c_str() << endl;
    }
}

void PrintStringCombinationsWithSpaces()
{
    vector<string> strings;

    PrintStringCombinationsWithSpaces("AB", 0, strings);
    cout << "Cobinations for 'AB' with spaces are:" << endl;
    PrintStrings(strings);
    strings.clear();

    PrintStringCombinationsWithSpaces("ABC", 0, strings);
    cout << "Cobinations for 'ABC' with spaces are:" << endl;
    PrintStrings(strings);
    strings.clear();

    PrintStringCombinationsWithSpaces("ABCD", 0, strings);
    cout << "Cobinations for 'ABCD' with spaces are:" << endl;
    PrintStrings(strings);
    strings.clear();

    PrintStringCombinationsWithSpaces("ABCDE", 0, strings);
    cout << "Cobinations for 'ABCDE' with spaces are:" << endl;
    PrintStrings(strings);
    strings.clear();
}

/*
Given two positive integers n and k, print all increasing sequences of length k such that 
the elements in every sequence are from first n natural numbers.

Examples:

Input : k = 2, n = 3
Output : 1 2
         1 3
         2 3

Input : k = 5, n = 5
Output : 1 2 3 4 5

Input : k = 3, n = 5
Output : 1 2 3
         1 2 4
         1 2 5
         1 3 4
         1 3 5
         1 4 5
         2 3 4
         2 3 5
         2 4 5
         3 4 5
*/

void PrintIncreasingSequences(int k, int n, int start, vector<int>& combinations)
{
    if (k == 0)
    {
        for each(auto i in combinations)
            cout << i;
        cout << endl;
        return;
    }

    for (int i = start; i <= (n - k + 1); i++)
    {
        combinations.push_back(i);
        PrintIncreasingSequences(k - 1, n, i + 1, combinations);
        combinations.pop_back();
    }
}

void PrintIncreasingSequences()
{
    cout << "Print Increasing Sequences..." << endl;

    vector<int> combinations;
    cout << "IncreasingSequences (2, 3): " << endl;
    PrintIncreasingSequences(2, 3, 1, combinations);
    cout << endl;

    cout << "IncreasingSequences (5, 5): " << endl;
    PrintIncreasingSequences(5, 5, 1, combinations);
    cout << endl;

    cout << "IncreasingSequences (3, 5): " << endl;
    PrintIncreasingSequences(3, 5, 1, combinations);
    cout << endl;
}

int main()
{
    runCustomerSimulation();

    PrintStringCombinationsWithSpaces();

    PrintIncreasingSequences();

    cout << endl << "press any key to continue..." << endl;
    cin.get();
    return 0;
}