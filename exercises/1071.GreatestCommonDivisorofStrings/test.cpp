
#define BOOST_TEST_MODULE 1071.GreatestCommonDivisorofStrings
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

// Fixture to create an instance of the Solution class for testing
struct SolutionFixture
{
    Solution solution;
};

BOOST_FIXTURE_TEST_CASE(TestCase1, SolutionFixture)
{
    std::string str1 = "ABCABC";
    std::string str2 = "ABC";
    std::string expected = "ABC";
    BOOST_CHECK_EQUAL(solution.gcdOfStrings(str1, str2), expected);
}

BOOST_FIXTURE_TEST_CASE(TestCase2, SolutionFixture)
{
    std::string str1 = "ABABAB";
    std::string str2 = "ABAB";
    std::string expected = "AB";
    BOOST_CHECK_EQUAL(solution.gcdOfStrings(str1, str2), expected);
}

BOOST_FIXTURE_TEST_CASE(TestCase3, SolutionFixture)
{
    std::string str1 = "LEET";
    std::string str2 = "CODE";
    std::string expected = "";
    BOOST_CHECK_EQUAL(solution.gcdOfStrings(str1, str2), expected);
}

BOOST_FIXTURE_TEST_CASE(TestCase4, SolutionFixture)
{
    std::string str1 = "A";
    std::string str2 = "A";
    std::string expected = "A";
    BOOST_CHECK_EQUAL(solution.gcdOfStrings(str1, str2), expected);
}

BOOST_FIXTURE_TEST_CASE(TestCase5, SolutionFixture)
{
    std::string str1 = "AAAAAA";
    std::string str2 = "AAA";
    std::string expected = "AAA";
    BOOST_CHECK_EQUAL(solution.gcdOfStrings(str1, str2), expected);
}

BOOST_FIXTURE_TEST_CASE(TestCase6, SolutionFixture)
{
    std::string str1 = "XYZXYZ";
    std::string str2 = "XYZ";
    std::string expected = "XYZ";
    BOOST_CHECK_EQUAL(solution.gcdOfStrings(str1, str2), expected);
}

BOOST_FIXTURE_TEST_CASE(TestCase7, SolutionFixture)
{
    std::string str1 = "AAAA";
    std::string str2 = "BBBB";
    std::string expected = "";
    BOOST_CHECK_EQUAL(solution.gcdOfStrings(str1, str2), expected);
}

BOOST_FIXTURE_TEST_CASE(TestCase8, SolutionFixture)
{
    std::string str1 = "ABABABAB";
    std::string str2 = "ABAB";
    std::string expected = "ABAB";
    BOOST_CHECK_EQUAL(solution.gcdOfStrings(str1, str2), expected);
}

BOOST_FIXTURE_TEST_CASE(TestCase9, SolutionFixture)
{
    std::string str1 = "";
    std::string str2 = "";
    std::string expected = "";
    BOOST_CHECK_EQUAL(solution.gcdOfStrings(str1, str2), expected);
}

BOOST_FIXTURE_TEST_CASE(TestCase10, SolutionFixture)
{
    std::string str1 = "ABCD";
    std::string str2 = "AB";
    std::string expected = "";
    BOOST_CHECK_EQUAL(solution.gcdOfStrings(str1, str2), expected);
}
