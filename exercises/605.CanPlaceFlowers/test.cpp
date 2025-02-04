
#define BOOST_TEST_MODULE 605.CanPlaceFlowers
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution;

BOOST_AUTO_TEST_CASE(TestCases)
{
    // Test Case 1
    std::vector<int> flowerbed1 = {1, 0, 0, 0, 1};
    int n1 = 1;
    BOOST_CHECK(solution.canPlaceFlowers(flowerbed1, n1) == true);

    // Test Case 2
    std::vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    int n2 = 2;
    BOOST_CHECK(solution.canPlaceFlowers(flowerbed2, n2) == false);

    // Test Case 3: No space available to plant
    std::vector<int> flowerbed3 = {1, 1, 1, 1, 1};
    int n3 = 1;
    BOOST_CHECK(solution.canPlaceFlowers(flowerbed3, n3) == false);

    // Test Case 4: All empty slots, enough space
    std::vector<int> flowerbed4 = {0, 0, 0, 0, 0};
    int n4 = 2;
    BOOST_CHECK(solution.canPlaceFlowers(flowerbed4, n4) == true);

    // Test Case 5: Edge case with only one slot
    std::vector<int> flowerbed5 = {0};
    int n5 = 1;
    BOOST_CHECK(solution.canPlaceFlowers(flowerbed5, n5) == true);

    // Test Case 6: Edge case with only one slot but already occupied
    std::vector<int> flowerbed6 = {1};
    int n6 = 1;
    BOOST_CHECK(solution.canPlaceFlowers(flowerbed6, n6) == false);

    // Test Case 7: Large input with alternating pattern
    std::vector<int> flowerbed7 = {0, 1, 0, 1, 0, 1, 0, 1, 0};
    int n7 = 1;
    BOOST_CHECK(solution.canPlaceFlowers(flowerbed7, n7) == false);

    // Test Case 8: Large input, all empty
    std::vector<int> flowerbed8(100, 0); // 100 empty slots
    int n8 = 50;                         // We can plant 50 flowers
    BOOST_CHECK(solution.canPlaceFlowers(flowerbed8, n8) == true);
}