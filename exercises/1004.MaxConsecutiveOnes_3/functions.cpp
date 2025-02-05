
#include "functions.h"

int Solution::longestOnes(std::vector<int> &nums, int k)
{
    int left = 0, zeros = 0, maxLength = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        // If current element is 0, increase the zero count
        if (nums[right] == 0)
        {
            zeros++;
        }

        // If we have more zeros than allowed, shrink the window from the left
        while (zeros > k)
        {
            if (nums[left] == 0)
            {
                zeros--;
            }
            left++;
        }

        // Update the maximum window size
        maxLength = std::max(maxLength, right - left + 1);
    }
    return maxLength;
}
