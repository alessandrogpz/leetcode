#define BOOST_TEST_MODULE find-pivot-index
#include <boost/test/included/unit_test.hpp>

#include "functions.h"

std::vector<int> nums1 {1,7,3,6,5,6};
std::vector<int> nums2 {2, 1,-1, 0, 0};
std::vector<int> nums3 {1,-1, 0, 0, 2};
std::vector<int> nums4 {20};
std::vector<int> nums5 {20, 30};
std::vector<int> nums6 {1,2,3};
std::vector<int> nums7 {-1,-1,-1,-1,-1,0};

BOOST_AUTO_TEST_CASE(first_test)
{
  BOOST_TEST(compareElementsByIndex(nums1) == 3);
}

BOOST_AUTO_TEST_CASE(second_test)
{
  BOOST_TEST(compareElementsByIndex(nums2) == 0);
}

BOOST_AUTO_TEST_CASE(third_test)
{
  BOOST_TEST(compareElementsByIndex(nums3) == 4);
}

BOOST_AUTO_TEST_CASE(fourth_test)
{
  BOOST_TEST(compareElementsByIndex(nums4) == 20);
}

BOOST_AUTO_TEST_CASE(fifth_test)
{
  BOOST_TEST(compareElementsByIndex(nums5) == -1);
}

BOOST_AUTO_TEST_CASE(sixth_test)
{
  BOOST_TEST(compareElementsByIndex(nums6) == -1);
}

BOOST_AUTO_TEST_CASE(seventh_test)
{
  BOOST_TEST(compareElementsByIndex(nums7) == 2);
}