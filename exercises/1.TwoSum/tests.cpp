#define BOOST_TEST_MODULE boost_test_sequence
#include <boost/test/included/unit_test.hpp>
#include <vector>
#include "functions.h"

BOOST_AUTO_TEST_CASE(test_collections_vectors)
{
    std::vector<int> nums_1{2, 7, 11, 15};
    std::vector<int> res_1{0, 1};

    std::vector<int> nums_2{3, 2, 4};
    std::vector<int> res_2{1, 2};

    std::vector<int> nums_3{3, 3};
    std::vector<int> res_3{0, 1};

    BOOST_TEST(twoSum(nums_1, 9) == res_1, boost::test_tools::per_element());
    BOOST_TEST(twoSum(nums_2, 6) == res_2, boost::test_tools::per_element());
    BOOST_TEST(twoSum(nums_3, 6) == res_3, boost::test_tools::per_element());
}