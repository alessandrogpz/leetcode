#define BOOST_TEST_MODULE ContainerWithMostWater
#include <boost/test/included/unit_test.hpp>
#include <vector>
#include "functions.h" // Ensure this has the Solution class with maxArea method

Solution solution;

BOOST_AUTO_TEST_CASE(TestExample1)
{
    // From problem statement:
    // Input: [1,8,6,2,5,4,8,3,7]
    // Expected output: 49
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    BOOST_CHECK_EQUAL(solution.maxArea(height), 49);
}

BOOST_AUTO_TEST_CASE(TestExample2)
{
    // From problem statement:
    // Input: [1,1]
    // Expected output: 1
    std::vector<int> height = {1, 1};
    BOOST_CHECK_EQUAL(solution.maxArea(height), 1);
}

// Additional Tests

BOOST_AUTO_TEST_CASE(TestAllSame)
{
    // All lines have the same height
    // Example: [5,5,5,5]
    // The best container is between the first and last line
    std::vector<int> height = {5, 5, 5, 5};
    BOOST_CHECK_EQUAL(solution.maxArea(height), 15);
    // Explanation: distance between first and last indices = 3, height = 5 => area = 3*5 = 15
}

BOOST_AUTO_TEST_CASE(TestStrictlyIncreasing)
{
    // Heights are strictly ascending, e.g. [1,2,3,4,5]
    std::vector<int> height = {1, 2, 3, 4, 5};
    // Check correctness for that pattern
    BOOST_CHECK_EQUAL(solution.maxArea(height), 6);
    // Explanation: The best container is between the lines at indices 0 and 4 => distance=4, height=min(1,5)=1 => area=4*1=4
    // Another candidate is between 3 and 4 => distance=1, height=min(4,5)=4 => area=4
    // The largest is between indices 1 and 4 => distance=3, height=min(2,5)=2 => area=6 (this is bigger)
}

BOOST_AUTO_TEST_CASE(TestStrictlyDescending)
{
    // Heights are strictly descending, e.g. [9,7,6,4,1]
    std::vector<int> height = {9, 7, 6, 4, 1};
    BOOST_CHECK_EQUAL(solution.maxArea(height), 12);
    // Explanation:
    //   - Indices (0,4) => distance=4, height=min(9,1)=1 => area=4
    //   - Indices (0,3) => distance=3, height=min(9,4)=4 => area=12
    //   - Indices (0,2) => distance=2, height=min(9,6)=6 => area=12
    //   - Indices (1,4) => distance=3, height=min(7,1)=1 => area=3
    // Actually the best container is (0,2) or (0,3) with area=12 (Check carefully if you'd like)
    // So if your solution is correct, it should yield 12, not 9.
    // (Note: This case also tests that code is carefully handling all possibilities.)
}
