#define BOOST_TEST_MODULE 1207.UniqueNumberOfOccurrences
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution;

BOOST_AUTO_TEST_CASE(test_example1)
{
    // Example 1: [1,2,2,1,1,3] => true
    // Explanation: 1 occurs 3 times, 2 occurs 2 times, 3 occurs 1 time. All distinct counts.
    std::vector<int> arr = {1, 2, 2, 1, 1, 3};
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_1(arr), true);
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_2(arr), true);
}

BOOST_AUTO_TEST_CASE(test_example2)
{
    // Example 2: [1,2] => false
    // Explanation: 1 occurs once, 2 occurs once => the counts are not unique
    std::vector<int> arr = {1, 2};
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_1(arr), false);
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_2(arr), false);
}

BOOST_AUTO_TEST_CASE(test_example3)
{
    // Example 3: [-3,0,1,-3,1,1,1,-3,10,0] => true
    // Explanation:
    //   -3 => 3 times
    //    0 => 2 times
    //    1 => 4 times
    //   10 => 1 time
    // All distinct counts (3, 2, 4, 1).
    std::vector<int> arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_1(arr), true);
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_2(arr), true);
}

BOOST_AUTO_TEST_CASE(test_single_element)
{
    // Single element => trivially true, as there's only one count
    std::vector<int> arr = {42};
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_1(arr), true);
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_2(arr), true);
}

BOOST_AUTO_TEST_CASE(test_repeated_identical)
{
    // All elements are the same => there's only one distinct number
    // which means there's only one unique count
    // => should be true
    std::vector<int> arr = {7, 7, 7, 7};
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_1(arr), true);
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_2(arr), true);
}

BOOST_AUTO_TEST_CASE(test_two_numbers_same_count)
{
    // [1,1,2,2,3] => occurs?
    //   1 => 2 times
    //   2 => 2 times
    //   3 => 1 time
    // 1 and 2 have the same occurrence count => false
    std::vector<int> arr = {1, 1, 2, 2, 3};
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_1(arr), false);
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_2(arr), false);
}

BOOST_AUTO_TEST_CASE(test_zero_and_negative)
{
    // Mix of negative, zero, positives
    // [0,0,0, -1,-1, 1, 2] =>
    //   0 => 3 times
    //  -1 => 2 times
    //   1 => 1 time
    //   2 => 1 time
    // 1 and 2 each occur once => same count => false
    std::vector<int> arr = {0, 0, 0, -1, -1, 1, 2};
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_1(arr), false);
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_2(arr), false);
}

BOOST_AUTO_TEST_CASE(test_large_variety)
{
    // Testing a scenario with multiple distinct values,
    // each must have a unique count
    // e.g. [1,1,2,3,3,4,4,4,5,5,5,5]
    //   1 => 2 times
    //   2 => 1 time
    //   3 => 2 times (same as 1 => conflict => false)
    //   4 => 3 times
    //   5 => 4 times
    // Actually, 1 and 3 both appear 2 times => false
    std::vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5};
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_1(arr), false);
    BOOST_CHECK_EQUAL(solution.uniqueOccurrences_2(arr), false);
}
