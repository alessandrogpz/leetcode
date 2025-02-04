#define BOOST_TEST_MODULE 1679.MaxNumberOfK - SumPairs
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution;

BOOST_AUTO_TEST_CASE(Example1)
{
    std::vector<int> nums = {1, 2, 3, 4};
    int k = 5;
    int result = solution.maxOperations(nums, k);
    BOOST_CHECK_EQUAL(result, 2);
}

BOOST_AUTO_TEST_CASE(Example2)
{
    std::vector<int> nums = {3, 1, 3, 4, 3};
    int k = 6;
    int result = solution.maxOperations(nums, k);
    BOOST_CHECK_EQUAL(result, 1);
}

BOOST_AUTO_TEST_CASE(NoPairsPossible)
{
    std::vector<int> nums = {1, 2, 3};
    int k = 7;
    int result = solution.maxOperations(nums, k);
    BOOST_CHECK_EQUAL(result, 0);
}

BOOST_AUTO_TEST_CASE(AllPairsPossible)
{
    std::vector<int> nums = {2, 2, 2, 2, 2, 2};
    int k = 4;
    // With 6 occurrences of 2 and k=4, we can form 3 pairs.
    int result = solution.maxOperations(nums, k);
    BOOST_CHECK_EQUAL(result, 3);
}

BOOST_AUTO_TEST_CASE(MixedNumbers)
{
    std::vector<int> nums = {1, 3, 2, 2, 3, 4, 1};
    int k = 4;
    // Valid pairs that sum to 4 can be:
    // (1, 3) -> two pairs and (2, 2) -> one pair, totaling 3 operations.
    int result = solution.maxOperations(nums, k);
    BOOST_CHECK_EQUAL(result, 3);
}

BOOST_AUTO_TEST_CASE(LotsOFNumbers_1)
{
    std::vector<int> nums = {67, 44, 76, 8, 63, 78, 65, 47, 7, 20, 61, 55, 11, 89, 38, 1, 62, 25, 52, 79, 46, 18, 60, 67, 5, 40, 20, 4, 8, 40, 26, 13, 21, 21, 32, 17, 7, 27, 9, 45, 87, 14, 5, 73, 66, 75, 34, 48, 50, 72, 72, 81, 25, 71, 58, 84, 25, 84, 81, 48, 65, 42, 28, 50, 80, 50, 15, 79, 60, 40, 64, 57, 13, 31, 31, 18, 16, 43, 18, 41, 88, 28, 30, 61, 73, 37, 85, 88, 33, 55, 52, 55, 30, 45, 63, 38, 53, 4, 81, 80, 14, 53, 31, 21, 67, 27, 90, 47, 85, 28, 12, 87, 57, 65, 86, 82, 16, 61, 60, 70, 38, 36, 10, 61, 10, 42, 2, 20, 11, 48, 32, 57, 67, 27, 81, 44, 86, 14, 80, 8, 26, 71, 72, 48, 75, 53, 18, 83, 48, 41, 10, 65, 37, 9, 68, 44, 5, 14, 77, 5, 61, 67, 58, 57, 47, 75, 31, 40, 60, 71, 50, 4, 35, 88, 40, 49, 41, 73, 16, 68, 71, 81, 43, 76, 86, 44, 77, 37, 8, 17, 76, 31, 49, 58, 57, 35, 51, 77, 53, 41, 57, 36, 18, 83, 51, 27, 42, 23, 90, 20, 21, 82, 69, 63, 29, 8, 90, 69, 1, 59, 70, 4, 36, 35, 49, 24, 29, 25, 19, 22, 17, 18, 56, 49, 87, 54, 90, 25, 30, 22, 20, 52, 16, 34, 29, 83, 49, 58, 69, 8, 55, 56, 60, 69, 31, 52, 14, 67, 54, 50, 31, 32, 37, 62, 3, 70, 12, 35, 4, 44, 88, 44, 5, 45, 79, 46, 49, 51, 76, 23, 73, 75, 17, 76, 58, 27, 9, 2, 27, 52, 8, 31, 57, 75, 16, 82, 50, 90, 34, 5, 16, 76, 6, 61, 51, 11, 26, 8, 80, 73, 86, 83, 86, 28, 60, 23, 35, 24, 6, 69, 24, 19, 43, 62, 59, 66, 13, 80, 38, 18, 69, 55, 22, 14, 33, 47, 89, 79, 26, 31, 90, 83, 64, 89, 52, 20, 71, 19, 53, 46, 30, 43, 22, 28, 72, 27, 9, 30, 68, 47, 73, 20, 5, 51, 84, 87, 31, 71, 51, 38, 28, 16, 87, 55, 30, 11, 85, 22, 60, 1, 69, 72, 87, 35, 23, 69, 11, 8, 1, 54, 34, 61, 40, 51, 57, 65, 86, 49, 77, 8, 72, 15, 46, 68, 61, 68, 14, 3, 32, 53, 28, 4, 31, 80, 78, 83, 52, 8, 40, 88, 58, 73, 29, 24, 2, 11, 71, 87, 82, 81, 2, 88, 54, 85, 25, 61, 83, 6, 72};
    int k = 62;
    int result = solution.maxOperations(nums, k);
    BOOST_CHECK_EQUAL(result, 116);
}
