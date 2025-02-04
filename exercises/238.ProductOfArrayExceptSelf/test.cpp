#define BOOST_TEST_MODULE ProductOfArrayExceptSelfTest
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

BOOST_AUTO_TEST_CASE(TestExample1)
{
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> expected = {24, 12, 8, 6};                 // Matches current implementation
    std::vector<int> result = solution.productExceptSelf(nums); // Store result

    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(TestExample2)
{
    Solution solution;
    std::vector<int> nums = {-1, 1, 0, -3, 3};
    std::vector<int> expected = {0, 0, 9, 0, 0};                // Matches current implementation
    std::vector<int> result = solution.productExceptSelf(nums); // Store result

    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(TestSmallInput)
{
    Solution solution;
    std::vector<int> nums = {2, 3};
    std::vector<int> expected = {3, 2};                         // Matches current implementation
    std::vector<int> result = solution.productExceptSelf(nums); // Store result

    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(TestAllPositive)
{
    Solution solution;
    std::vector<int> nums = {5, 10, 15, 20};
    std::vector<int> expected = {3000, 1500, 1000, 750};        // Matches current implementation
    std::vector<int> result = solution.productExceptSelf(nums); // Store result

    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(TestAllZeros)
{
    Solution solution;
    std::vector<int> nums = {0, 0, 0, 0};
    std::vector<int> expected = {0, 0, 0, 0};                   // Matches current implementation
    std::vector<int> result = solution.productExceptSelf(nums); // Store result

    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(TestSingleZero)
{
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 0, 5};
    std::vector<int> expected = {0, 0, 0, 30, 0};               // Matches current implementation
    std::vector<int> result = solution.productExceptSelf(nums); // Store result

    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(TestNegativeNumbers)
{
    Solution solution;
    std::vector<int> nums = {-2, -3, -4, -5};
    std::vector<int> expected = {-60, -40, -30, -24};           // Matches current implementation
    std::vector<int> result = solution.productExceptSelf(nums); // Store result

    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}
