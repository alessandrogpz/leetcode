
#include "functions.h"

int Solution::equalPairs(std::vector<std::vector<int>> &grid)
{
    int gridSize = grid.size();
    std::vector<int> tempVec = {};
    int totalPairs = 0;

    //---- hash function (lambda) -----
    // Define an inline lambda hash function for std::vector<int>
    auto vectorHash = [](const std::vector<int> &v) -> std::size_t
    {
        std::size_t seed = v.size();
        for (int num : v)
        {
            // Combine the hash of each element into 'seed'
            seed ^= std::hash<int>()(num) + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
        }
        return seed;
    };

    // Create an unordered_map that uses our inline lambda as the hash function.
    // The second argument in the constructor is our lambda.
    std::unordered_map<std::vector<int>, int, decltype(vectorHash)> rowFreq(10, vectorHash);
    std::unordered_map<std::vector<int>, int, decltype(vectorHash)> colFreq(10, vectorHash);
    // --------------------------------

    // Process rows in rowFreq
    for (const auto &row : grid)
    {
        rowFreq[row]++; // Increments the count for this row vector, initializes if not present
    }

    // Process Columns in colFreq
    for (int i = 0; i < gridSize; ++i)
    {
        tempVec.clear();
        for (int j = 0; j < gridSize; ++j)
        {
            tempVec.push_back(grid[j][i]);
        }
        colFreq[tempVec]++; // Increments the count  for this column vector, initializes if not present
    }

    // Count matching pairs: for each row vector that appears in columns,
    // add the product of their frequencies to the total count.
    for (const auto &rowPair : rowFreq)
    {
        for (const auto &colPair : colFreq)
        {
            if (rowPair.first == colPair.first)
            {
                totalPairs += rowPair.second * colPair.second;
            }
        }
    }

    return totalPairs;
}
