#define BOOST_TEST_MODULE "running sum of 1d array"
#include <boost/test/included/unit_test.hpp>

#include "functions.h"

BOOST_AUTO_TEST_CASE(free_test_function)
/* Compare with void free_test_function() */
{
    std::vector<int> vector_1{1, 2, 3, 4, 5};
    std::vector<int> vector_2{1, 1, 1, 1, 1};
    std::vector<int> vector_3{3, 1, 2, 10, 1};

    std::vector<int> rs_vector_1{runningSumOf1DArray(vector_1)};
    std::vector<int> rs_vector_1_test{1, 3, 6, 10, 15};

    std::vector<int> rs_vector_2{runningSumOf1DArray(vector_2)};
    std::vector<int> rs_vector_2_test{1, 2, 3, 4, 5};

    std::vector<int> rs_vector_3{runningSumOf1DArray(vector_3)};
    std::vector<int> rs_vector_3_test{3, 4, 6, 16, 17};

    BOOST_TEST(rs_vector_1 == rs_vector_1_test, boost::test_tools::per_element());
    BOOST_TEST(rs_vector_2 == rs_vector_2_test, boost::test_tools::per_element());
    BOOST_TEST(rs_vector_3 == rs_vector_3_test, boost::test_tools::per_element());
}