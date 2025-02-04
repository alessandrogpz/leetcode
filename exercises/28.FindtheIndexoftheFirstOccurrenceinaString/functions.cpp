#include "functions.h"

int Solution::strStr(std::string haystack, std::string needle)
{
    size_t found = haystack.find(needle);
    if (found != std::string::npos)
    {
        return found;
    }
    return -1;
}