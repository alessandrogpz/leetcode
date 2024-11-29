
#include "functions.h"

std::string Solution::gcdOfStrings(std::string str1, std::string str2)
{
    if (str1 + str2 != str2 + str1)
    {
        return "";
    }
    else
    {
        int len1 = str1.size();
        int len2 = str2.size();

        while (len2 != 0)
        {
            int temp = len2;
            len2 = len1 % len2;
            len1 = temp;
        }

        return str1.substr(0, len1);
    }
}