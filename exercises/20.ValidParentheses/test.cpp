#define BOOST_TEST_MODULE valid - parentheses
#include <boost/test/included/unit_test.hpp>

#include "functions.h"

BOOST_AUTO_TEST_SUITE(BracketValidationTestSuite)

BOOST_AUTO_TEST_CASE(EmptyStringTest)
{
    std::string s = "";
    BOOST_CHECK(isValid_myImplementation(s) == true);
}

BOOST_AUTO_TEST_CASE(SingleBracketTest)
{
    std::string s = "()";
    BOOST_CHECK(isValid_myImplementation(s) == true);
}

BOOST_AUTO_TEST_CASE(MultipleBracketsTest)
{
    std::string s = "([]{})";
    BOOST_CHECK(isValid_myImplementation(s) == true);
}

BOOST_AUTO_TEST_CASE(IncorrectOrderTest)
{
    std::string s = "([)]";
    BOOST_CHECK(isValid_myImplementation(s) == false);
}

BOOST_AUTO_TEST_CASE(UnevenNumberTest)
{
    std::string s = "((())";
    BOOST_CHECK(isValid_myImplementation(s) == false);
}

BOOST_AUTO_TEST_CASE(OpenBracketsOnlyTest)
{
    std::string s = "([{";
    BOOST_CHECK(isValid_myImplementation(s) == false);
}

BOOST_AUTO_TEST_CASE(ClosedBracketsOnlyTest)
{
    std::string s = ")]}";
    BOOST_CHECK(isValid_myImplementation(s) == false);
}

BOOST_AUTO_TEST_CASE(ExtraClosedBracketsTest)
{
    std::string s = "()[]}";
    BOOST_CHECK(isValid_myImplementation(s) == false);
}

BOOST_AUTO_TEST_CASE(ExtraOpenBracketsTest)
{
    std::string s = "{[()]}(";
    BOOST_CHECK(isValid_myImplementation(s) == false);
}

BOOST_AUTO_TEST_CASE(RandomStringTest)
{
    std::string s = "()()[{()()}]";
    BOOST_CHECK(isValid_myImplementation(s) == true);
}

BOOST_AUTO_TEST_SUITE_END()