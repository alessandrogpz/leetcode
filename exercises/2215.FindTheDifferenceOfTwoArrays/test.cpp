#define BOOST_TEST_MODULE 2215.FindTheDifferenceOfTwoArrays
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution;

/**
 * Helper function to verify that a given subVector (result of findDifference)
 * contains exactly the elements in expectedElements, no more, no less.
 * Order is ignored.
 */
static void checkVectorContents(
    const std::vector<int> &subVector,
    const std::vector<int> &expectedElements)
{
    // 1) Check same size
    BOOST_CHECK_EQUAL(subVector.size(), expectedElements.size());

    // 2) For each expected element, verify it's present in subVector
    for (int val : expectedElements)
    {
        auto it = std::find(subVector.begin(), subVector.end(), val);
        BOOST_CHECK_MESSAGE(
            it != subVector.end(),
            "Element " << val << " was expected but not found in subVector.");
    }

    // 3) Ensure no extra unexpected elements are present
    // We'll count matches. The total must match subVector.size()
    std::size_t matchCount = 0;
    for (int val : subVector)
    {
        if (std::find(expectedElements.begin(), expectedElements.end(), val) != expectedElements.end())
        {
            matchCount++;
        }
    }
    BOOST_CHECK_EQUAL(matchCount, subVector.size());
}

// --------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(test_example1)
{
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 4, 6};

    auto result = solution.findDifference(nums1, nums2);

    // Expected:
    // result[0] -> distinct in nums1 (not in nums2) => {1, 3}
    // result[1] -> distinct in nums2 (not in nums1) => {4, 6}

    // Sanity-check that we have exactly 2 sub-vectors
    BOOST_REQUIRE_EQUAL(result.size(), 2);

    // Check sub-vector #0
    checkVectorContents(result[0], {1, 3});

    // Check sub-vector #1
    checkVectorContents(result[1], {4, 6});
}

// --------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(test_example2)
{
    std::vector<int> nums1 = {1, 2, 3, 3};
    std::vector<int> nums2 = {1, 1, 2, 2};

    auto result = solution.findDifference(nums1, nums2);

    // Expected:
    // result[0] = [3]
    // result[1] = []

    BOOST_REQUIRE_EQUAL(result.size(), 2);

    checkVectorContents(result[0], {3});
    checkVectorContents(result[1], {});
}

// --------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(test_all_common)
{
    // All elements are the same across both arrays
    std::vector<int> nums1 = {2, 2, 2};
    std::vector<int> nums2 = {2, 2};

    auto result = solution.findDifference(nums1, nums2);

    // Since both contain only '2', there's no distinct element
    // => result[0] = {}, result[1] = {}
    BOOST_REQUIRE_EQUAL(result.size(), 2);

    checkVectorContents(result[0], {});
    checkVectorContents(result[1], {});
}

// --------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(test_all_distinct)
{
    // No elements overlap
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};

    auto result = solution.findDifference(nums1, nums2);

    // All nums1 elements are distinct => result[0] = {1, 2}
    // All nums2 elements are distinct => result[1] = {3, 4}
    BOOST_REQUIRE_EQUAL(result.size(), 2);

    checkVectorContents(result[0], {1, 2});
    checkVectorContents(result[1], {3, 4});
}

// --------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(test_negative_and_duplicates)
{
    std::vector<int> nums1 = {-1, -2, -2, 0};
    std::vector<int> nums2 = {-1, 1, 2};

    auto result = solution.findDifference(nums1, nums2);

    // Distinct in nums1 -> [-2, 0]
    // Distinct in nums2 -> [1, 2]
    BOOST_REQUIRE_EQUAL(result.size(), 2);

    checkVectorContents(result[0], {-2, 0});
    checkVectorContents(result[1], {1, 2});
}
