// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal
// substring
//  consisting of non-space characters only.

// Example 1:
// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.

// Example 2:
// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.

// Example 3:
// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.

// Constraints:
// 1 <= s.length <= 104
// s consists of only English letters and spaces ' '.
// There will be at least one word in s.

#include <iostream>
#include <string>

class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        std::string word = "";
        bool space = false;

        for (char c : s)
        {
            if (std::isalpha(c) && space == false)
            {
                word += c;
                space = false;
            }
            else if (std::isalpha(c) && space == true)
            {
                word = "";
                word += c;
                space = false;
            }
            else
            {
                space = true;
            }
        }
        return word.length();
    }
};

int main()
{
    Solution solution;

    std::string one = "Hello World";
    std::string two = "   fly me   to   the moon  ";
    std::string three = "luffy is still joyboy";

    std::cout << solution.lengthOfLastWord(one) << std::endl;
    std::cout << solution.lengthOfLastWord(two) << std::endl;
    std::cout << solution.lengthOfLastWord(three) << std::endl;

    return 0;
}