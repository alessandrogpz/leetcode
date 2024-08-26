#include <iostream>
#include <string>
#include <unordered_map>

int romanToInt(std::string s)
// Convert Roman numbers to decimal.
{
    int index{0};
    int sum{0};

    for (index; index < s.size(); index++)

    {
        if (s[index] == 'I')
        {
            if (s[index + 1] == 'V')
                sum += 4, index++;

            else if (s[index + 1] == 'X')
                sum += 9, index++;

            else
                sum += 1;
        }
        else if (s[index] == 'V')
            sum += 5;

        else if (s[index] == 'X')
        {
            if (s[index + 1] == 'L')
                sum += 40, index += 1;

            else if (s[index + 1] == 'C')
                sum += 90, index++;

            else
                sum += 10;
        }
        else if (s[index] == 'L')
            sum += 50;

        else if (s[index] == 'C')
        {
            if (s[index + 1] == 'D')
                sum += 400, index++;

            else if (s[index + 1] == 'M')
                sum += 900, index++;

            else
                sum += 100;
        }
        else if (s[index] == 'D')
            sum += 500;

        else if (s[index] == 'M')
            sum += 1000;
    }
    return sum;
}

int romanToInt2(std::string s)
/*
Roman numerals are usually written largest to smallest from left to right,
for example: XII (7), XXVII (27), III (3)...
If a small value is placed before a bigger value then it's a combine number,
for exampe: IV (4), IX (9), XIV (14)...
IV = -1 + 5
VI = 5 + 1
XL = -10 + 50
LX = 50 + 10
So, if a smaller number appears before a larger number, it indicates that the number is smaller by a quantity used as a suffix to it,
which made going backwards seem easy.
*/
{
    std::unordered_map<char, int> mp{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
            ans -= mp[s[i]];
        else
            ans += mp[s[i]];
    }
    return ans;
};

int string_loop(std::string s)
// print string size
{

    for (int i = 0; i < s.size(); i++)
        std::cout << s[i] << std::endl;
    return s.size();
}