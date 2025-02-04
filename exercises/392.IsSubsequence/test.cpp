#define BOOST_TEST_MODULE 392_IsSubsequence
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution; // Global instance of the Solution class

BOOST_AUTO_TEST_CASE(test_basic_cases)
{
    bool test_basic_case_1 = solution.isSubsequence("abc", "ahbgdc");
    bool test_basic_case_2 = solution.isSubsequence("axc", "ahbgdc");
    BOOST_CHECK_EQUAL(test_basic_case_1, true);
    BOOST_CHECK_EQUAL(test_basic_case_2, false);
}

BOOST_AUTO_TEST_CASE(test_edge_cases)
{
    BOOST_CHECK_EQUAL(solution.isSubsequence("", "ahbgdc"), true); // Empty string is always a subsequence
    BOOST_CHECK_EQUAL(solution.isSubsequence("abc", ""), false);   // Non-empty s cannot be a subsequence of an empty t
    BOOST_CHECK_EQUAL(solution.isSubsequence("a", "a"), true);     // Single-character match
    BOOST_CHECK_EQUAL(solution.isSubsequence("a", "b"), false);    // Single-character no match
}

BOOST_AUTO_TEST_CASE(test_large_cases)
{
    std::string largeS = "abcdefghij";
    std::string largeT = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzzabcdefghij";
    BOOST_CHECK_EQUAL(solution.isSubsequence(largeS, largeT), true);

    std::string largeS2 = "zx";
    BOOST_CHECK_EQUAL(solution.isSubsequence(largeS2, largeT), false);
}

BOOST_AUTO_TEST_CASE(test_repeated_characters)
{
    BOOST_CHECK_EQUAL(solution.isSubsequence("aaa", "aaabaa"), true);
    BOOST_CHECK_EQUAL(solution.isSubsequence("aaa", "baaa"), true);
    BOOST_CHECK_EQUAL(solution.isSubsequence("aaa", "babba"), false);
}

BOOST_AUTO_TEST_CASE(test_full_subsequence)
{
    BOOST_CHECK_EQUAL(solution.isSubsequence("ahbgdc", "ahbgdc"), true);    // Exact match
    BOOST_CHECK_EQUAL(solution.isSubsequence("ahbgdc", "ahbgdcabc"), true); // Prefix match
}
