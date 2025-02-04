#define BOOST_TEST_MODULE FindPivotIndexTests
#include <boost/test/included/unit_test.hpp>
#include <vector>
#include "functions.h" // Ensure this file contains the definition of `Solution` class

Solution solution;

BOOST_AUTO_TEST_CASE(TestCase1)
{
    std::vector<int> nums = {1, 7, 3, 6, 5, 6};
    BOOST_CHECK_EQUAL(solution.pivotIndex(nums), 3);
}

BOOST_AUTO_TEST_CASE(TestCase2)
{
    std::vector<int> nums = {1, 2, 3};
    BOOST_CHECK_EQUAL(solution.pivotIndex(nums), -1);
}

BOOST_AUTO_TEST_CASE(TestCase3)
{
    std::vector<int> nums = {2, 1, -1};
    BOOST_CHECK_EQUAL(solution.pivotIndex(nums), 0);
}

BOOST_AUTO_TEST_CASE(TestCase4)
{
    std::vector<int> nums = {0, 0, 0, 0};
    BOOST_CHECK_EQUAL(solution.pivotIndex(nums), 0);
}

BOOST_AUTO_TEST_CASE(TestCase5)
{
    std::vector<int> nums = {-1, -1, -1, -1, -1, 0};
    BOOST_CHECK_EQUAL(solution.pivotIndex(nums), 2);
}

BOOST_AUTO_TEST_CASE(TestCase6)
{
    std::vector<int> nums = {-1, -1, -1, -1, 0, 1};
    BOOST_CHECK_EQUAL(solution.pivotIndex(nums), 1);
}

BOOST_AUTO_TEST_CASE(TestCase7)
{
    std::vector<int> nums = {-1, -1, 0, -1, -1, -1};
    BOOST_CHECK_EQUAL(solution.pivotIndex(nums), 3);
}
