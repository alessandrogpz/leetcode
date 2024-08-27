// Given a sorted array of distinct integers and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4

// Constraints:
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

#include <iostream>
#include <vector>

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int lowIndex = 0;
        int highIndex = nums.size() - 1;

        while (lowIndex <= highIndex)
        {
            int searchIndex = lowIndex + (highIndex - lowIndex) / 2;

            if (nums[searchIndex] == target)
            {
                return searchIndex;
            }
            else if (nums[searchIndex] > target)
            {
                highIndex = searchIndex - 1;
            }
            else
            {
                lowIndex = searchIndex + 1;
            }
        }

        return lowIndex;
    }
};

int main()
{
    std::vector<int> one = {1, 3, 5, 6};

    Solution solution;

    std::cout << solution.searchInsert(one, 1) << std::endl;
    std::cout << solution.searchInsert(one, 2) << std::endl;
    std::cout << solution.searchInsert(one, 3) << std::endl;
    std::cout << solution.searchInsert(one, 4) << std::endl;
    std::cout << solution.searchInsert(one, 5) << std::endl;
    std::cout << solution.searchInsert(one, 6) << std::endl;
    std::cout << solution.searchInsert(one, 7) << std::endl;

    return 0;
}