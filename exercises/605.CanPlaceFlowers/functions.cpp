
#include "functions.h"

bool Solution::canPlaceFlowers(std::vector<int> &flowerbed, int n)
{
    if (n == 0)
        return true;

    if (flowerbed.size() == 1)
    {
        if (flowerbed[0] == 0 && n == 1)
        {
            return true;
        }
    }

    int remainingSeeds = n;
    for (size_t i = 0; i < flowerbed.size(); ++i)
    {

        // First Element
        if (i == 0)
        {
            if (flowerbed[0] == 0 && flowerbed[1] == 0)
            {
                flowerbed[0] = 1;
                remainingSeeds -= 1;
            }
        }
        // Last Element
        else if (i == flowerbed.size() - 1)
        {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                remainingSeeds -= 1;
            }
        }
        else
        {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                remainingSeeds -= 1;
            }
        }

        if (remainingSeeds == 0)
        {
            return true;
        }
    }

    return false;
}