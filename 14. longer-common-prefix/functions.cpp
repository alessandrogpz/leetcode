#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string longestCommonPrefix(std::vector<std::string> &strs)
{
    bool isStillValid = true;
    std::string prefixChecked = "";
    int smallerWordSize = strs[0].length();

    // Find the size of the smallest word
    for (int word = 1; word <= strs.size(); word++)
    {
        if (strs[word].length() < smallerWordSize)
            smallerWordSize = strs[word].length();
    }

    // Main loop
    if (strs.size() == 1)
        return strs[0];

    else
    {
        // loop trhough char indexes (ci)
        for (int ci{0}; ci < smallerWordSize; ci++)
        {
            char tempChar = strs[0][ci];

            // loop through word indexes (wi)
            for (int wi{0}; wi < strs.size(); wi++)
            {
                if (strs[wi][ci] == tempChar)
                    continue;
                else
                {
                    isStillValid = false;
                    break;
                }
            }

            if (isStillValid == true)
            {
                prefixChecked += tempChar;
            }
            else
                break;
        }
    }

    if (prefixChecked.length() == 0)
        return "";
    else
        return prefixChecked;
}

// Alternative
std::string longestCommonPrefix_1(std::vector<std::string> &strs)
{
    /*
    The longest common prefix is common to all the strings.
    So, we can fix one string and check the common prefix of this string with other strings.
    The minimum such length is found and the answer is the substring of the fixed string starting from 0 to the length of the above such minimum.
    Here, I have fixed 0th string and checked other strings with this.
    */

    int ans = strs[0].length(), n = strs.size();
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (j < strs[i].length() && strs[i][j] == strs[0][j])
            j++;
        ans = std::min(ans, j);
    }
    return strs[0].substr(0, ans);
}
