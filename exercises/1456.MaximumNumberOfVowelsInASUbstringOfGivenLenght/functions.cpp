
#include "functions.h"
#include <unordered_set>

int Solution::maxVowels(std::string s, int k)
{
    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int current_count = 0;
    int max_count = 0;

    // Initial Window
    for (int i = 0; i < k; i++)
    {
        auto it = vowels.find(s[i]);
        if (it != vowels.end())
        {
            current_count++;
        }
    }

    max_count = current_count; // Store the first window's vowel count

    for (int i = k; i < s.size(); i++)
    {
        // Add new character (right side of the window)
        if (vowels.find(s[i]) != vowels.end())
        {
            current_count++;
        }

        // Remove old character (left side of the window)
        if (vowels.find(s[i - k]) != vowels.end())
        {
            current_count--;
        }
        max_count = std::max(max_count, current_count);
    }

    return max_count;
}