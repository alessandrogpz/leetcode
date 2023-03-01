#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> nums{};

void print_each_digit(int x)
{
    if (x >= 10)
        print_each_digit(x / 10);

    int digit = x % 10;

    std::cout << "digit: " << digit << "\n";
}

std::vector<int> separate_digits_into_vector(int x)
{
    if (x >= 10)
        separate_digits_into_vector(x / 10);

    int digit = x % 10;
    nums.push_back(digit);

    return nums;
}

void print_vector(std::vector<int> const &a)
{
    std::cout << "{ ";

    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';

    std::cout << "}";
}

bool is_palindrome(int x)
{
    std::vector<int> nums{separate_digits_into_vector(x)};

    long unsigned int l_index{0};
    long unsigned int r_index{nums.size() - 1};

    if (x < 0)
    {
        return false;
    }
    else if (nums.size() == 1)
    {
        return true;
    }
    else
    {
        while (l_index <= r_index)
        {
            if (nums[l_index] == nums[r_index])
            {
                l_index += 1;
                r_index -= 1;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
}

// --------- Alternative solutions ----------

bool is_palindrome_1(int x)
/*
Convert the number to a string, revert it and compare.
Return true if x is a palindrome.
*/
{
    std::string rev = std::to_string(x);
    reverse(rev.begin(), rev.end());
    return std::to_string(x) == rev;
}

bool is_palindrome_2(int x)
/*
Convert the number to a string, then use two pointers at beginning and end to check if it's a palindrome.
Return true if x is a palindrome.
*/
{
    std::string s = std::to_string(x);
    int i = 0, j = s.size() - 1;
    while (i <= j)
        if (s[i++] != s[j--])
            return false;
    return true;
}

bool is_palindrome_3(int x)
/*
Reverse the second half of the number and then compare.
Return true if x is a palindrome.
*/
{
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;
    int rev = 0;
    while (rev < x)
    {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    return x == rev || x == rev / 10;
}