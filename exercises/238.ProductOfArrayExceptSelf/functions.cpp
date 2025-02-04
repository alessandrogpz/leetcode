#include "functions.h"

std::vector<int> Solution::productExceptSelf(std::vector<int> &nums)
{
    int vecSize = nums.size();

    std::vector<int> leftProd(vecSize, 1);
    std::vector<int> rightProd(vecSize, 1);
    std::vector<int> finalProdVec(vecSize, 1);

    int leftCumul = 1;
    for (int indexL = 1; indexL < vecSize; indexL++)
    {
        leftCumul *= nums[indexL - 1];
        leftProd[indexL] = leftCumul;
    }

    int rightCumul = 1;
    for (int indexR = vecSize - 2; indexR >= 0; indexR--)
    {
        rightCumul *= nums[indexR + 1];
        rightProd[indexR] = rightCumul;
    }

    for (int i = 0; i < vecSize; i++)
    {
        finalProdVec[i] = leftProd[i] * rightProd[i];
    }

    return finalProdVec;
};
