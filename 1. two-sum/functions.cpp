#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int> nums, int target)
{
    int anchorIndex{0};
    int summedIndex{1};
    long unsigned int vectorSize{nums.size() - 1};
    std::vector<int> index_sum{};

    // Loops through anchors
    for (anchorIndex; anchorIndex <= vectorSize - 1; anchorIndex++)
    {

        // Loops through summed
        for (int i{0}; i < vectorSize - anchorIndex; i++)
        {

            if (nums[anchorIndex] + nums[summedIndex + i] == target)
                index_sum = {anchorIndex, summedIndex + i};
        }

        summedIndex = anchorIndex + 2;
    }

    return index_sum;
}

// -------------------------------------------------

// First Approach
// Time Complexity:O(nlogn)
std::vector<int> twoSum_1(std::vector<int> &nums, int target)
{
    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < nums.size(); i++)
        v.push_back({nums[i], i});
    std::sort(v.begin(), v.end());
    int i = 0;
    int j = v.size() - 1;
    int idx1 = 0;
    int idx2 = 0;
    while (i < j)
    {
        if (v[i].first + v[j].first == target)
        {
            idx1 = v[i].second;
            idx2 = v[j].second;
            break;
        }
        if (v[i].first + v[j].first < target)
            i++;
        if (v[i].first + v[j].first > target)
            j--;
    }
    return {idx1, idx2};
}

// Second Approach
// Time Complexity:O(n)
std::vector<int> twoSum_2(std::vector<int> &nums, int target)
{
    std::vector<int> v;
    std::unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(target - nums[i]) != m.end())
        {
            v.push_back(m[target - nums[i]]);
            v.push_back(i);
            return v;
        }
        else
            m[nums[i]] = i;
    }
    return v;
}

// Third Approach
// Time Complexity: O(n^2)
std::vector<int> twoSum_3(std::vector<int> &nums, int target)
{
    std::vector<int> index;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        int k = target - nums[i];
        for (int j = i + 1; j < size; j++)
        {
            if (nums[j] == k)
            {
                index.push_back(i);
                index.push_back(j);
                break;
            }
        }
        if (index.size() == 2)
            break;
    }
    return index;
}

// ---------------------------------------------------------------------

void print(std::vector<int> const &a)
// Prints a returned vector

{
    std::cout << "{ ";

    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';

    std::cout << "}";
}
