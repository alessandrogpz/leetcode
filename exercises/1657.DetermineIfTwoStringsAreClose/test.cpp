#define BOOST_TEST_MODULE 1657.DetermineIfTwoStringsAreClose
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

Solution solution;

// ------------------------------------------------------------------
// Official Examples
// ------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(test_example1)
{
    // word1 = "abc", word2 = "bca"
    // Output: true
    // Explanation:
    // - We can achieve "bca" from "abc" by two swaps (Operation 1).
    // - So the function should return true.
    BOOST_CHECK_EQUAL(solution.closeStrings("abc", "bca"), true);
}

BOOST_AUTO_TEST_CASE(test_example2)
{
    // word1 = "a", word2 = "aa"
    // Output: false
    // Explanation:
    // - It's impossible to form "aa" from "a" because word1 has only 1 character
    //   while word2 needs 2 occurrences of 'a'.
    // - So the function should return false.
    BOOST_CHECK_EQUAL(solution.closeStrings("a", "aa"), false);
}

BOOST_AUTO_TEST_CASE(test_example3)
{
    // word1 = "cabbba", word2 = "abbccc"
    // Output: true
    // Explanation:
    // "cabbba" -> "caabbb" (swap)
    // "caabbb" -> "baaccc" (transform a <-> b)
    // "baaccc" -> "abbccc" (transform b <-> c)
    // So the function should return true.
    BOOST_CHECK_EQUAL(solution.closeStrings("cabbba", "abbccc"), true);
}

// ------------------------------------------------------------------
// Additional Tests
// ------------------------------------------------------------------

BOOST_AUTO_TEST_CASE(test_identical_strings)
{
    // If both words are identical, they are trivially "close"
    // because no transformations are needed.
    // For instance: "abc" and "abc".
    std::string word1 = "abc";
    std::string word2 = "abc";
    BOOST_CHECK_EQUAL(solution.closeStrings(word1, word2), true);
}

BOOST_AUTO_TEST_CASE(test_different_length_but_same_characters)
{
    // If the lengths differ, they generally cannot be close,
    // because you cannot create extra characters out of nothing
    // or remove them via just swaps/transforming characters.
    // Example: "ab" vs "abb"
    BOOST_CHECK_EQUAL(solution.closeStrings("ab", "abb"), false);
}

BOOST_AUTO_TEST_CASE(test_same_characters_different_frequencies)
{
    // "aabb" vs "abbb"
    // Both have the same set of characters {'a', 'b'},
    // but the frequency distributions are different (2x'a' + 2x'b' vs 1x'a' + 3x'b').
    // This might or might not be transformable. Let's see:
    // - Operation 2 swaps characters entirely (e.g., every 'a' becomes 'b').
    //   We can't just "shift" one 'a' into 'b' without shifting them all.
    // So "aabb" can't become "abbb" because "aabb" has 2 'a's and 2 'b's,
    // while "abbb" has 1 'a' and 3 'b's.
    // A swap operation won't fix the mismatch in the total counts.
    // => false
    BOOST_CHECK_EQUAL(solution.closeStrings("aabb", "abbb"), false);
}

BOOST_AUTO_TEST_CASE(test_same_frequency_distribution)
{
    // "xxyyzz" vs "yyzzxx"
    // Both have 2 'x', 2 'y', 2 'z'.
    // The sets of characters and their frequencies match.
    // By swapping and/or transforming (if needed), we can form one from the other.
    // => true
    BOOST_CHECK_EQUAL(solution.closeStrings("xxyyzz", "yyzzxx"), true);
}

BOOST_AUTO_TEST_CASE(test_multiple_characters_same_frequencies)
{
    // "aaabbbbccc" vs "bbbcccaaab"
    // word1 has: 3 'a', 4 'b', 3 'c'
    // word2 has: 3 'b', 3 'a', 4 'c' (just shuffled among 'a','b','c').
    // They have the same set of characters and same frequency multiset: {3,4,3}.
    // With swaps and transformations, they should be considered close.
    BOOST_CHECK_EQUAL(solution.closeStrings("aaabbbbccc", "bbbcccaaab"), true);
}

BOOST_AUTO_TEST_CASE(test_disjoint_character_sets)
{
    // "abc" vs "def"
    // They have different character sets,
    // so there's no way to transform "abc" into "def" using the allowed operations
    // since you'd need to introduce new characters that don't appear in the original.
    // => false
    BOOST_CHECK_EQUAL(solution.closeStrings("abc", "def"), false);
}

BOOST_AUTO_TEST_CASE(test_partial_overlap_character_sets)
{
    // "abbc" vs "abcc"
    // 'abbc' => characters {a, b, c} with frequencies {1, 2, 1}
    // 'abcc' => characters {a, b, c} with frequencies {1, 1, 2}
    // They have the same set of characters, but the frequency distribution is not the same.
    // Frequencies for 'abbc': a=1, b=2, c=1
    // Frequencies for 'abcc': a=1, b=1, c=2
    // Since the "counts of counts" are the same ( {1,2,1} vs {1,1,2} ) except in a different arrangement,
    // we can transform character 'b' <-> 'c' if needed. That would swap the frequencies of b and c.
    // => This is likely "true" because we can apply Operation 2 to swap 'b' and 'c' entirely.
    BOOST_CHECK_EQUAL(solution.closeStrings("abbc", "abcc"), true);
}
