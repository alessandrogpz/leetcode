# Approach for "1004. Max Consecutive Ones III"

## Problem Recap

Given a binary array `nums` and an integer `k`, the goal is to return the maximum number of consecutive 1's in the array if you can flip at most `k` 0's to 1's.

**Example 1:**
- **Input:** `nums = [1,1,1,0,0,0,1,1,1,1,0]`, `k = 2`
- **Output:** `6`
- **Explanation:** By flipping at most 2 zeros, the longest subarray of consecutive 1's becomes `[1,1,1,0,0,1,1,1,1,1,1]` (with the underlined portion being the maximum).

**Example 2:**
- **Input:** `nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]`, `k = 3`
- **Output:** `10`
- **Explanation:** Flipping at most 3 zeros produces a longest subarray of consecutive 1's of length 10.

**Constraints:**
- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`
- `0 <= k <= nums.length`

---

## Approach Overview

The problem can be efficiently solved using a **sliding window** (or two-pointer) technique. The key idea is to maintain a window `[left, right]` that represents a subarray of `nums` containing at most `k` zeros (i.e., zeros that can be flipped).

### Steps in the Sliding Window Approach:
1. **Expand the Window:**  
   As you iterate over the array with the right pointer, count the number of zeros in the current window.  
   - If the current element is `0`, increment the `zeros` count.

2. **Shrink the Window:**  
   If the number of zeros exceeds `k`, move the left pointer to the right until the window contains at most `k` zeros.  
   - While shrinking, if the element being removed (at the left pointer) is a `0`, decrement the `zeros` count.

3. **Update the Maximum Length:**  
   At each iteration, the size of the current window (given by `right - left + 1`) is a candidate for the longest subarray with at most `k` flipped zeros. Keep track of the maximum window size encountered.

---

## Code Implementation

Below is the implementation of the solution in C++:

```cpp
#include "functions.h"
#include <vector>
#include <algorithm>

int Solution::longestOnes(std::vector<int>& nums, int k) {
    int left = 0, zeros = 0, maxLength = 0;
    for (int right = 0; right < nums.size(); right++) {
        // If the current element is 0, increment the zeros counter.
        if (nums[right] == 0) {
            zeros++;
        }
        
        // If the zeros count exceeds k, shrink the window from the left.
        while (zeros > k) {
            if (nums[left] == 0) {
                zeros--;
            }
            left++;
        }
        
        // Update the maximum length of the window found so far.
        maxLength = std::max(maxLength, right - left + 1);
    }
    return maxLength;
}
```

---

## Complexity Analysis

- **Time Complexity:** O(n)  
  The algorithm makes a single pass through the array with the `right` pointer, and the `left` pointer only moves forward. Each element is processed at most twice (once by `right` and once by `left`), resulting in linear time.

- **Space Complexity:** O(1)  
  Only a few integer variables are used for tracking the window boundaries and counts, regardless of the input size.

---

## Conclusion

This sliding window approach efficiently computes the maximum number of consecutive 1's possible after flipping at most `k` zeros. By dynamically adjusting the window boundaries based on the count of zeros, the algorithm ensures an optimal O(n) solution suitable for large input sizes.