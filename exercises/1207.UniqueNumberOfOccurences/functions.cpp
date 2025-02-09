
#include "functions.h"

bool Solution::uniqueOccurrences_1(std::vector<int> &arr)
{
    std::unordered_set<int> uniqueNum = {arr.begin(), arr.end()};
    std::unordered_set<int> freqNum = {};

    for (int i = 0; i < uniqueNum.size(); ++i)
    {
        auto it = uniqueNum.begin();
        std::advance(it, i);
        int curNum = *it;
        int countNum = 0;

        for (int j = 0; j < arr.size(); ++j)
        {
            if (arr[j] == curNum)
            {
                countNum++;
            }
        }

        if (freqNum.find(countNum) == freqNum.end())
        {
            freqNum.insert(countNum);
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool Solution::uniqueOccurrences_2(std::vector<int> &arr)
{
    // 1. Build a frequency map: O(n)
    std::unordered_map<int, int> freq;
    for (int val : arr)
    {
        freq[val]++;
    }

    // 2. Check if each frequency is unique using a set: O(k)
    //    (where k is the number of distinct elements)
    std::unordered_set<int> seen;
    for (auto &p : freq)
    {
        int count = p.second;
        // If we already have this frequency, return false
        if (seen.find(count) != seen.end())
        {
            return false;
        }
        seen.insert(count);
    }

    // If no duplicates in frequencies, return true
    return true;
}
