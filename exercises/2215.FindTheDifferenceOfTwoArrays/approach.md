# Approach: Using Unordered Sets

**Goal:**  
Find the distinct elements in `nums1` not in `nums2` and the distinct elements in `nums2` not in `nums1`.

---

## Key Idea

1. Convert each input array into an **unordered set** to eliminate duplicates and achieve **O(1)** average lookup.
2. Iterate through `set1` to find which elements are **not** present in `set2`.
3. Iterate through `set2` to find which elements are **not** present in `set1`.
4. Collect these elements into two separate vectors and return as a 2D vector.

---

## Pseudocode

```plaintext
function findDifference(nums1, nums2):
    set1 ← new unordered_set from nums1
    set2 ← new unordered_set from nums2

    distinct1 ← new list
    for val in set1:
        if val not in set2:
            distinct1.push_back(val)

    distinct2 ← new list
    for val in set2:
        if val not in set1:
            distinct2.push_back(val)

    return [distinct1, distinct2]
```

---

## Complexity Analysis

- **Building the Sets:** O(n + m) average time, where:
  - **n** = size of `nums1`
  - **m** = size of `nums2`
- **Finding Differences:** O(n + m) in total since each element is checked once against the other set.
- Overall Time Complexity: **O(n + m)**.
- Space Complexity:
  - O(n + m) for storing unique elements from both arrays into sets.
  - O(k) additional space for the output vectors (where **k** ≤ n + m).

---

## Why This is Better

- **No Nested Loops:**  
  The naive approach checks each element of `nums1` against all of `nums2`, leading to O(n \* m) in the worst case. Here, set lookups are O(1) on average, eliminating nested loops.
- **Handles Duplicates Gracefully:**  
  Unordered sets automatically discard duplicate elements, aligning well with the requirement to return distinct values only once.

---

## Final Note

- If a **sorted** output is required, you can simply **sort** the resulting `distinct1` and `distinct2` before returning.
- For guaranteed O(1) average lookups, `std::unordered_set` is ideal. If consistent ordering of elements is needed (e.g., sorted order by default), consider `std::set` (which offers O(log n) lookups).

---
