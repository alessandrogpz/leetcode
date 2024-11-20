#define BOOST_TEST_MODULE LongestConsecutiveSequenceTest
#include <boost/test/included/unit_test.hpp>
#include <vector>
#include "functions.h"

// Assuming the function is defined in the same file for simplicity
// int longestConsecutive(std::vector<int> &nums);

BOOST_AUTO_TEST_CASE(test_example_cases)
{
    std::vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    BOOST_CHECK_EQUAL(longestConsecutive(nums1), 4);

    std::vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    BOOST_CHECK_EQUAL(longestConsecutive(nums2), 9);
}

BOOST_AUTO_TEST_CASE(test_empty_array)
{
    std::vector<int> nums = {};
    BOOST_CHECK_EQUAL(longestConsecutive(nums), 0);
}

BOOST_AUTO_TEST_CASE(test_single_element)
{
    std::vector<int> nums = {10};
    BOOST_CHECK_EQUAL(longestConsecutive(nums), 1);
}

BOOST_AUTO_TEST_CASE(test_no_consecutive_sequence)
{
    std::vector<int> nums = {10, 30, 50};
    BOOST_CHECK_EQUAL(longestConsecutive(nums), 1);
}

BOOST_AUTO_TEST_CASE(test_large_consecutive_sequence)
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BOOST_CHECK_EQUAL(longestConsecutive(nums), 10);
}

BOOST_AUTO_TEST_CASE(test_with_negative_numbers)
{
    std::vector<int> nums = {-1, -2, -3, 2, 3, 1, 0};
    BOOST_CHECK_EQUAL(longestConsecutive(nums), 7); // Sequence is [-3, -2, -1, 0, 1, 2, 3]
}

BOOST_AUTO_TEST_CASE(test_duplicate_elements)
{
    std::vector<int> nums = {1, 2, 2, 3, 4};
    BOOST_CHECK_EQUAL(longestConsecutive(nums), 4); // Sequence is [1, 2, 3, 4]
}
