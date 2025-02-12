## Problem Statement

You have a `RecentCounter` class that counts the number of recent requests within a specified time frame. Implement the class with the following operations:

- **`RecentCounter()`**: Initializes the counter with zero recent requests.
- **`int ping(int t)`**: Adds a new request at time `t` (in milliseconds) and returns the number of requests that have happened in the past 3000 milliseconds (inclusive of `t`). In other words, return the number of requests within the time window `[t - 3000, t]`.

**Example:**

```
Input: ["RecentCounter", "ping", "ping", "ping", "ping"]
       [[], [1], [100], [3001], [3002]]
Output: [null, 1, 2, 3, 3]

Explanation:
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1], valid range is [-2999, 1] -> returns 1
recentCounter.ping(100);   // requests = [1, 100], valid range is [-2900, 100] -> returns 2
recentCounter.ping(3001);  // requests = [1, 100, 3001], valid range is [1, 3001] -> returns 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], valid range is [2, 3002] -> returns 3
```

---

## Approach Overview

### Key Idea

The solution uses a **queue** to keep track of the timestamps of the incoming pings. Since the problem guarantees that each new ping time is strictly larger than the previous one, the queue will always be ordered from oldest to newest.

### Step-by-Step Process

1. **Enqueue the New Request:**

   - When `ping(t)` is called, add the new timestamp `t` to the queue.

2. **Remove Outdated Requests:**

   - Check the timestamp at the front of the queue.
   - Remove timestamps (using `pop()`) that are less than `t - 3000`, as they fall outside the valid window `[t - 3000, t]`.

3. **Return the Count:**
   - The size of the queue after removals gives the number of pings within the last 3000 milliseconds.

### Example Walkthrough

Consider the following sequence of pings: `1`, `100`, `3001`, `3002`.

- **Ping(1):**

  - **Queue before:** `[]`
  - **Action:** Add `1`.
  - **Queue after:** `[1]`
  - **Valid range:** `[-2999, 1]` → Count: `1`.

- **Ping(100):**

  - **Queue before:** `[1]`
  - **Action:** Add `100`.
  - **Queue after:** `[1, 100]`
  - **Valid range:** `[-2900, 100]` → Count: `2`.

- **Ping(3001):**

  - **Queue before:** `[1, 100]`
  - **Action:** Add `3001`.
  - **Queue after:** `[1, 100, 3001]`
  - **Valid range:** `[1, 3001]` (since `1 >= 3001 - 3000`) → Count: `3`.

- **Ping(3002):**
  - **Queue before:** `[1, 100, 3001]`
  - **Action:** Add `3002`.
  - **Queue after:** `[1, 100, 3001, 3002]`
  - **Cleanup:** Remove `1` because `1 < 3002 - 3000` (i.e., `1 < 2`).
  - **Final Queue:** `[100, 3001, 3002]` → Count: `3`.

### Why Use a Queue?

- **FIFO Order:** The queue naturally maintains the order of pings, ensuring that the oldest is always at the front.
- **Efficient Operations:** Adding to the back (`push()`) and removing from the front (`pop()`) are both efficient operations.
- **Natural Expiry:** Since pings are processed in order, removing outdated ones is straightforward.

---

## Time and Space Complexity

- **Time Complexity:**

  - Each call to `ping` involves enqueuing a new timestamp and possibly dequeuing outdated timestamps. Since each timestamp is enqueued once and dequeued once, the amortized time complexity per `ping` is O(1).

- **Space Complexity:**
  - The space required is proportional to the number of timestamps stored at any time, which is O(W), where W is the maximum number of requests in any 3000-millisecond window.

---

## Code Implementation

```cpp
#include <queue>

class RecentCounter {
private:
    std::queue<int> q;  // Instance-specific queue to store timestamps

public:
    RecentCounter() {
        // The queue starts empty.
    }

    int ping(int t) {
        // Add the new ping timestamp
        q.push(t);

        // Remove timestamps outside the valid window [t - 3000, t]
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        // Return the count of valid timestamps
        return q.size();
    }
};
```

---

## Testing the Implementation

### Example Test Case

```cpp
RecentCounter* obj = new RecentCounter();
BOOST_CHECK_EQUAL(obj->ping(1), 1);    // Queue: [1]
BOOST_CHECK_EQUAL(obj->ping(100), 2);  // Queue: [1, 100]
BOOST_CHECK_EQUAL(obj->ping(3001), 3); // Queue: [1, 100, 3001]
BOOST_CHECK_EQUAL(obj->ping(3002), 3); // Queue: [100, 3001, 3002]
delete obj;
```

### Additional Test Case

```cpp
RecentCounter* obj2 = new RecentCounter();
BOOST_CHECK_EQUAL(obj2->ping(100), 1);    // Queue: [100]
BOOST_CHECK_EQUAL(obj2->ping(3100), 2);   // Queue: [100, 3100]
BOOST_CHECK_EQUAL(obj2->ping(3200), 2);   // Queue: [3100, 3200] (100 is removed)
BOOST_CHECK_EQUAL(obj2->ping(4000), 3);   // Queue: [3100, 3200, 4000]
BOOST_CHECK_EQUAL(obj2->ping(5000), 4);   // Queue: [3100, 3200, 4000, 5000]
delete obj2;
```

---

## Conclusion

The queue-based approach for the **Number of Recent Calls** problem is both intuitive and efficient. By leveraging the FIFO properties of a queue, we can:

- Easily add new timestamps.
- Remove outdated ones.
- Keep track of the current number of valid pings with minimal overhead.

This approach satisfies the problem requirements and meets the constraints for both time and space complexity.

---
