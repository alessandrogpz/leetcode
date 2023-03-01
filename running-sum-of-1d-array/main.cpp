// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

// Return the running sum of nums.

// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

#include "functions.h"

int main()
{

    std::vector<int> array_1 = {1, 2, 3, 4, 5};

    std::vector<int> new_vector{runningSumOf1DArray(array_1)};

    std::cout << "[";
    for (int i : new_vector)
        std::cout << i << ", ";

    std::cout << "]";

    return 0;
}