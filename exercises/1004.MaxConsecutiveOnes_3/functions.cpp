
#include "functions.h"

int Solution::longestOnes(std::vector<int> &nums, int k)
{
    int left = 0, zeros = 0, maxLength = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        // If current element is 0, increase the zero count

        // If we have more zeros than allowed, shrink the window from the left

        // Update the maximum window size
    }
    return maxLength;
}
