
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <queue>

class RecentCounter
{
public:
    std::queue<int> q; // Queue to store the timestamps of the pings
    RecentCounter();
    int ping(int t);
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

#endif
