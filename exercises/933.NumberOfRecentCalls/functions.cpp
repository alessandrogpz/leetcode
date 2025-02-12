
#include "functions.h"

// Constructor: Initializes the RecentCounter with an empty queue.
RecentCounter::RecentCounter()
{
    // Nothing special to initialize since the queue starts empty.
}

// The ping function adds a new request at time t and returns
// the number of requests in the time range [t - 3000, t].
int RecentCounter::ping(int t)
{
    // Add the new ping time into the queue.
    q.push(t);

    // Remove any ping times that are older than t - 3000.
    while (!q.empty() && q.front() < t - 3000)
    {
        q.pop();
    }

    // The size of the queue now represents the number of pings
    // in the last 3000 milliseconds.
    return q.size();
}