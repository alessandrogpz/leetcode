Below is a concise explanation of the **two-sum approach** for finding the pivot index. Feel free to include or modify this content in your `approach.md` document.

---

## **Approach Explanation**

The goal is to find an index `i` in the array `nums` such that the sum of all elements to the left of `i` equals the sum of all elements to the right of `i`.

1. **Compute the total sum of the array**

   - Let `totalSum` be the sum of all elements in `nums`.
   - This gives us the sum of the entire array in a single pass, O(n).

2. **Iterate through the array and maintain a running `leftSum`**

   - Initialize `leftSum = 0`.
   - As you move through each index `i`, think of `leftSum` as the sum of elements strictly to the left of `i`.

3. **Determine the right sum on the fly**

   - The sum of elements strictly to the right of `i` can be computed as:  
     \[
     \text{rightSum} = \text{totalSum} - \text{leftSum} - \text{nums}[i]
     \]
   - This works because we remove both the left side (already in `leftSum`) and the current element `nums[i]` from the total.

4. **Check for the pivot condition**

   - If `leftSum == rightSum`, index `i` is a pivot index. Return `i`.

5. **Update `leftSum` for the next index**

   - After the check, add `nums[i]` to `leftSum` and continue to the next index.

6. **If no pivot index is found**, return `-1`.

### **Why This Works**

- By computing `totalSum` initially, we have a quick way to know what the right side should sum to if the left side is known.
- At index `i`, the left sum is everything before `i`, and the right sum is everything after `i`. Checking `leftSum == rightSum` effectively enforces the pivot index definition.
- This approach ensures we only traverse the array **once** for `totalSum` and **once** more to find the pivot index—resulting in **O(n)** time complexity and **O(1)** extra space.

### **Example**

- **Array:** `[1, 7, 3, 6, 5, 6]`
- `totalSum = 1 + 7 + 3 + 6 + 5 + 6 = 28`
- Start iterating:
  1. `i = 0`, `leftSum = 0`
     - `rightSum = 28 - 0 - nums[0] = 28 - 1 = 27`
     - `leftSum != rightSum`, so move on.
     - `leftSum += 1 (nums[0])` → `leftSum = 1`
  2. `i = 1`, `leftSum = 1`
     - `rightSum = 28 - 1 - 7 = 20`
     - Not equal, move on. `leftSum += 7 → 8`
  3. `i = 2`, `leftSum = 8`
     - `rightSum = 28 - 8 - 3 = 17`
     - Not equal, `leftSum += 3 → 11`
  4. `i = 3`, `leftSum = 11`
     - `rightSum = 28 - 11 - 6 = 11`
     - **Equal!** Return `i = 3`.

---
