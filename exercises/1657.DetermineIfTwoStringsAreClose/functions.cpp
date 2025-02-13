
#include "functions.h"
#include <iostream>

bool Solution::closeStrings(std::string word1, std::string word2)
{
    std::unordered_map<char, int> word1Map = {};
    std::unordered_map<char, int> word2Map = {};

    std::unordered_set<char> word1Set = {};
    std::unordered_set<char> word2Set = {};

    std::vector<int> word1Values = {};
    std::vector<int> word2Values = {};

    // Pupulate hashmap & hashset for word1
    for (char ch : word1)
    {
        word1Map[ch]++; // Increments the count, initializes if not present
        word1Set.insert(ch);
    }

    // Pupulate value vector for word 1
    for (const auto &pair : word1Map)
    {
        word1Values.push_back(pair.second);
    }

    // Pupulate hashmap & hashset for word1
    for (char ch : word2)
    {
        word2Map[ch]++; // Increments the count, initializes if not present
        word2Set.insert(ch);
    }

    // Pupulate value vector for word 1
    for (const auto &pair : word2Map)
    {
        word2Values.push_back(pair.second);
    }

    // If the two unordered_map do not have the same size, return false.
    if (word1Map.size() != word2Map.size())
        return false;

    // If the the unordered_maps have the same size, but not the same elements (keys), return false.
    if (word1Set != word2Set)
        return false;

    // Check if all different value occuances for a letter can be permutated.
    std::sort(word1Values.begin(), word1Values.end());
    std::sort(word2Values.begin(), word2Values.end());
    for (int i = 0; i < word1Values.size(); ++i)
    {
        if (word1Values[i] != word2Values[i])
            return false;
    }

    return true;
}
