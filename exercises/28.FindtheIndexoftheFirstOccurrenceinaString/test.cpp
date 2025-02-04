#define BOOST_TEST_MODULE strStrTest
#include <boost/test/included/unit_test.hpp>
#include <string>
#include "functions.h"

BOOST_AUTO_TEST_CASE(test_needle_at_beginning)
{
    Solution sol;
    std::string haystack = "sadbutsad";
    std::string needle = "sad";
    int result = sol.strStr(haystack, needle);
    BOOST_CHECK_EQUAL(result, 0);
}

BOOST_AUTO_TEST_CASE(test_needle_not_found)
{
    Solution sol;
    std::string haystack = "leetcode";
    std::string needle = "leeto";
    int result = sol.strStr(haystack, needle);
    BOOST_CHECK_EQUAL(result, -1);
}

BOOST_AUTO_TEST_CASE(test_needle_empty)
{
    Solution sol;
    std::string haystack = "hello";
    std::string needle = "";
    int result = sol.strStr(haystack, needle);
    // According to the standard behavior of std::string::find, an empty needle returns 0.
    BOOST_CHECK_EQUAL(result, 0);
}

BOOST_AUTO_TEST_CASE(test_haystack_equals_needle)
{
    Solution sol;
    std::string haystack = "hello";
    std::string needle = "hello";
    int result = sol.strStr(haystack, needle);
    BOOST_CHECK_EQUAL(result, 0);
}

BOOST_AUTO_TEST_CASE(test_needle_in_middle)
{
    Solution sol;
    std::string haystack = "mississippi";
    std::string needle = "issip";
    int result = sol.strStr(haystack, needle);
    BOOST_CHECK_EQUAL(result, 4);
}

BOOST_AUTO_TEST_CASE(test_needle_longer_than_haystack)
{
    Solution sol;
    std::string haystack = "abc";
    std::string needle = "abcd";
    int result = sol.strStr(haystack, needle);
    BOOST_CHECK_EQUAL(result, -1);
}

BOOST_AUTO_TEST_CASE(test_needle_not_in_haystack)
{
    Solution sol;
    std::string haystack = "abc";
    std::string needle = "d";
    int result = sol.strStr(haystack, needle);
    BOOST_CHECK_EQUAL(result, -1);
}
