#define BOOST_TEST_MODULE 394.DecodeString
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution;

BOOST_AUTO_TEST_CASE(test_decodeString_example1)
{
    // Example 1:
    // Input: "3[a]2[bc]"
    // Expected Output: "aaabcbc"
    std::string input = "3[a]2[bc]";
    std::string expected = "aaabcbc";
    std::string output = solution.decodeString(input);
    BOOST_CHECK_EQUAL(output, expected);
}

BOOST_AUTO_TEST_CASE(test_decodeString_example2)
{
    // Example 2:
    // Input: "3[a2[c]]"
    // Expected Output: "accaccacc"
    std::string input = "3[a2[c]]";
    std::string expected = "accaccacc";
    std::string output = solution.decodeString(input);
    BOOST_CHECK_EQUAL(output, expected);
}

BOOST_AUTO_TEST_CASE(test_decodeString_example3)
{
    // Example 3:
    // Input: "2[abc]3[cd]ef"
    // Expected Output: "abcabccdcdcdef"
    std::string input = "2[abc]3[cd]ef";
    std::string expected = "abcabccdcdcdef";
    std::string output = solution.decodeString(input);
    BOOST_CHECK_EQUAL(output, expected);
}
