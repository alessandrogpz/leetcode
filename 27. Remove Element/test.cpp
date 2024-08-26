#define BOOST_TEST_MODULE remove - element
#include <boost/test/included/unit_test.hpp>

#include <algorithm>
#include "functions.h"

BOOST_AUTO_TEST_SUITE(RemoveElementTests)

BOOST_AUTO_TEST_CASE(TestRemoveElementCase1)
{
    std::vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int k = removeElement(nums, val);
    std::vector<int> expectedNums = {2, 2};
    BOOST_TEST(k == expectedNums.size());
    std::sort(nums.begin(), nums.begin() + k);
    BOOST_TEST(nums == expectedNums);
}

BOOST_AUTO_TEST_CASE(TestRemoveElementCase3)
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int val = 6;
    int k = removeElement(nums, val);
    std::vector<int> expectedNums = {1, 2, 3, 4, 5};
    BOOST_TEST(k == expectedNums.size());
    std::sort(nums.begin(), nums.begin() + k);
    BOOST_TEST(nums == expectedNums);
}

BOOST_AUTO_TEST_CASE(TestRemoveElementCase4)
{
    std::vector<int> nums = {1, 1, 1, 1, 1};
    int val = 1;
    int k = removeElement(nums, val);
    std::vector<int> expectedNums = {};
    BOOST_TEST(k == expectedNums.size());
    BOOST_TEST(nums == expectedNums);
}

BOOST_AUTO_TEST_CASE(TestRemoveElementCase5)
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int val = 1;
    int k = removeElement(nums, val);
    std::vector<int> expectedNums = {2, 3, 4, 5};
    BOOST_TEST(k == expectedNums.size());
    std::sort(nums.begin(), nums.begin() + k);
    BOOST_TEST(nums == expectedNums);
}

BOOST_AUTO_TEST_CASE(TestRemoveElementCase6)
{
    std::vector<int> nums = {};
    int val = 1;
    int k = removeElement(nums, val);
    std::vector<int> expectedNums = {};
    BOOST_TEST(k == expectedNums.size());
    BOOST_TEST(nums == expectedNums);
}

BOOST_AUTO_TEST_CASE(TestRemoveElementCase7)
{
    std::vector<int> nums = {1};
    int val = 1;
    int k = removeElement(nums, val);
    std::vector<int> expectedNums = {};
    BOOST_TEST(k == expectedNums.size());
    BOOST_TEST(nums == expectedNums);
}

BOOST_AUTO_TEST_SUITE_END()