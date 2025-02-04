
#include "functions.h"

std::vector<bool> Solution::kidsWithCandies(std::vector<int> &candies, int extraCandies)
{
    std::vector<bool> result;
    int largestAmmount = 0;
    for (int element : candies)
    {
        if (element > largestAmmount)
        {
            largestAmmount = element;
        }
    }

    for (int element : candies)
    {
        (element + extraCandies >= largestAmmount) ? result.push_back(true) : result.push_back(false);
    }

    return result;
}