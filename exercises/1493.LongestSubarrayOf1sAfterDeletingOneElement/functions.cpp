
#include "functions.h"

int Solution::longestSubarray(std::vector<int> &nums)
{
    int left = 0;
    int right = 0;
    int spareElement = 1;
    int maxCount = 0;

    for (right; right < nums.size(); right++)
    {
        if (nums[right] == 0)
        {
            spareElement--;
        }

        while (spareElement < 0)
        {
            if (nums[left] == 0)
            {
                spareElement++;
            }
            left++;
        }

        maxCount = std::max(maxCount, right - left + 1);
    }

    return maxCount - 1;
}