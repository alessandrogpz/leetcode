#define BOOST_TEST_MODULE test_longestCommonPrefix
#include <boost/test/included/unit_test.hpp>

#include "functions.h"

BOOST_AUTO_TEST_CASE(test_longestCommonPrefix_basic)
{
    // Test case 1: Example from the problem statement
    {
        std::vector<std::string> strs = {"flower", "flow", "flight"};
        BOOST_CHECK_EQUAL(longestCommonPrefix(strs), "fl");
    }
    // Test case 2: No common prefix
    {
        std::vector<std::string> strs = {"dog", "racecar", "car"};
        BOOST_CHECK_EQUAL(longestCommonPrefix(strs), "");
    }
    // Test case 3: Single string
    {
        std::vector<std::string> strs = {"alone"};
        BOOST_CHECK_EQUAL(longestCommonPrefix(strs), "alone");
    }
    // Test case 4: All strings the same
    {
        std::vector<std::string> strs = {"test", "test", "test"};
        BOOST_CHECK_EQUAL(longestCommonPrefix(strs), "test");
    }
    // Test case 5: Partial common prefix
    {
        std::vector<std::string> strs = {"interspecies", "interstellar", "interstate"};
        BOOST_CHECK_EQUAL(longestCommonPrefix(strs), "inters");
    }
    // Test case 6: Empty string in the list
    {
        std::vector<std::string> strs = {"", "empty", "emma"};
        BOOST_CHECK_EQUAL(longestCommonPrefix(strs), "");
    }
    // Test case 7: Mixed single character strings
    {
        std::vector<std::string> strs = {"a", "ab", "abc"};
        BOOST_CHECK_EQUAL(longestCommonPrefix(strs), "a");
    }
}

BOOST_AUTO_TEST_CASE(test_longestCommonPrefix_1_basic)
{
    // Repeat the same set of tests for longestCommonPrefix_1 to ensure consistency

    // Test case 1: Example from the problem statement
    {
        std::vector<std::string> strs = {"flower", "flow", "flight"};
        BOOST_CHECK_EQUAL(longestCommonPrefix_1(strs), "fl");
    }
    // Test case 2: No common prefix
    {
        std::vector<std::string> strs = {"dog", "racecar", "car"};
        BOOST_CHECK_EQUAL(longestCommonPrefix_1(strs), "");
    }
    // Test case 3: Single string
    {
        std::vector<std::string> strs = {"alone"};
        BOOST_CHECK_EQUAL(longestCommonPrefix_1(strs), "alone");
    }
    // Test case 4: All strings the same
    {
        std::vector<std::string> strs = {"test", "test", "test"};
        BOOST_CHECK_EQUAL(longestCommonPrefix_1(strs), "test");
    }
    // Test case 5: Partial common prefix
    {
        std::vector<std::string> strs = {"interspecies", "interstellar", "interstate"};
        BOOST_CHECK_EQUAL(longestCommonPrefix_1(strs), "inters");
    }
    // Test case 6: Empty string in the list
    {
        std::vector<std::string> strs = {"", "empty", "emma"};
        BOOST_CHECK_EQUAL(longestCommonPrefix_1(strs), "");
    }
    // Test case 7: Mixed single character strings
    {
        std::vector<std::string> strs = {"a", "ab", "abc"};
        BOOST_CHECK_EQUAL(longestCommonPrefix_1(strs), "a");
    }
}
