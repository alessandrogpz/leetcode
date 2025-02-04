
#define BOOST_TEST_MODULE 345.ReverseVowelsOfAString
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution; // Instantiate the class containing reverseVowels

BOOST_AUTO_TEST_CASE(TestExample1)
{
    std::string input = "IceCreAm";
    std::string expected = "AceCreIm";
    BOOST_CHECK_EQUAL(solution.reverseVowels2(input), expected);
}

BOOST_AUTO_TEST_CASE(TestExample2)
{
    std::string input = "leetcode";
    std::string expected = "leotcede";
    BOOST_CHECK_EQUAL(solution.reverseVowels2(input), expected);
}

BOOST_AUTO_TEST_CASE(TestCaseAllVowels)
{
    std::string input = "aeiouAEIOU";
    std::string expected = "UOIEAuoiea";
    BOOST_CHECK_EQUAL(solution.reverseVowels2(input), expected);
}

BOOST_AUTO_TEST_CASE(TestCaseNoVowels)
{
    std::string input = "bcdfg";
    std::string expected = "bcdfg"; // No vowels to swap
    BOOST_CHECK_EQUAL(solution.reverseVowels2(input), expected);
}

BOOST_AUTO_TEST_CASE(TestCaseMixedCharacters)
{
    std::string input = "h3ll0 w0rld";
    std::string expected = "h3ll0 w0rld"; // No vowels, should remain the same
    BOOST_CHECK_EQUAL(solution.reverseVowels2(input), expected);
}

BOOST_AUTO_TEST_CASE(TestCaseSingleCharacter)
{
    std::string input = "a";
    std::string expected = "a"; // Single character remains the same
    BOOST_CHECK_EQUAL(solution.reverseVowels2(input), expected);
}

BOOST_AUTO_TEST_CASE(TestCaseNumbersAndVowels)
{
    std::string input = "h1a2e3i4o5u";
    std::string expected = "h1u2o3i4e5a"; // Only vowels swap positions
    BOOST_CHECK_EQUAL(solution.reverseVowels2(input), expected);
}
