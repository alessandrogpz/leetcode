#define BOOST_TEST_MODULE 1493.LongestSubarrayOf1sAfterDeletingOneElement
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution;

BOOST_AUTO_TEST_CASE(test_example_cases)
{
    // Example 1

    BOOST_CHECK_EQUAL(solution.longestSubarray(std::vector<int>{1, 1, 0, 1}), 3);

    // Example 2
    BOOST_CHECK_EQUAL(solution.longestSubarray(std::vector<int>{0, 1, 1, 1, 0, 1, 1, 0, 1}), 5);

    // Example 3
    BOOST_CHECK_EQUAL(solution.longestSubarray(std::vector<int>{1, 1, 1}), 2);
}

BOOST_AUTO_TEST_CASE(test_all_zeroes)
{
    // No 1's at all
    BOOST_CHECK_EQUAL(solution.longestSubarray(std::vector<int>{0, 0, 0}), 0);
}

BOOST_AUTO_TEST_CASE(test_single_element)
{
    // Single element 1
    BOOST_CHECK_EQUAL(solution.longestSubarray(std::vector<int>{1}), 0);
    // Explanation: Must delete the only element → longest subarray of 1's is empty → 0

    // Single element 0
    BOOST_CHECK_EQUAL(solution.longestSubarray(std::vector<int>{0}), 0);
    // Explanation: There's no 1 at all → result is 0
}

BOOST_AUTO_TEST_CASE(test_two_elements)
{
    // [1,0]
    BOOST_CHECK_EQUAL(solution.longestSubarray(std::vector<int>{1, 0}), 1);
    // After deleting 0, the subarray of 1's is [1] → length 1

    // [0,1]
    BOOST_CHECK_EQUAL(solution.longestSubarray(std::vector<int>{0, 1}), 1);
    // After deleting 0, the subarray of 1's is [1] → length 1

    // [1,1]
    BOOST_CHECK_EQUAL(solution.longestSubarray(std::vector<int>{1, 1}), 1);
    // After deleting one element, only one 1 remains
}

BOOST_AUTO_TEST_CASE(test_all_ones)
{
    // Already covered a small example [1,1,1], let's try a longer one
    // Deleting any one still leaves a subarray of length n-1
    BOOST_CHECK_EQUAL(solution.longestSubarray(std::vector<int>{1, 1, 1, 1, 1}), 4);
}

BOOST_AUTO_TEST_CASE(test_mixed_case_1)
{
    // Mixed case to test typical scenario
    // e.g. [0,1,0,1,1,1,0]
    // Potential subarrays of 1's are [1], [1,1,1]
    // If we delete a 0 between sequences of 1's, we might get a longer subarray
    // In this case, the longest after a good deletion is [1,1,1] or [1,1], depending on the position.
    // The longest we can get here is 3 by deleting one of the 0's that doesn't bridge anything useful
    // (If we delete the 0 at index 2, the array would be [0,1,1,1,1,0], the largest subarray of 1's is 4!)
    // Let's see:
    // Original:        0   1   0   1   1   1   0
    // Indices:         0   1   2   3   4   5   6
    // Delete index 2 → 0,1,1,1,1,0 => subarray [1,1,1,1] => length = 4
    BOOST_CHECK_EQUAL(solution.longestSubarray(std::vector<int>{0, 1, 0, 1, 1, 1, 0}), 4);
}

BOOST_AUTO_TEST_CASE(test_mixed_case_2)
{
    // More complex arrangement
    // [1,1,0,1,1,0,1,1,1,0,1]
    // There are multiple places where deleting a 0 can merge sequences of 1's.
    // We want to ensure the function handles these merges correctly.
    BOOST_CHECK_EQUAL(solution.longestSubarray(std::vector<int>{1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1}), 5);
    // For intance, deleting the 0 at index 2 merges the subarrays at index [0,1] and [3,4].
    // Or deleting at index 5 merges [3,4] and [6,7,8], and so on.
}