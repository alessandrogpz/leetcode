
#include "functions.h"
#include <algorithm>

int Solution::maxOperations(std::vector<int> &nums, int k)
{
    // First, sort the vector (you may implement your own sort if desired)
    std::sort(nums.begin(), nums.end());

    int count = 0;
    int left = 0;
    int right = nums.size() - 1;

    // Continue while there are at least two elements left.
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == k)
        {
            // When a pair is found
            right--;
            left++;
            count++;
        }
        else if (sum < k)
        {
            // Move left pointer rightward to try to increase the sum
            left++;
        }
        else
        {
            // Move right pointer leftward to try to decrease the sum.
            right--;
        }
    }

    return count;
}
