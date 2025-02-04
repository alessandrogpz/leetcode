#define BOOST_TEST_MODULE 443_StringCompression
#include <boost/test/included/unit_test.hpp>
#include "functions.h" // Ensure this header contains the function prototype

Solution solution; // Global instance of the Solution class

BOOST_AUTO_TEST_CASE(test_basic_cases)
{
    std::vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int result1 = solution.compress(chars1);
    std::vector<char> expected1 = {'a', '2', 'b', '2', 'c', '3'};
    BOOST_CHECK_EQUAL(result1, expected1.size());
    BOOST_CHECK_EQUAL_COLLECTIONS(chars1.begin(), chars1.begin() + result1,
                                  expected1.begin(), expected1.end());

    std::vector<char> chars2 = {'a'};
    int result2 = solution.compress(chars2);
    std::vector<char> expected2 = {'a'};
    BOOST_CHECK_EQUAL(result2, expected2.size());
    BOOST_CHECK_EQUAL_COLLECTIONS(chars2.begin(), chars2.begin() + result2,
                                  expected2.begin(), expected2.end());

    std::vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int result3 = solution.compress(chars3);
    std::vector<char> expected3 = {'a', 'b', '1', '2'};
    BOOST_CHECK_EQUAL(result3, expected3.size());
    BOOST_CHECK_EQUAL_COLLECTIONS(chars3.begin(), chars3.begin() + result3,
                                  expected3.begin(), expected3.end());
}

BOOST_AUTO_TEST_CASE(test_edge_cases)
{
    std::vector<char> chars4 = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
    int result4 = solution.compress(chars4);
    std::vector<char> expected4 = {'a', '1', '1'};
    BOOST_CHECK_EQUAL(result4, expected4.size());
    BOOST_CHECK_EQUAL_COLLECTIONS(chars4.begin(), chars4.begin() + result4,
                                  expected4.begin(), expected4.end());

    std::vector<char> chars5 = {'z', 'z', 'z', 'z', 'y', 'y', 'y', 'y', 'y'};
    int result5 = solution.compress(chars5);
    std::vector<char> expected5 = {'z', '4', 'y', '5'};
    BOOST_CHECK_EQUAL(result5, expected5.size());
    BOOST_CHECK_EQUAL_COLLECTIONS(chars5.begin(), chars5.begin() + result5,
                                  expected5.begin(), expected5.end());
}

BOOST_AUTO_TEST_CASE(test_large_group_sizes)
{
    std::vector<char> chars6(2000, 'x'); // 2000 'x' characters
    int result6 = solution.compress(chars6);
    std::vector<char> expected6 = {'x', '2', '0', '0', '0'};
    BOOST_CHECK_EQUAL(result6, expected6.size());
    BOOST_CHECK_EQUAL_COLLECTIONS(chars6.begin(), chars6.begin() + result6,
                                  expected6.begin(), expected6.end());
}

BOOST_AUTO_TEST_CASE(test_mixed_characters)
{
    std::vector<char> chars7 = {'a', 'b', 'c', 'c', 'd', 'd', 'd', 'e', 'f', 'f'};
    int result7 = solution.compress(chars7);
    std::vector<char> expected7 = {'a', 'b', 'c', '2', 'd', '3', 'e', 'f', '2'};
    BOOST_CHECK_EQUAL(result7, expected7.size());
    BOOST_CHECK_EQUAL_COLLECTIONS(chars7.begin(), chars7.begin() + result7,
                                  expected7.begin(), expected7.end());
}
