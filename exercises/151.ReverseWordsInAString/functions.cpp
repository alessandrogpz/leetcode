
#include "functions.h"

std::string Solution::reverseWords(std::string s)
{
    std::string word = "";
    std::string reverseWords = "";
    size_t i = s.length();

    // Trim trailing spaces
    while (i > 0 && s[i - 1] == ' ')
    {
        i--;
    }

    while (i > 0)
    {
        i--;

        // Skip multiple spaces
        while (i > 0 && s[i] == ' ')
        {
            i--;
        }

        // Extract word
        while (i > 0 && s[i] != ' ')
        {
            word = s[i] + word;
            i--;
        }

        // Include the first character (when i == 0)
        if (s[i] != ' ')
        {
            word = s[i] + word;
        }

        // Append word to the result
        if (!word.empty())
        {
            if (!reverseWords.empty())
            {
                reverseWords += " "; // Add space between words
            }
            reverseWords += word;
        }

        word = ""; // Reset for next word
    }

    return reverseWords;
}
