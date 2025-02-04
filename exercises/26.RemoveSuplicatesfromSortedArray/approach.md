# Approach Explanation: Removing Duplicates from a Sorted Array

## Overview

The problem is to remove duplicate elements from a sorted array in-place such that each unique element appears only once. The relative order of the elements must be maintained, and the solution should use O(1) extra memory. Since the array is sorted in non-decreasing order, any duplicates will be adjacent, which simplifies the task.

## Key Observations

- **Sorted Array**: Since the array is sorted, all duplicate values are contiguous.
- **Two-Pointer Technique**: We can use two pointers to efficiently traverse and modify the array in-place.
  - One pointer (`i`) tracks the index of the last unique element.
  - The other pointer (`j`) iterates through the array to find the next unique element.

## Detailed Steps

1. **Edge Case Check**:

   - If the array is empty, return `0` immediately since there are no elements to process.

2. **Initialize Pointers**:

   - Set `i = 0` as the index for the current unique element.
   - Set `j = 1` as the index to explore the rest of the array.

3. **Traverse the Array**:

   - Loop while `j` is less than the size of the array.
   - **Duplicate Check**:
     - If `nums[j]` is equal to `nums[i]`, then it is a duplicate and we simply move `j` to the next index.
   - **Unique Element Found**:
     - If `nums[j]` is not equal to `nums[i]`, increment `i` to prepare for placing the new unique element.
     - Copy `nums[j]` to `nums[i]` so that the new unique element is stored next to the previous unique ones.
     - Move `j` forward to continue checking the rest of the array.

4. **Return the Result**:
   - After the loop finishes, `i + 1` represents the total number of unique elements in the array.
   - The first `i + 1` elements of the array now contain the unique elements in their original order.

## Complexity Analysis

- **Time Complexity:**  
  \(O(n)\), where \(n\) is the number of elements in the array.  
  Each element is examined exactly once.

- **Space Complexity:**  
  \(O(1)\) extra space, as the modifications are made in-place without using additional data structures.

## Additional Helper Functions

- **`printVector` Function:**  
  This function iterates through the vector and prints each element. It is useful for debugging or verifying the contents of the vector after modifications.

- **`removeOneItem` Function:**  
  This function demonstrates how to remove an element from the vector (specifically, it erases the element at the second position). While not directly related to the duplicate removal algorithm, it shows an example of in-place modification of a vector.

## Summary

The two-pointer approach used in the `removeDuplicates` function efficiently handles the removal of duplicates from a sorted array by leveraging the sorted order to group duplicates together. This method maintains the original order of unique elements, works in linear time, and uses constant extra space, making it an optimal solution for the problem.
