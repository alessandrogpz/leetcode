#include "functions.h"

// My Solution
int removeElement(std::vector<int> &nums, int val)
{

    int index{0};

    for (index; index < nums.size(); index++)
    {
        if (nums.empty())
        {
            return 0;
        }
        else
        {
            if (nums[index] == val)
            {
                nums.erase(nums.begin() + index);
                index -= 1;
            }
        }
    }
    return index;
}

// chatGPT solution
int removeElement2(std::vector<int> &nums, int val)
{
    int k = 0; // index of the last element in the resulting array
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[k++] = nums[i];
        }
    }
    return k;
}

void printVEctor(const std::vector<int> nums)
{
    for (int val : nums)
    {
        std::cout << val << std::endl;
    }
}