#define BOOST_TEST_MODULE plus - one

#include <boost/test/included/unit_test.hpp>
#include "functions.h"

BOOST_AUTO_TEST_SUITE(plusOneTests)

BOOST_AUTO_TEST_CASE(emptyVectorTest)
{
    std::vector<int> digits{0};
    std::vector<int> expected{1};
    BOOST_TEST(plusOne(digits) == expected);
}

BOOST_AUTO_TEST_CASE(singleDigitTest)
{
    std::vector<int> digits{9};
    std::vector<int> expected{1, 0};
    BOOST_TEST(plusOne(digits) == expected);
}

BOOST_AUTO_TEST_CASE(multipleDigitsNoCarryTest)
{
    std::vector<int> digits{1, 2, 3};
    std::vector<int> expected{1, 2, 4};
    BOOST_TEST(plusOne(digits) == expected);
}

BOOST_AUTO_TEST_CASE(multipleDigitsWithCarryTest)
{
    std::vector<int> digits{9, 9, 9};
    std::vector<int> expected{1, 0, 0, 0};
    BOOST_TEST(plusOne(digits) == expected);
}

BOOST_AUTO_TEST_CASE(multipleDigitsWithCarryAtEndTest)
{
    std::vector<int> digits{1, 9, 9};
    std::vector<int> expected{2, 0, 0};
    BOOST_TEST(plusOne(digits) == expected);
}

BOOST_AUTO_TEST_CASE(allZeroesTest)
{
    std::vector<int> digits{0, 0, 0, 0};
    std::vector<int> expected{0, 0, 0, 1};
    BOOST_TEST(plusOne(digits) == expected);
}

BOOST_AUTO_TEST_CASE(maxDigitsTest)
{
    std::vector<int> digits{9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    std::vector<int> expected{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    BOOST_TEST(plusOne(digits) == expected);
}

BOOST_AUTO_TEST_CASE(multipleDigitsWithLeadingZerosTest)
{
    std::vector<int> digits{0, 0, 1, 2, 3};
    std::vector<int> expected{0, 0, 1, 2, 4};
    BOOST_TEST(plusOne(digits) == expected);
}

BOOST_AUTO_TEST_CASE(singleDigitNoCarryTest)
{
    std::vector<int> digits{5};
    std::vector<int> expected{6};
    BOOST_TEST(plusOne(digits) == expected);
}

BOOST_AUTO_TEST_CASE(singleDigitWithCarryTest)
{
    std::vector<int> digits{9};
    std::vector<int> expected{1, 0};
    BOOST_TEST(plusOne(digits) == expected);
}

BOOST_AUTO_TEST_CASE(multipleDigitsWithMultipleCarriesTest)
{
    std::vector<int> digits{1, 9, 9, 9, 9, 9};
    std::vector<int> expected{2, 0, 0, 0, 0, 0};
    BOOST_TEST(plusOne(digits) == expected);
}

BOOST_AUTO_TEST_SUITE_END()