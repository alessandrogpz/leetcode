// 2352. Equal Row and Column Pairs

// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.
// A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

// Example 1:
// Input: grid = {{3,2,1},{1,7,6},{2,7,7}}
// Output: 1
// Explanation: There is 1 equal row and column pair:
// - (Row 2, Column 1): {2,7,7}

// Example 2:
// Input: grid = {{3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
// Output: 3
// Explanation: There are 3 equal row and column pairs:
// - (Row 0, Column 0): [3,1,2,2]
// - (Row 2, Column 2): [2,4,2,2]
// - (Row 3, Column 2): [2,4,2,2]

// Constraints:
// n == grid.length == grid[i].length
// 1 <= n <= 200
// 1 <= grid[i][j] <= 105

#include "functions.h"

int main(int argc, char *argv[])
{
    std::vector<std::vector<int>> test1 = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    std::vector<std::vector<int>> test2 = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    std::vector<std::vector<int>> test3 = {{1, 1}, {1, 1}};
    std::vector<std::vector<int>> test4 = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    Solution solution;

    std::cout << "Out: " << "\n"
              << solution.equalPairs(test1) << "\n";
    std::cout << "Out: " << "\n"
              << solution.equalPairs(test2) << "\n";
    std::cout << "Out: " << "\n"
              << solution.equalPairs(test3) << "\n";
    std::cout << "Out: " << "\n"
              << solution.equalPairs(test4) << "\n";

    return 0;
}
