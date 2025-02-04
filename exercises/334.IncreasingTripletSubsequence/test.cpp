#define BOOST_TEST_MODULE IncreasingTripletSubsequence
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

BOOST_AUTO_TEST_CASE(TestExample1)
{
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 5};
    BOOST_CHECK(solution.increasingTriplet(nums) == true);
}

BOOST_AUTO_TEST_CASE(TestExample2)
{
    Solution solution;
    std::vector<int> nums = {5, 4, 3, 2, 1};
    BOOST_CHECK(solution.increasingTriplet(nums) == false);
}

BOOST_AUTO_TEST_CASE(TestExample3)
{
    Solution solution;
    std::vector<int> nums = {2, 1, 5, 0, 4, 6};
    BOOST_CHECK(solution.increasingTriplet(nums) == true);
}

// Edge Case: Smallest possible array (size 1)
BOOST_AUTO_TEST_CASE(TestSingleElement)
{
    Solution solution;
    std::vector<int> nums = {1};
    BOOST_CHECK(solution.increasingTriplet(nums) == false);
}

// Edge Case: Only two elements (should return false)
BOOST_AUTO_TEST_CASE(TestTwoElements)
{
    Solution solution;
    std::vector<int> nums = {1, 2};
    BOOST_CHECK(solution.increasingTriplet(nums) == false);
}

// Edge Case: Triplet at the start
BOOST_AUTO_TEST_CASE(TestTripletAtStart)
{
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 10, 9, 8};
    BOOST_CHECK(solution.increasingTriplet(nums) == true);
}

// Edge Case: Triplet in the middle
BOOST_AUTO_TEST_CASE(TestTripletInMiddle)
{
    Solution solution;
    std::vector<int> nums = {10, 1, 2, 3, 9, 8};
    BOOST_CHECK(solution.increasingTriplet(nums) == true);
}

// Edge Case: Large Input (Boundary Test)
BOOST_AUTO_TEST_CASE(TestLargeInput)
{
    Solution solution;
    std::vector<int> nums(500000, 1); // All elements are the same, so no triplet
    BOOST_CHECK(solution.increasingTriplet(nums) == false);
}

// Edge Case: Decreasing with a peak (should return true)
BOOST_AUTO_TEST_CASE(TestDecreasingWithPeak)
{
    Solution solution;
    std::vector<int> nums = {5, 1, 2, 6, 0, -1};
    BOOST_CHECK(solution.increasingTriplet(nums) == true);
}

// Edge Case: Multiple increasing sequences but no valid triplet
BOOST_AUTO_TEST_CASE(TestMultipleIncreasingSequences)
{
    Solution solution;
    std::vector<int> nums = {1, 2, 1, 2, 1, 2}; // No continuous increasing triplet
    BOOST_CHECK(solution.increasingTriplet(nums) == false);
}

// Edge Case: Skiping indexes
BOOST_AUTO_TEST_CASE(TestSkipingIndexes)
{
    Solution solution;
    std::vector<int> nums = {20, 100, 10, 12, 5, 13};
    BOOST_CHECK(solution.increasingTriplet(nums) == true);
}
