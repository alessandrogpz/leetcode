
#include "functions.h"

bool Solution::isSubsequence(std::string s, std::string t)
{
    bool FIRST_CHAR = false;
    bool SECOND_CHAR = true;
    int S_INDEX = 0;
    int S_SIZE = s.size();

    // Returns true if the substring is empty
    if (S_SIZE == 0)
        return true;

    for (int i = 0; i < t.size(); ++i)
    {
        // Tracks FIRST_CHAR nd resets SECOND_CHAR
        if (t[i] == s[S_INDEX] && FIRST_CHAR == false && SECOND_CHAR == true)
        {
            FIRST_CHAR = true;
            SECOND_CHAR = false;
            ++S_INDEX;
        }
        // Traccks SECOND_CHAR and resets FIRST_CHAR
        else if (t[i] == s[S_INDEX] && FIRST_CHAR == true && SECOND_CHAR == false)
        {
            FIRST_CHAR = false;
            SECOND_CHAR = true;
            ++S_INDEX;
        }

        if (S_INDEX == S_SIZE)
            return true;
    }

    return false;
}