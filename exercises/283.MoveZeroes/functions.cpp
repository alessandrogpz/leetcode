
#include "functions.h"

void Solution::moveZeroes(std::vector<int> &nums)
{
    int nonZeroIndex = 0; // Pointer for placing non-zero elements

    // Move all non-zero elements to the front
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            std::swap(nums[nonZeroIndex], nums[i]);
            ++nonZeroIndex;
        }
    }
};
