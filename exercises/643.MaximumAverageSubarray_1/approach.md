Below is a concise description of the **sliding window** approach used in your `findMaxAverage` function. You can include this in your `approach.md` document.

---

# Approach

The problem requires finding the **maximum average** of a contiguous subarray of length \( k \) within an integer array `nums`. Here’s how the sliding window approach works:

1. **Initialize the window**

   - First, compute the average of the **first \( k \) elements**. This sum (or average) will serve as both your current window’s average and the initial `maxAverage`.

2. **Slide the window across the array**

   - For each position \( j \) starting from \( k \) to the end of the array:
     - **Remove** the contribution of the element leaving the window: `nums[j - k]`
     - **Add** the contribution of the new element: `nums[j]`
     - Update the current average by:
       \[
       \text{curMaxAvg} \;+=\; \frac{ \text{nums}[j] \;-\; \text{nums}[j - k] }{ k }
       \]
   - Compare and update `maxAverage` if the new average is higher.

3. **Return the result**
   - After sliding through the entire array, `maxAverage` will hold the highest average among all subarrays of length \( k \).

### **Why This Works**

- **Fixed Window Size:** Since \( k \) is fixed, each subarray we consider has exactly \( k \) elements.
- **Efficient Updates:** Instead of recalculating the sum (or average) from scratch for each new subarray, we **remove** the contribution of the element that exits the window and **add** the element that enters, keeping the operation in **O(1)** time for each step.
- **Overall Time Complexity:** \( O(n) \), where \( n \) is the number of elements in `nums`. This is optimal, because any solution must at least look at each element once.
- **Space Complexity:** \( O(1) \), as we only store running sums/averages, and do not allocate extra data structures proportional to \( n \).

This approach ensures we efficiently keep track of the average as our window “slides” across the array, returning the maximum average subarray value in a single pass.
