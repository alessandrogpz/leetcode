#include "functions.h"

#define BOOST_TEST_MODULE RemoveDuplicatesTest
#include <boost/test/included/unit_test.hpp>


int removeDuplicates(std::vector<int> &nums);

BOOST_AUTO_TEST_SUITE(RemoveDuplicateTestSuite)

BOOST_AUTO_TEST_CASE(EmptyVectorTest)
{
    std::vector<int> nums;
    BOOST_CHECK_EQUAL(removeDuplicates(nums), 0);
}

BOOST_AUTO_TEST_CASE(NoDuplicatesTest)
{
    std::vector<int> nums{1, 2, 3, 4, 5};
   
    BOOST_CHECK_EQUAL(removeDuplicates(nums), 5);

}

BOOST_AUTO_TEST_CASE(SingleDuplicateTest)
{
    std::vector<int> nums{1, 2, 2, 3, 4, 5};

    BOOST_CHECK_EQUAL(removeDuplicates(nums), 5);

}

BOOST_AUTO_TEST_CASE(MultipleDuplicatesTest)
{
    std::vector<int> nums{1, 2, 2, 3, 3, 3, 4, 5, 5};

    BOOST_CHECK_EQUAL(removeDuplicates(nums), 5);

}

BOOST_AUTO_TEST_CASE(AllDuplicatesTest)
{
    std::vector<int> nums{1, 1, 1, 1};

    BOOST_CHECK_EQUAL(removeDuplicates(nums), 1);

}

BOOST_AUTO_TEST_CASE(NegativeNumbersTest)
{
    std::vector<int> nums{-2, -2, -1, 0, 0, 1, 1, 1, 2, 2, 3};

    BOOST_CHECK_EQUAL(removeDuplicates(nums), 6);

}

BOOST_AUTO_TEST_CASE(LargeNumbersTest)
{
    std::vector<int> nums{-1000000, -1000000, 1000000, 1000000};

    BOOST_CHECK_EQUAL(removeDuplicates(nums), 2);

}

BOOST_AUTO_TEST_CASE(DuplicateAtEndTest)
{
    std::vector<int> nums{1, 2, 3, 4, 5, 5};

    BOOST_CHECK_EQUAL(removeDuplicates(nums), 5);

}

BOOST_AUTO_TEST_CASE(DuplicateAtStartTest)
{
    std::vector<int> nums{1, 1, 2, 3, 4, 5};

    BOOST_CHECK_EQUAL(removeDuplicates(nums), 5);

}

BOOST_AUTO_TEST_CASE(DuplicateAtMiddleTest)
{
    std::vector<int> nums{1, 2, 2, 2, 3, 4, 5};

    BOOST_CHECK_EQUAL(removeDuplicates(nums), 5);

}

BOOST_AUTO_TEST_SUITE_END()