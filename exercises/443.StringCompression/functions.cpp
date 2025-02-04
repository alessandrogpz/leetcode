
#include "functions.h"

int Solution::compress(std::vector<char> &chars)
{
    std::vector<char> resultArr;

    int i = 0;
    while (i < chars.size())
    {
        char currChar = chars[i];
        int charCount = 0;

        // Count occurrences of the current character
        while (i < chars.size() && chars[i] == currChar)
        {
            ++charCount;
            ++i; // Move to the next character
        }

        // Store the character
        resultArr.push_back(currChar);

        // Store the count if > 1
        if (charCount > 1)
        {
            for (char c : std::to_string(charCount))
            {
                resultArr.push_back(c);
            }
        }
    }

    // Replace chars with the compressed result
    chars.swap(resultArr);

    return chars.size();
};
