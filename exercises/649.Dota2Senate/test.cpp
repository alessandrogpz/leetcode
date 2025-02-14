#define BOOST_TEST_MODULE 649.Dota2Senate
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

// Global instance of the Solution class.
Solution solution;

// Example test case using the sample provided in the problem statement.
BOOST_AUTO_TEST_CASE(Example1)
{
    // Input: "RD" should result in Radiant winning.
    BOOST_CHECK_EQUAL(solution.predictPartyVictory("RD"), "Radiant");
}

// Example test case using the sample provided in the problem statement.
BOOST_AUTO_TEST_CASE(Example2)
{
    // Input: "RDD" should result in Dire winning.
    BOOST_CHECK_EQUAL(solution.predictPartyVictory("RDD"), "Dire");
}

// Additional test: All Radiant senators.
BOOST_AUTO_TEST_CASE(AllRadiant)
{
    // If the senate consists only of Radiant senators, the result should be Radiant.
    BOOST_CHECK_EQUAL(solution.predictPartyVictory("RRRRR"), "Radiant");
}

// Additional test: All Dire senators.
BOOST_AUTO_TEST_CASE(AllDire)
{
    // If the senate consists only of Dire senators, the result should be Dire.
    BOOST_CHECK_EQUAL(solution.predictPartyVictory("DDDD"), "Dire");
}

// Additional test: A more mixed case.
BOOST_AUTO_TEST_CASE(MixedCase)
{
    // This is an additional test. The expected output ("Radiant" or "Dire") must be determined
    // based on the optimal strategy simulation. For instance, assume the string "DRRDRDR" results in "Radiant".
    BOOST_CHECK_EQUAL(solution.predictPartyVictory("DRRDRDR"), "Radiant");
}
