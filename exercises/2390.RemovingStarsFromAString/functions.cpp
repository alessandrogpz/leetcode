
#include "functions.h"

std::string Solution::removeStars_1(std::string s)
{
    std::string updatedStr = "";
    std::stack<char> s_stack = {};
    int n_stars = 0;

    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == '*')
        {
            n_stars++;
        }

        s_stack.push(s[i]);
    }

    while (!s_stack.empty())
    {
        if (s_stack.top() != '*')
        {
            updatedStr.push_back(s_stack.top());
            s_stack.pop();
        }
        else if (!s_stack.empty() && s_stack.top() == '*')
        {
            // Make sure updatedStr is not empty before erasing
            if (!updatedStr.empty())
            {
                int RemoveAt = updatedStr.size() - 1;
                updatedStr.erase(RemoveAt, 1);
            }
            s_stack.pop();
        }
    }
    return updatedStr;
}

std::string Solution::removeStars_2(std::string s)
{
    std::stack<char> st;

    for (char &el : s)
    {
        if (el == '*')
        {
            st.pop();
        }
        else
        {
            st.push(el);
        }
    }

    s.erase(s.begin(), s.end());
    while (!st.empty())
    {
        s += st.top();
        st.pop();
    }

    std::reverse(s.begin(), s.end());
    return s;
}