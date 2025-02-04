#define BOOST_TEST_MODULE MaximumAverageSubarrayTests
#include <boost/test/included/unit_test.hpp>
#include <vector>
#include "functions.h" // Ensure this contains the declaration of `Solution` and `findMaxAverage`

Solution solution;

BOOST_AUTO_TEST_CASE(TestExample1)
{
    std::vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double expected = 12.75;
    double actual = solution.findMaxAverage(nums, k);

    // Allowing a small floating-point error margin of 1e-5
    BOOST_CHECK_CLOSE_FRACTION(actual, expected, 1e-5);
}

BOOST_AUTO_TEST_CASE(TestExample2)
{
    std::vector<int> nums = {5};
    int k = 1;
    double expected = 5.0;
    double actual = solution.findMaxAverage(nums, k);

    BOOST_CHECK_CLOSE_FRACTION(actual, expected, 1e-5);
}

// Additional Test Cases

// Test 3: A small array with repeated values
BOOST_AUTO_TEST_CASE(TestAllPositive)
{
    std::vector<int> nums = {0, 1, 1, 3, 3};
    int k = 2;
    // Possible sums of size 2: [0+1, 1+1, 1+3, 3+3] = [1, 2, 4, 6].
    // Max sum is 6, average 6/2 = 3.0.
    double expected = 3.0;
    double actual = solution.findMaxAverage(nums, k);

    BOOST_CHECK_CLOSE_FRACTION(actual, expected, 1e-5);
}

// Test 4: All negative values
BOOST_AUTO_TEST_CASE(TestAllNegative)
{
    std::vector<int> nums = {-1, -12, -5, -6, -50, -3};
    int k = 3;
    // Subarrays of size 3:
    //   [-1, -12, -5] sum = -18, average = -6
    //   [-12, -5, -6] sum = -23, avg = -7.666...
    //   [-5, -6, -50] sum = -61, avg = -20.333...
    //   [-6, -50, -3] sum = -59, avg = -19.666...
    // Max average is -6.0
    double expected = -6.0;
    double actual = solution.findMaxAverage(nums, k);

    BOOST_CHECK_CLOSE_FRACTION(actual, expected, 1e-5);
}

// Test 5: Mixed positive/negative, larger subarray length
BOOST_AUTO_TEST_CASE(TestMixedValues)
{
    std::vector<int> nums = {-1, 2, 3, -2, 5, -1, 4, 2, -3};
    int k = 4;
    // Let's just trust our function or manually verify if needed.
    // A quick check for subarray of size 4 with the best average:
    // Potentially subarray [3, -2, 5, -1] = sum = 5 -> avg = 1.25
    // Another candidate: [2, 3, -2, 5] = 8 -> avg = 2.0
    // Let's see if there's a better one around the middle: [3, -2, 5, -1] = 5
    // [5, -1, 4, 2] = 10 -> average = 2.5 (this is likely the max)
    // So expected = 2.5
    double expected = 2.5;
    double actual = solution.findMaxAverage(nums, k);

    BOOST_CHECK_CLOSE_FRACTION(actual, expected, 1e-5);
}
