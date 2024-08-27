// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

// Constraints:
// 1 <= haystack.length, needle.length <= 104
// haystack and needle consist of only lowercase English characters.

#include <iostream>
#include <string>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        size_t found = haystack.find(needle);
        if (found != std::string::npos)
        {
            return found;
        }
        return -1;
    }
};

int main()
{

    std::string str1 = "mystringmy";
    std::string str2 = "str";
    std::string str3 = "ab";

    Solution solution;

    std::cout << solution.strStr(str1, str2) << std::endl;
    std::cout << solution.strStr(str1, str3) << std::endl;

    return 0;
}