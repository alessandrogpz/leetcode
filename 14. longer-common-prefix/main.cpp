/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.*/

#include "functions.h"

int main()
{
    std::vector<std::string> strs{"flower", "flow", "flight"};
    // std::vector<std::string> strs{"dog", "racecar", "car"};

    std::cout << longestCommonPrefix(strs);

    return 0;
}
