#include <iostream>
#include <vector>

// Own solution
std::vector<int> plusOne(std::vector<int> &digits)
{
    int numberOfItems{static_cast<int>(digits.size())};
    int lastUsableIndex{numberOfItems - 1};

    if (!digits.empty())
    {
        digits[lastUsableIndex] += 1;

        while (digits[lastUsableIndex] == 10)
        {
            if (lastUsableIndex == 0)
            {
                digits[lastUsableIndex] = 1;
                digits.push_back(0);
                break;
            }
            else
            {
                digits[lastUsableIndex] = 0;
                lastUsableIndex -= 1;
                digits[lastUsableIndex] += 1;
            }
        }
    }

    return digits;
}

// chatGPT solution

/*
This implementation works by iterating over the digits of the input vector from right to left, checking if each digit is equal to 9.
If a digit is not 9, it is incremented by 1 and the resulting vector is returned.
If all digits are 9, they are set to 0 and the loop continues to the next digit.
If the loop completes without returning, it means that all digits were 9, so a new digit 1 is inserted at the beginning of the vector and the resulting vector is returned.

This implementation has a time complexity of O(n), where n is the length of the input vector, since it iterates over the input vector only once.
It also has a space complexity of O(1), since it modifies the input vector in place and does not use any additional data structures.*/
std::vector<int> plusOne2(std::vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] != 9)
        {
            digits[i]++;
            return digits;
        }
        else
        {
            digits[i] = 0;
        }
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

void printVector(const std::vector<int> myVec)
{
    for (const auto &value : myVec)
    {
        std::cout << value << std::endl;
    }
}