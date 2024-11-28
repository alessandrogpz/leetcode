#include "functions.h"

std::string Solution::mergeAlternately(std::string word1, std::string word2)
{

    std::string mergedString = "";
    size_t i = 0;

    while (i < word1.size() || i < word2.size())
    {
        if (word1.size() > i)
            mergedString.push_back(word1[i]);

        if (word2.size() > i)
            mergedString.push_back(word2[i]);

        ++i;
    }

    return mergedString;
}
