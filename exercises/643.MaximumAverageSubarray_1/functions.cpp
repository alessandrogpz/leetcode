
#include "functions.h"

double Solution::findMaxAverage(std::vector<int> &nums, int k)
{
    double curMaxAvg = 0;
    double maxAverage = 0;

    // initial sum
    for (int i = 0; i < k; ++i)
    {
        curMaxAvg += nums[i];
    }
    curMaxAvg = curMaxAvg / static_cast<double>(k);
    maxAverage = curMaxAvg;

    // slide k window
    for (int j = k; j < nums.size(); ++j)
    {
        // remove old, add new
        curMaxAvg += (nums[j] - nums[j - k]) / static_cast<double>(k);

        if (curMaxAvg > maxAverage)
            maxAverage = curMaxAvg;
    }

    return maxAverage;
}