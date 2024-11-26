
#include "functions.h"

int longestConsecutive(std::vector<int> &nums)
{
    // Create an unordered_set from nums for O(1) lookups
    std::unordered_set<int> uset(nums.begin(), nums.end());

    int longest = 0;

    for (int element : uset)
    {
        // Check if the current element is the start of a sequence
        if (uset.find(element - 1) == uset.end()) // If element - 1 is not in the set
        {
            int length = 1; // Start counting the sequence
            int current = element;

            // Count the length of the consecutive sequence
            while (uset.find(current + 1) != uset.end())
            {
                current += 1;
                length += 1;
            }

            // Update the longest sequence length
            longest = std::max(longest, length);
        }
    }
    return longest;
}
