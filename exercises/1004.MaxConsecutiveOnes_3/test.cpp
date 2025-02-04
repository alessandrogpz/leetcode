#define BOOST_TEST_MODULE 1004.MaxConsecutiveOnes_3
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution;

BOOST_AUTO_TEST_CASE(test_example1)
{
    // Example 1:
    // Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
    // Expected Output: 6
    std::vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    int expected = 6;
    BOOST_CHECK_EQUAL(solution.longestOnes(nums, k), expected);
}

BOOST_AUTO_TEST_CASE(test_example2)
{
    // Example 2:
    // Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
    // Expected Output: 10
    std::vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;
    int expected = 10;
    BOOST_CHECK_EQUAL(solution.longestOnes(nums, k), expected);
}

BOOST_AUTO_TEST_CASE(test_all_ones)
{
    // Test when the array is all ones. Flips are irrelevant.
    std::vector<int> nums = {1, 1, 1, 1, 1};
    int k = 2; // k doesn't matter here since no flip is needed.
    int expected = 5;
    BOOST_CHECK_EQUAL(solution.longestOnes(nums, k), expected);
}

BOOST_AUTO_TEST_CASE(test_all_zeros)
{
    // Test when the array is all zeros.
    // You can flip at most k zeros to ones.
    std::vector<int> nums = {0, 0, 0, 0, 0};
    int k = 2;
    // Maximum consecutive ones equals k (since you can only flip 2 zeros).
    int expected = 2;
    BOOST_CHECK_EQUAL(solution.longestOnes(nums, k), expected);
}

BOOST_AUTO_TEST_CASE(test_k_zero)
{
    // Test when no flips are allowed (k = 0).
    std::vector<int> nums = {1, 0, 1, 1, 0, 1};
    int k = 0;
    // Without flips, the maximum consecutive ones is 2 (the subarray [1,1]).
    int expected = 2;
    BOOST_CHECK_EQUAL(solution.longestOnes(nums, k), expected);
}

BOOST_AUTO_TEST_CASE(test_alternating)
{
    // Test an alternating array.
    // For an array like: [1,0,1,0,1,0,1,0,1,0] and k = 3,
    // the best window after flipping three zeros can yield a subarray of 7 consecutive ones.
    std::vector<int> nums = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    int k = 3;
    int expected = 7;
    BOOST_CHECK_EQUAL(solution.longestOnes(nums, k), expected);
}
