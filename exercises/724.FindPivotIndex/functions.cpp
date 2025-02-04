
#include "functions.h"

int Solution::pivotIndex(std::vector<int> &nums)
{
    int totalSum = 0;
    for (int num : nums)
    {
        totalSum += num;
    }

    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // rightSum is the total sum minus left sum minus current element
        int rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum)
        {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}