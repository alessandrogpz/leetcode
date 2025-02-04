# Approach Document for "Max Number of K-Sum Pairs"

This document explains the solution for the problem of finding the maximum number of operations (i.e., valid pairs) in an array such that the sum of each pair equals a given integer `k`.

---

## Problem Recap

Given an integer array `nums` and an integer `k`, the task is to perform operations where, in each operation, you remove two numbers from the array whose sum is exactly `k`. The goal is to return the maximum number of such operations.

### Example 1

- **Input:** `nums = [1,2,3,4]`, `k = 5`
- **Output:** `2`
- **Explanation:**
  - Remove `1` and `4` (1 + 4 = 5) → `nums = [2,3]`
  - Remove `2` and `3` (2 + 3 = 5) → `nums = []`

### Example 2

- **Input:** `nums = [3,1,3,4,3]`, `k = 6`
- **Output:** `1`
- **Explanation:**
  - Remove two `3`s (3 + 3 = 6) → `nums = [1,4,3]`
  - No more pairs sum to `6`

---

## Approach

The solution uses a two-pointer technique after sorting the array to efficiently find pairs that sum to `k`.

### 1. Sorting the Array

- **Purpose:** Sorting the array ensures that the numbers are in increasing order. This ordering allows us to use two pointers (one starting at the beginning and one at the end) to effectively locate pairs with the desired sum.
- **Time Complexity:** Sorting takes _O(n log n)_.

### 2. Two-Pointer Technique

- **Initialization:**
  - `left` pointer at the start of the array (index 0).
  - `right` pointer at the end of the array (index `nums.size() - 1`).
- **Procedure:**
  - **While** `left < right`:
    1. Calculate `sum = nums[left] + nums[right]`.
    2. **If** `sum == k`:
       - A valid pair is found.
       - Increment the count of operations.
       - Move both pointers inward (`left++` and `right--`).
    3. **Else if** `sum < k`:
       - The current pair is too small.
       - Move the `left` pointer rightward to increase the sum.
    4. **Else (i.e., `sum > k`)**:
       - The current pair is too large.
       - Move the `right` pointer leftward to decrease the sum.

### 3. Termination

- The loop terminates when the `left` pointer is no longer less than the `right` pointer.
- The final value of `count` represents the maximum number of valid pairs.

---

## Complexity Analysis

- **Time Complexity:**
  - Sorting the array: _O(n log n)_
  - Two-pointer traversal: _O(n)_
  - **Overall:** _O(n log n)_ (dominated by the sorting step)
- **Space Complexity:**
  - Sorting is performed in-place.
  - **Overall:** _O(1)_ additional space (ignoring the input storage)

---

## Key Insights

- **Sorting Enables Efficient Pairing:** By sorting the array, the smallest and largest elements can be paired and the decision to move pointers is straightforward.
- **Two-Pointer Technique:** This method allows scanning the array in a single pass after sorting, ensuring each element is considered only once.
- **Efficient Pair Removal:** Instead of modifying the array, moving the pointers simulates the removal of pairs, making the algorithm both time and space efficient.

---
