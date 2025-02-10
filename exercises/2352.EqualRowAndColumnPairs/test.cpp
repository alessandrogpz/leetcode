#define BOOST_TEST_MODULE 2352.EqualRowAndColumnPairs
#include <boost/test/included/unit_test.hpp>
#include "functions.h" // Contains the declaration of Solution::equalPairs

Solution solution;

BOOST_AUTO_TEST_CASE(test_example1)
{
    // Example 1:
    // Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
    // Expected output: 1 (only row2 equals col1: [2,7,7])
    std::vector<std::vector<int>> grid = {
        {3, 2, 1},
        {1, 7, 6},
        {2, 7, 7}};
    BOOST_CHECK_EQUAL(solution.equalPairs(grid), 1);
}

BOOST_AUTO_TEST_CASE(test_example2)
{
    // Example 2:
    // Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
    // Expected output: 3
    std::vector<std::vector<int>> grid = {
        {3, 1, 2, 2},
        {1, 4, 4, 5},
        {2, 4, 2, 2},
        {2, 4, 2, 2}};
    BOOST_CHECK_EQUAL(solution.equalPairs(grid), 3);
}

BOOST_AUTO_TEST_CASE(test_single_element)
{
    // 1x1 grid test
    // Input: grid = [[42]]
    // Expected output: 1 (only one row and one column, which trivially match)
    std::vector<std::vector<int>> grid = {
        {42}};
    BOOST_CHECK_EQUAL(solution.equalPairs(grid), 1);
}

BOOST_AUTO_TEST_CASE(test_all_identical)
{
    // Grid with all identical elements
    // Input: grid = [[1,1],[1,1]]
    // Each row is [1,1] and each column is [1,1].
    // There are 2 rows and 2 columns, so total matching pairs = 2 * 2 = 4.
    std::vector<std::vector<int>> grid = {
        {1, 1},
        {1, 1}};
    BOOST_CHECK_EQUAL(solution.equalPairs(grid), 4);
}

BOOST_AUTO_TEST_CASE(test_no_matches)
{
    // Grid where no row equals any column
    // Input: grid = [[1,2],[3,4]]
    // Rows: [1,2] and [3,4]
    // Columns: [1,3] and [2,4]
    // No row matches any column → expected output: 0.
    std::vector<std::vector<int>> grid = {
        {1, 2},
        {3, 4}};
    BOOST_CHECK_EQUAL(solution.equalPairs(grid), 0);
}

BOOST_AUTO_TEST_CASE(test_mixed)
{
    // A grid with two rows and two columns where both pairs match:
    // Input: grid = [[1,2],[2,1]]
    // Rows: row0 = [1,2], row1 = [2,1]
    // Columns: col0 = [1,2], col1 = [2,1]
    // row0 equals col0, row1 equals col1 → expected output: 2.
    std::vector<std::vector<int>> grid = {
        {1, 2},
        {2, 1}};
    BOOST_CHECK_EQUAL(solution.equalPairs(grid), 2);
}
