#define BOOST_TEST_MODULE ReverseWordsInAStringTest
#include <boost/test/included/unit_test.hpp>
#include "functions.h" // Ensure this contains the function declaration

Solution solution; // Instantiate the class containing reverseWords

BOOST_AUTO_TEST_CASE(TestExample1)
{
    std::string input = "the sky is blue";
    std::string expected = "blue is sky the";
    BOOST_CHECK_EQUAL(solution.reverseWords(input), expected);
}

BOOST_AUTO_TEST_CASE(TestExample2)
{
    std::string input = "  hello world  ";
    std::string expected = "world hello";
    BOOST_CHECK_EQUAL(solution.reverseWords(input), expected);
}

BOOST_AUTO_TEST_CASE(TestExample3)
{
    std::string input = "a good   example";
    std::string expected = "example good a";
    BOOST_CHECK_EQUAL(solution.reverseWords(input), expected);
}

BOOST_AUTO_TEST_CASE(TestSingleWord)
{
    std::string input = "word";
    std::string expected = "word"; // Single word remains unchanged
    BOOST_CHECK_EQUAL(solution.reverseWords(input), expected);
}

BOOST_AUTO_TEST_CASE(TestAllSpaces)
{
    std::string input = "     ";
    std::string expected = ""; // Should remove all spaces
    BOOST_CHECK_EQUAL(solution.reverseWords(input), expected);
}

BOOST_AUTO_TEST_CASE(TestMixedCase)
{
    std::string input = "This IS a TEST";
    std::string expected = "TEST a IS This";
    BOOST_CHECK_EQUAL(solution.reverseWords(input), expected);
}

BOOST_AUTO_TEST_CASE(TestNumbersAndWords)
{
    std::string input = "123 hello 456 world";
    std::string expected = "world 456 hello 123";
    BOOST_CHECK_EQUAL(solution.reverseWords(input), expected);
}

BOOST_AUTO_TEST_CASE(TestTrailingAndLeadingSpaces)
{
    std::string input = "   Keep    it   simple   ";
    std::string expected = "simple it Keep";
    BOOST_CHECK_EQUAL(solution.reverseWords(input), expected);
}

BOOST_AUTO_TEST_CASE(TestLongString)
{
    std::string input = "This is a very long string with multiple words to test the function properly";
    std::string expected = "properly function the test to words multiple with string long very a is This";
    BOOST_CHECK_EQUAL(solution.reverseWords(input), expected);
}
