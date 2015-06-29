#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int applyOp(char op, int b, int a)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            throw new exception("Cannot divide by zero");
        return a / b;
    }
    return 0;
}

bool hasPrecedence(char op1, char op2)
{
    if (op2 == '(' || op2 == ')')
        return false;
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
        return false;
    else
        return true;
}

void parseInfix()
{
    string expression = "10 + 2 * 6";
    // string expression = "6 + 5 * (3 - 2)";

    stack<int> values;
    stack<char> operations;

    for (size_t i = 0; i < expression.size(); i++)
    {
        if (expression[i] != ' ')
        {
            if (expression[i] >= '0' && expression[i] <= '9')
            {
                string intValue;
                while (expression[i] >= '0' && expression[i] <= '9')
                    intValue.push_back(expression[i++]);

                values.push(stoi(intValue));
            }
            
            if (expression[i] == '(')
            {
                operations.push('(');
            }
            else if (expression[i] == ')')
            {
                while (operations.top() != '(')
                {
                    int a = values.top();
                    values.pop();
                    int b = values.top();
                    values.pop();
                    values.push(applyOp(operations.top(), a, b));
                    operations.pop();
                }
                operations.pop();
            }
            else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
            {
                while (!operations.empty() && hasPrecedence(expression[i], operations.top()))
                {
                    int a = values.top();
                    values.pop();
                    int b = values.top();
                    values.pop();
                    values.push(applyOp(operations.top(), a, b));
                    operations.pop();
                }
                operations.push(expression[i]);
            }
        }
    }

    while (!operations.empty() && values.size() > 1)
    {
        int a = values.top();
        values.pop();
        int b = values.top();
        values.pop();
        values.push(applyOp(operations.top(), a, b));
        operations.pop();
    }

    cout << expression.c_str() << " = " << values.top() << endl;
}

void parsePostfix()
{
    // string expression = "48 4 6 * /";
    string expression = "10 2 8 * + 3 -";

    stack<int> values;

    for (size_t i = 0; i < expression.size(); i++)
    {
        if (expression[i] != ' ')
        {
            if (expression[i] >= '0' && expression[i] <= '9')
            {
                string intValue;
                while (expression[i] >= '0' && expression[i] <= '9')
                    intValue.push_back(expression[i++]);

                values.push(stoi(intValue));
            }
            else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
            {
                if (values.size() < 2)
                    throw new exception("Invalid expression.");

                int a = values.top();
                values.pop();
                int b = values.top();
                values.pop();
                values.push(applyOp(expression[i], a, b));
            }
        }
    }

    cout << expression.c_str() << " = " << values.top() << endl;
}

int main()
{
    parseInfix();

    parsePostfix();

    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}