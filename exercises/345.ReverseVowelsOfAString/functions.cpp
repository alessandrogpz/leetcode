#include "functions.h"

// Dynamic allocating memory for an array
std::string Solution::reverseVowels(std::string s)
{

    // char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int currentArrSize = 0;
    char *charArr = nullptr; // Start with nullptr

    for (char c : s)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            char *newCharArr = new char[currentArrSize + 1];

            for (int i = 0; i < currentArrSize; i++)
            {
                newCharArr[i] = charArr[i]; // Copy old elements
            }

            newCharArr[currentArrSize] = c; // Add the new character
            currentArrSize++;

            delete[] charArr;     // Free old array
            charArr = newCharArr; // Update pointer
        }
    }

    for (size_t i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            s[i] = charArr[currentArrSize - 1];
            currentArrSize--;
        }
    }

    // // Print each character using indexing
    // for (int i = 0; i < s.length(); i++)
    // {
    //     std::cout << s[i] << " ";
    // }

    // std::cout << std::endl;

    delete[] charArr; // Free allocated memory
    return s;
}

// Two pointer solution
std::string Solution::reverseVowels2(std::string s)
{
    int left = 0, right = s.size() - 1;
    std::string vowels = "aeiouAEIOU";

    while (left < right)
    {
        while (left < right && vowels.find(s[left]) == std::string::npos)
            left++;
        while (left < right && vowels.find(s[right]) == std::string::npos)
            right--;
        std::swap(s[left++], s[right--]);
    }
    return s;
}
