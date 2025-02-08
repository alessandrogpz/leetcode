#include "functions.h"

std::vector<std::vector<int>> Solution::findDifference(std::vector<int> &nums1, std::vector<int> &nums2)
{
    // 1. Insert all elements from nums1 and nums2 into two sets
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());

    // 2. Compute elements in set1 but not in set2
    std::vector<int> distinct1;
    for (int val : set1)
    {
        if (set2.find(val) == set2.end())
        {
            distinct1.push_back(val);
        }
    }

    // 3. Compute elements in set2 but not in set1
    std::vector<int> distinct2;
    for (int val : set2)
    {
        if (set1.find(val) == set1.end())
        {
            distinct2.push_back(val);
        }
    }

    return {distinct1, distinct2};
}
