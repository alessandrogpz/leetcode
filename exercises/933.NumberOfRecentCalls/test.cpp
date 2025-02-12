#define BOOST_TEST_MODULE 933.NumberOfRecentCalls
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

// Example test case using the provided example from the problem statement.
BOOST_AUTO_TEST_CASE(example_test)
{
    RecentCounter *obj1 = new RecentCounter();
    // The following calls correspond to the sample:
    // recentCounter.ping(1) should return 1, since requests = [1]
    BOOST_CHECK_EQUAL(obj1->ping(1), 1);

    // recentCounter.ping(100) should return 2, since requests = [1, 100]
    BOOST_CHECK_EQUAL(obj1->ping(100), 2);

    // recentCounter.ping(3001) should return 3, since requests = [1, 100, 3001]
    BOOST_CHECK_EQUAL(obj1->ping(3001), 3);

    // recentCounter.ping(3002) should return 3, since the request at time 1 is now out of the [t-3000, t] range
    BOOST_CHECK_EQUAL(obj1->ping(3002), 3);

    delete obj1;
}

// Additional test case to further validate the functionality.
BOOST_AUTO_TEST_CASE(additional_test)
{
    RecentCounter *obj2 = new RecentCounter();

    // First call: only one request at time 100.
    BOOST_CHECK_EQUAL(obj2->ping(100), 1);

    // Second call at time 3100. Valid range is [3100 - 3000, 3100] = [100, 3100],
    // so both 100 and 3100 are valid => count = 2.
    BOOST_CHECK_EQUAL(obj2->ping(3100), 2);

    // Third call at time 3200. Valid range is [3200 - 3000, 3200] = [200, 3200].
    // The request at 100 is now out of range, leaving [3100, 3200] => count = 2.
    BOOST_CHECK_EQUAL(obj2->ping(3200), 2);

    // Fourth call at time 4000. Valid range is [4000 - 3000, 4000] = [1000, 4000].
    // Valid pings: 3100, 3200, 4000 => count = 3.
    BOOST_CHECK_EQUAL(obj2->ping(4000), 3);

    // Fifth call at time 5000. Valid range is [5000 - 3000, 5000] = [2000, 5000].
    // Valid pings: 3100, 3200, 4000, 5000 => count = 4.
    BOOST_CHECK_EQUAL(obj2->ping(5000), 4);

    delete obj2;
}
