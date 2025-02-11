#define BOOST_TEST_MODULE 735.AsteroidCollision
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution;

BOOST_AUTO_TEST_CASE(test_example1)
{
    // Example 1:
    // Input: [5, 10, -5]
    // Expected Output: [5, 10]
    std::vector<int> asteroids = {5, 10, -5};
    std::vector<int> expected = {5, 10};
    auto result = solution.asteroidCollision(asteroids);
    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(test_example2)
{
    // Example 2:
    // Input: [8, -8]
    // Expected Output: [] (both asteroids explode)
    std::vector<int> asteroids = {8, -8};
    std::vector<int> expected = {};
    auto result = solution.asteroidCollision(asteroids);
    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(test_example3)
{
    // Example 3:
    // Input: [10, 2, -5]
    // Expected Output: [10]
    std::vector<int> asteroids = {10, 2, -5};
    std::vector<int> expected = {10};
    auto result = solution.asteroidCollision(asteroids);
    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(test_equal_explosion)
{
    // Test: Two asteroids of equal size and opposite direction
    // Input: [5, -5] => Both explode.
    std::vector<int> asteroids = {5, -5};
    std::vector<int> expected = {};
    auto result = solution.asteroidCollision(asteroids);
    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(test_chain_collision)
{
    // Test: Chain reaction collision
    // Input: [1, -1, -1, -1]
    // Process:
    //   1 collides with -1 (equal, both explode),
    //   then the remaining -1's are pushed (since negative asteroids don't collide among themselves).
    // Expected Output: [-1, -1]
    std::vector<int> asteroids = {1, -1, -1, -1};
    std::vector<int> expected = {-1, -1};
    auto result = solution.asteroidCollision(asteroids);
    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(test_no_collision)
{
    // Test: No collisions occur when asteroids move away from each other.
    // Input: [-2, -1, 1, 2]
    // Expected Output: [-2, -1, 1, 2]
    std::vector<int> asteroids = {-2, -1, 1, 2};
    std::vector<int> expected = {-2, -1, 1, 2};
    auto result = solution.asteroidCollision(asteroids);
    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(test_complex_collision)
{
    // Test: Multiple collisions in sequence.
    // Input: [10, 2, -5, -15]
    // Simulation:
    //   [10,2] then -5 collides: 2 explodes, then 10 remains (since 10 > 5),
    //   then -15 collides with 10: 10 explodes (since 15 > 10), leaving [-15].
    // Expected Output: [-15]
    std::vector<int> asteroids = {10, 2, -5, -15};
    std::vector<int> expected = {-15};
    auto result = solution.asteroidCollision(asteroids);
    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(test_another_collision)
{
    // Test: Collision with asteroids in different directions.
    // Input: [-10, 5, -5]
    // Simulation:
    //   -10 (left) remains, 5 (right) and -5 (left) collide: |5| == |5| so both explode.
    // Expected Output: [-10]
    std::vector<int> asteroids = {-10, 5, -5};
    std::vector<int> expected = {-10};
    auto result = solution.asteroidCollision(asteroids);
    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(test_mixed_collision)
{
    // Test: Mixed collisions with chain reactions.
    // Input: [5, 10, -5, -10]
    // Simulation:
    //   Process 5, then 10: stack becomes [5,10].
    //   Then -5 collides with 10 (10 > 5): -5 is destroyed.
    //   Then -10 collides with 10: equal sizes result in both exploding.
    //   Remaining asteroid is [5].
    // Expected Output: [5]
    std::vector<int> asteroids = {5, 10, -5, -10};
    std::vector<int> expected = {5};
    auto result = solution.asteroidCollision(asteroids);
    BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());
}
