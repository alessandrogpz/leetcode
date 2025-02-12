#define BOOST_TEST_MODULE 2390.RemovingStarsFromAString
#include <boost/test/included/unit_test.hpp>
#include "functions.h" // Contains the declaration of Solution and removeStars

Solution solution;

BOOST_AUTO_TEST_CASE(test_example1)
{
    // Example 1:
    // Input: "leet**cod*e"
    // Expected Output: "lecoe"
    std::string s = "leet**cod*e";
    std::string expected = "lecoe";
    BOOST_CHECK_EQUAL(solution.removeStars_1(s), expected);
}

BOOST_AUTO_TEST_CASE(test_example2)
{
    // Example 2:
    // Input: "erase*****"
    // Expected Output: "" (empty string)
    std::string s = "erase*****";
    std::string expected = "";
    BOOST_CHECK_EQUAL(solution.removeStars_1(s), expected);
}

BOOST_AUTO_TEST_CASE(test_no_stars)
{
    // Test when there are no stars.
    // Input: "leetcode" remains unchanged.
    std::string s = "leetcode";
    std::string expected = "leetcode";
    BOOST_CHECK_EQUAL(solution.removeStars_1(s), expected);
}

BOOST_AUTO_TEST_CASE(test_all_stars_removal)
{
    // Test where every non-star character is removed.
    // Input: "a*b*c*" → Each star removes the letter to its left.
    // Expected Output: "" (empty string)
    std::string s = "a*b*c*";
    std::string expected = "";
    BOOST_CHECK_EQUAL(solution.removeStars_1(s), expected);
}

BOOST_AUTO_TEST_CASE(test_custom)
{
    // A custom test case:
    // Input: "ab**c"
    // Simulation:
    //   - The first star (at index 2) removes the closest left letter 'b' → "a*c"
    //   - The next star (now at index 1) removes 'a' → "c"
    // Expected Output: "c"
    std::string s = "ab**c";
    std::string expected = "c";
    BOOST_CHECK_EQUAL(solution.removeStars_1(s), expected);
}
