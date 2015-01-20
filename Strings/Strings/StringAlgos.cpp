#include "Headers.h"

void inplace_reverse(char* str)
{
    cout << "Original string: " << str << endl;

    reverse_string(str, 0, strlen(str) - 1);

    cout << "Reversed string: " << str << endl;

    reverse_string_words(str);
}

void reverse_string(char* str, int begin, int end)
{
    while (begin < end)
    {
        char temp = str[begin];
        str[begin] = str[end];
        str[end] = temp;

        begin++;
        end--;
    }
}

void reverse_string_words(char* str)
{
    int len = strlen(str);
    int start = 0;

    for (int i = 0; i < len;)
    {
        while (str[i] != ' ' && str[i] != '\0')
        {
            i++;
        }

        reverse_string(str, start, i - 1);

        start = i + 1;
        i++;
    }

    reverse_string(str, start, len - 1);

    cout << "Words reversed string: " << str << endl;
}