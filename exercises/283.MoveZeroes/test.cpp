#define BOOST_TEST_MODULE 283_MoveZeroes
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution; // Global instance of the Solution class

BOOST_AUTO_TEST_CASE(test_basic_cases)
{
    std::vector<int> nums1 = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums1);
    std::vector<int> expected1 = {1, 3, 12, 0, 0};
    BOOST_CHECK_EQUAL_COLLECTIONS(nums1.begin(), nums1.end(), expected1.begin(), expected1.end());

    std::vector<int> nums2 = {0, 0, 1};
    solution.moveZeroes(nums2);
    std::vector<int> expected2 = {1, 0, 0};
    BOOST_CHECK_EQUAL_COLLECTIONS(nums2.begin(), nums2.end(), expected2.begin(), expected2.end());

    std::vector<int> nums3 = {1, 0, 2, 0, 3};
    solution.moveZeroes(nums3);
    std::vector<int> expected3 = {1, 2, 3, 0, 0};
    BOOST_CHECK_EQUAL_COLLECTIONS(nums3.begin(), nums3.end(), expected3.begin(), expected3.end());
}

BOOST_AUTO_TEST_CASE(test_edge_cases)
{
    std::vector<int> nums4 = {0, 0, 0, 0};
    solution.moveZeroes(nums4);
    std::vector<int> expected4 = {0, 0, 0, 0};
    BOOST_CHECK_EQUAL_COLLECTIONS(nums4.begin(), nums4.end(), expected4.begin(), expected4.end());

    std::vector<int> nums5 = {1, 2, 3, 4, 5};
    solution.moveZeroes(nums5);
    std::vector<int> expected5 = {1, 2, 3, 4, 5}; // Already ordered, should remain unchanged
    BOOST_CHECK_EQUAL_COLLECTIONS(nums5.begin(), nums5.end(), expected5.begin(), expected5.end());

    std::vector<int> nums6 = {0};
    solution.moveZeroes(nums6);
    std::vector<int> expected6 = {0}; // Single zero remains the same
    BOOST_CHECK_EQUAL_COLLECTIONS(nums6.begin(), nums6.end(), expected6.begin(), expected6.end());
}

BOOST_AUTO_TEST_CASE(test_large_case)
{
    std::vector<int> nums7(1000, 0); // Large input of all zeros
    solution.moveZeroes(nums7);
    std::vector<int> expected7(1000, 0); // Should remain the same
    BOOST_CHECK_EQUAL_COLLECTIONS(nums7.begin(), nums7.end(), expected7.begin(), expected7.end());

    std::vector<int> nums8 = {1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 7, 8};
    solution.moveZeroes(nums8);
    std::vector<int> expected8 = {1, 2, 3, 4, 5, 6, 7, 8, 0, 0, 0, 0};
    BOOST_CHECK_EQUAL_COLLECTIONS(nums8.begin(), nums8.end(), expected8.begin(), expected8.end());
}
