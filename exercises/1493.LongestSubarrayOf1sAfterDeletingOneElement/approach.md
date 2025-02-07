# Approach for "Longest Subarray of 1's After Deleting One Element"

## Problem Summary

We are given a binary array `nums`, and we want to delete **one** element (either `0` or `1`). After this single deletion, we need to determine the length of the longest contiguous subarray consisting of only `1`s. If no such subarray exists, we should return `0`.

**Key points:**

1. We are allowed exactly one deletion from the entire array.
2. We aim for the longest contiguous sequence of `1`s post-deletion.

### Example

- **Input:** `[1,1,0,1]`
  - By deleting the `0` (element at index 2), we get `[1,1,1]`.
  - The length of this subarray is `3`, which is the answer.

---

## Explanation of the Two-Pointer / Sliding Window Approach

### Idea

1. **Maintain a Sliding Window** using two indices (`left` and `right`).
2. **Track how many zeroes** are currently in this window. We use a variable `spareElement`, which starts at `1`, indicating we can "afford" to have one zero in the window (representing the eventual deletion).
3. As we move `right` through the array:
   - If we encounter a zero, we decrease `spareElement`.
   - If `spareElement` becomes negative, it means we have **more than one** zero in the current window. We must shrink the window from the `left` until we have only one zero in the window again. This step effectively simulates having used up our single "delete" on one zero and needing to exclude additional zeroes from the window.
4. At each step, the **window length** (`right - left + 1`) represents the size of a subarray that can contain at most one zero (i.e., at most one deletion needed). We track the maximum window size found.
5. Finally, since the problem requires us to **delete exactly one element**, the result is `maxWindow - 1`.

### Pseudocode

```
Initialize left = 0, right = 0
Initialize spareElement = 1 (we can afford one zero)
Initialize maxCount = 0

For right in [0..nums.size() - 1]:
    If nums[right] == 0:
        spareElement -= 1

    While spareElement < 0:
        If nums[left] == 0:
            spareElement += 1
        left += 1

    maxCount = max(maxCount, right - left + 1)

Return maxCount - 1
```

**Why `maxCount - 1`?**

- Our window includes at most one zero, effectively the subarray if we “virtually” deleted one zero. But if the subarray is all ones, we still need to delete exactly one element (potentially a `1`). Therefore, we always subtract 1 from the window size.

### Complexity

- **Time Complexity:** O(n). We traverse the array once with a sliding window, each element is visited at most twice (once when `right` moves and possibly once when `left` moves).
- **Space Complexity:** O(1). We only keep a few pointers/counters.

### Edge Cases

1. **All 1s:**
   - For example, `nums = [1,1,1]`.
   - Our algorithm might find the window size = 3, but we must delete one, so final answer = 2.
2. **All 0s:**
   - For example, `nums = [0,0,0]`.
   - You still must delete one element. However, there are no 1s to begin with, so the final answer becomes `0`.
3. **Single Element:**
   - If `nums = [1]`, after deleting that single `1`, there’s no subarray of 1s left. The result is `0`.
   - If `nums = [0]`, we still have no 1s, so result is `0`.
4. **Mix of 0s and 1s** with multiple 0s in a row. The sliding window logic ensures we continuously shrink the window whenever the “spareElement” is used up.

---

## Final Notes

- Always remember to **subtract 1** from the maximum window size you find, because of the requirement to delete exactly one element.
- If the maximum window size is less than 1 (e.g., in an all-zero scenario), the result logically becomes `0`.

This approach ensures we only iterate through the array once, achieving O(n) time complexity, which is optimal for handling arrays up to `10^5` elements.

---
