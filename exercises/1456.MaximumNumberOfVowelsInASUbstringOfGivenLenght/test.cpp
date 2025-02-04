#define BOOST_TEST_MODULE 1456.MaximumNumberOfVowelsInASUbstringOfGivenLenght
#include <boost/test/included/unit_test.hpp>
#include "functions.h" // This header should declare the Solution class and maxVowels method

Solution solution;

BOOST_AUTO_TEST_CASE(test_example1)
{
    // Example 1:
    // Input: s = "abciiidef", k = 3
    // Output: 3 (substring "iii")
    std::string s = "abciiidef";
    int k = 3;
    int expected = 3;
    BOOST_CHECK_EQUAL(solution.maxVowels(s, k), expected);
}

BOOST_AUTO_TEST_CASE(test_example2)
{
    // Example 2:
    // Input: s = "aeiou", k = 2
    // Output: 2 (any substring of length 2 has 2 vowels)
    std::string s = "aeiou";
    int k = 2;
    int expected = 2;
    BOOST_CHECK_EQUAL(solution.maxVowels(s, k), expected);
}

BOOST_AUTO_TEST_CASE(test_example3)
{
    // Example 3:
    // Input: s = "leetcode", k = 3
    // Output: 2 (substrings "lee", "eet", "ode" have 2 vowels)
    std::string s = "leetcode";
    int k = 3;
    int expected = 2;
    BOOST_CHECK_EQUAL(solution.maxVowels(s, k), expected);
}

BOOST_AUTO_TEST_CASE(test_all_vowels)
{
    // All vowels in the string
    std::string s = "aaaaa";
    int k = 3;
    int expected = 3; // Every substring of length 3 is "aaa"
    BOOST_CHECK_EQUAL(solution.maxVowels(s, k), expected);
}

BOOST_AUTO_TEST_CASE(test_all_consonants)
{
    // All consonants in the string
    std::string s = "bcdfgh";
    int k = 3;
    int expected = 0; // No vowels at all
    BOOST_CHECK_EQUAL(solution.maxVowels(s, k), expected);
}

BOOST_AUTO_TEST_CASE(test_mixed_vowels_consonants)
{
    // Mixed vowels and consonants
    std::string s = "aabab";
    int k = 2;
    int expected = 2; // Best substring "aa" has 2 vowels
    BOOST_CHECK_EQUAL(solution.maxVowels(s, k), expected);
}

BOOST_AUTO_TEST_CASE(test_full_length_substring)
{
    // k equals the entire string length
    std::string s = "abcde";
    int k = 5;
    int expected = 2; // "abcde" contains vowels 'a' and 'e'
    BOOST_CHECK_EQUAL(solution.maxVowels(s, k), expected);
}

BOOST_AUTO_TEST_CASE(test_single_character_no_vowel)
{
    // k = 1 in a string with no vowels
    std::string s = "rhythm";
    int k = 1;
    int expected = 0;
    BOOST_CHECK_EQUAL(solution.maxVowels(s, k), expected);
}

BOOST_AUTO_TEST_CASE(test_single_character_vowel)
{
    // k = 1 in a string with vowels
    std::string s = "aeiou";
    int k = 1;
    int expected = 1;
    BOOST_CHECK_EQUAL(solution.maxVowels(s, k), expected);
}

BOOST_AUTO_TEST_CASE(test_entire_string_as_substring)
{
    // k equals string length with only one vowel in the string
    std::string s = "qwert";
    int k = 5;
    int expected = 1; // Only "e" is a vowel
    BOOST_CHECK_EQUAL(solution.maxVowels(s, k), expected);
}
