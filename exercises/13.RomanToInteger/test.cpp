#define BOOST_TEST_MODULE boost_test_sequence
#include <boost/test/included/unit_test.hpp>
#include <vector>
#include <string>
#include "functions.h"

BOOST_AUTO_TEST_CASE(test_romanToInt_basic_cases)
{
    // Test the basic known Roman numerals
    BOOST_CHECK_EQUAL(romanToInt("III"), 3);
    BOOST_CHECK_EQUAL(romanToInt("LVIII"), 58);
    BOOST_CHECK_EQUAL(romanToInt("MCMXCIV"), 1994);
}

BOOST_AUTO_TEST_CASE(test_romanToInt_additional_cases)
{
    // Edge case: smallest Roman numeral
    BOOST_CHECK_EQUAL(romanToInt("I"), 1);

    // A few random tests
    BOOST_CHECK_EQUAL(romanToInt("IX"), 9);
    BOOST_CHECK_EQUAL(romanToInt("XL"), 40);
    BOOST_CHECK_EQUAL(romanToInt("XC"), 90);
    BOOST_CHECK_EQUAL(romanToInt("CD"), 400);
    BOOST_CHECK_EQUAL(romanToInt("CM"), 900);

    // Large valid Roman numeral
    BOOST_CHECK_EQUAL(romanToInt("MMMCMXCIX"), 3999); // 3999 is often considered the max standard Roman numeral
}

BOOST_AUTO_TEST_CASE(test_romanToInt2_basic_cases)
{
    // Repeat tests for the second approach
    BOOST_CHECK_EQUAL(romanToInt2("III"), 3);
    BOOST_CHECK_EQUAL(romanToInt2("LVIII"), 58);
    BOOST_CHECK_EQUAL(romanToInt2("MCMXCIV"), 1994);
}

BOOST_AUTO_TEST_CASE(test_romanToInt2_additional_cases)
{
    BOOST_CHECK_EQUAL(romanToInt2("I"), 1);
    BOOST_CHECK_EQUAL(romanToInt2("IX"), 9);
    BOOST_CHECK_EQUAL(romanToInt2("XL"), 40);
    BOOST_CHECK_EQUAL(romanToInt2("XC"), 90);
    BOOST_CHECK_EQUAL(romanToInt2("CD"), 400);
    BOOST_CHECK_EQUAL(romanToInt2("CM"), 900);
    BOOST_CHECK_EQUAL(romanToInt2("MMMCMXCIX"), 3999);
}

BOOST_AUTO_TEST_CASE(test_string_loop)
{
    // Simple test for the string_loop function
    std::string s = "HelloWorld";
    BOOST_CHECK_EQUAL(string_loop(s), 10);
}
