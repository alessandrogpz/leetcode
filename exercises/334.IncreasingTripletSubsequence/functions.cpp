
#include "functions.h"

// O^3 solution
bool Solution::increasingTripletO3(std::vector<int> &nums)
{
    int low;
    int mid;

    if (nums.size() <= 2)
        return false;

    for (int i = 0; i < nums.size() - 2; i++)
    {
        low = nums[i];

        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] > low)
            {
                mid = nums[j];
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[k] > mid)
                        return true;
                }
            }
        }
    }
    return false;
}

// On solution
bool Solution::increasingTriplet(std::vector<int> &nums)
{
    if (nums.size() < 3)
        return false;

    int first = INT_MAX, second = INT_MAX;

    for (int num : nums)
    {
        if (num <= first)
        {
            first = num; // Smallest so far
        }
        else if (num <= second)
        {
            second = num; // Second smallest so far
        }
        else
        {
            return true; // Found third element forming a triplet
        }
    }

    return false;
}
