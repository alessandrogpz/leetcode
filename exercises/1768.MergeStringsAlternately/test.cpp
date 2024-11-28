#define BOOST_TEST_MODULE MergeAlternatelyTest
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

// Fixture to create an instance of the Solution class for testing
struct SolutionFixture {
    Solution solution;
};

// Test case for Example 1
BOOST_FIXTURE_TEST_CASE(Example1, SolutionFixture) {
    std::string word1 = "abc";
    std::string word2 = "pqr";
    BOOST_CHECK_EQUAL(solution.mergeAlternately(word1, word2), "apbqcr");
}

// Test case for Example 2
BOOST_FIXTURE_TEST_CASE(Example2, SolutionFixture) {
    std::string word1 = "ab";
    std::string word2 = "pqrs";
    BOOST_CHECK_EQUAL(solution.mergeAlternately(word1, word2), "apbqrs");
}

// Test case for Example 3
BOOST_FIXTURE_TEST_CASE(Example3, SolutionFixture) {
    std::string word1 = "abcd";
    std::string word2 = "pq";
    BOOST_CHECK_EQUAL(solution.mergeAlternately(word1, word2), "apbqcd");
}

// Test case for edge case: both strings are empty
BOOST_FIXTURE_TEST_CASE(EmptyStrings, SolutionFixture) {
    std::string word1 = "";
    std::string word2 = "";
    BOOST_CHECK_EQUAL(solution.mergeAlternately(word1, word2), "");
}

// Test case for edge case: one string is empty
BOOST_FIXTURE_TEST_CASE(OneStringEmpty, SolutionFixture) {
    std::string word1 = "abc";
    std::string word2 = "";
    BOOST_CHECK_EQUAL(solution.mergeAlternately(word1, word2), "abc");

    word1 = "";
    word2 = "xyz";
    BOOST_CHECK_EQUAL(solution.mergeAlternately(word1, word2), "xyz");
}

// Test case for edge case: strings of length 1
BOOST_FIXTURE_TEST_CASE(SingleCharacterStrings, SolutionFixture) {
    std::string word1 = "a";
    std::string word2 = "b";
    BOOST_CHECK_EQUAL(solution.mergeAlternately(word1, word2), "ab");
}

// Test case for edge case: longer strings
BOOST_FIXTURE_TEST_CASE(LongerStrings, SolutionFixture) {
    std::string word1 = "abcdefghijklmnopqrstuvwxyz";
    std::string word2 = "1234567890";
    BOOST_CHECK_EQUAL(solution.mergeAlternately(word1, word2),
        "a1b2c3d4e5f6g7h8i9j0klmnopqrstuvwxyz");
}
