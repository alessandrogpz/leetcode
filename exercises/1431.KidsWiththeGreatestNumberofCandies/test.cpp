
#define BOOST_TEST_MODULE 1431.KidsWiththeGreatestNumberofCandies
#include <boost/test/included/unit_test.hpp>
#include "functions.h"
#include <vector>
#include <algorithm>

Solution solution; // Instantiate the Solution class

// Test Suite
BOOST_AUTO_TEST_CASE(TestCases)
{
    // Test Case 1
    std::vector<int> candies1 = {2, 3, 5, 1, 3};
    int extraCandies1 = 3;
    std::vector<bool> expected1 = {true, true, true, false, true};
    BOOST_CHECK(solution.kidsWithCandies(candies1, extraCandies1) == expected1);

    // Test Case 2
    std::vector<int> candies2 = {4, 2, 1, 1, 2};
    int extraCandies2 = 1;
    std::vector<bool> expected2 = {true, false, false, false, false};
    BOOST_CHECK(solution.kidsWithCandies(candies2, extraCandies2) == expected2);

    // Test Case 3
    std::vector<int> candies3 = {12, 1, 12};
    int extraCandies3 = 10;
    std::vector<bool> expected3 = {true, false, true};
    BOOST_CHECK(solution.kidsWithCandies(candies3, extraCandies3) == expected3);

    // Edge Case 1: Minimum number of kids
    std::vector<int> candies4 = {1, 2};
    int extraCandies4 = 1;
    std::vector<bool> expected4 = {true, true};
    BOOST_CHECK(solution.kidsWithCandies(candies4, extraCandies4) == expected4);

    // Edge Case 2: All kids have same candies
    std::vector<int> candies5 = {5, 5, 5, 5};
    int extraCandies5 = 2;
    std::vector<bool> expected5 = {true, true, true, true};
    BOOST_CHECK(solution.kidsWithCandies(candies5, extraCandies5) == expected5);

    // Edge Case 3: Large values
    std::vector<int> candies6 = {100, 90, 80, 70};
    int extraCandies6 = 10;
    std::vector<bool> expected6 = {true, true, false, false};
    BOOST_CHECK(solution.kidsWithCandies(candies6, extraCandies6) == expected6);
}
