#include "functions.h"

std::string Solution::decodeString(std::string s)
{
    std::stack<int> countStack;
    std::stack<std::string> stringStack;
    std::string current;
    int k = 0;

    for (char c : s)
    {
        if (std::isdigit(c))
        {
            // Build the number k (might be multiple digits)
            k = k * 10 + (c - '0');
        }
        else if (c == '[')
        {
            // Push the current number and string onto their stacks.
            countStack.push(k);
            stringStack.push(current);
            // Reset current string and k for the new context.
            current = "";
            k = 0;
        }
        else if (c == ']')
        {
            // Pop the number and previous string.
            int repeatTimes = countStack.top();
            countStack.pop();
            std::string prevString = stringStack.top();
            stringStack.pop();

            // Build the new string by repeating the current string.
            std::string decoded = "";
            for (int i = 0; i < repeatTimes; i++)
            {
                decoded += current;
            }
            // Append the decoded string to the previous string.
            current = prevString + decoded;
        }
        else
        {
            // Append regular characters to the current string.
            current.push_back(c);
        }
    }

    return current;
}