
// 392. Is Subsequence
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:
// Input: s = "abc", t = "ahbgdc"
// Output: true

// Example 2:
// Input: s = "axc", t = "ahbgdc"
// Output: false

// Constraints:
// 0 <= s.length <= 100
// 0 <= t.length <= 104
// s and t consist only of lowercase English letters.

#include <iostream>
#include "functions.h"

int main(int argc, char *argv[])
{
    Solution solution;

    // bool test_basic_case_1 = solution.isSubsequence("abc", "ahbgdc");
    // bool test_basic_case_2 = solution.isSubsequence("axc", "ahbgdc");
    bool test_basic_case_3 = solution.isSubsequence("aaa", "babba");

    return 0;
}
