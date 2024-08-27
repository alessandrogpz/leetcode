#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    int i = 0; // current index
    int j = 1; // index for next unique element

    while (j < nums.size())
    {
        if (nums[j] == nums[i])
        {
            j++;
        }
        else
        {
            i++;
            nums[i] = nums[j];
            j++;
        }
    }

    return i + 1; // return the number of unique elements
}

void printVector(const std::vector<int> nums)
{
    for (int index; index < nums.size(); index++)
    {
        std::cout << nums[index] << std::endl;
    }
}

void removeOneItem(std::vector <int> &nums)
{
    nums.erase(nums.begin() + 1);
}