# Approach: Equal Row and Column Pairs

## Problem Recap

Given an n×n grid of integers, we need to count the number of pairs (ri, cj) such that the i-th row and j-th column are equal—that is, they contain the same elements in the same order.

**Example 1:**

- **Input:** `grid = [[3,2,1],[1,7,6],[2,7,7]]`
- **Output:** `1`
- **Explanation:** Only the 3rd row and the 2nd column match: `[2,7,7]`.

**Example 2:**

- **Input:** `grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]`
- **Output:** `3`
- **Explanation:** Three matching pairs exist:
  - (Row 0, Column 0): `[3,1,2,2]`
  - (Row 2, Column 2): `[2,4,2,2]`
  - (Row 3, Column 2): `[2,4,2,2]`

## High-Level Strategy

1. **Separate Processing of Rows and Columns:**

   - **Rows:** Count how many times each unique row appears.
   - **Columns:** Build each column vector and count how many times each unique column appears.

2. **Use Frequency Maps with Vectors as Keys:**

   - We need to compare entire rows/columns. We use `std::unordered_map` where keys are `std::vector<int>` and values are their frequencies.
   - Since C++ does not have a default hash for `std::vector<int>`, we create an inline lambda hash function within our function.

3. **Count Matching Pairs:**
   - For every unique row vector, if the same vector appears in the column frequency map, the number of matching pairs contributed by that vector is the product of its frequency in rows and columns.
   - Sum these products to get the total number of pairs.

## Detailed Steps

### 1. Custom Inline Hash Function

We define an inline lambda `vectorHash` that computes a hash value for a vector of integers:

- It initializes a seed with the vector’s size.
- It then iterates over each integer in the vector, combining its hash value into the seed using bitwise operations.

This lambda is used as the hash function for our unordered maps.

### 2. Build Frequency Maps for Rows and Columns

- **Row Frequency Map (`rowFreq`):**
  - For each row in the grid, increment its count in the map.
- **Column Frequency Map (`colFreq`):**
  - For each column index, construct a vector by taking the element at that column from every row.
  - Increment the count for that column vector in the map.

### 3. Count the Matching Pairs

- Iterate over each entry in the row frequency map.
- For every row vector that exists in the column frequency map, add `rowFreq * colFreq` to the total pairs.
- Return the total count.

## Complexity Analysis

- **Time Complexity:**
  - Building both frequency maps takes O(n²) since each row or column has n elements and there are n rows/columns.
  - Counting matching pairs iterates over the distinct row/column vectors, which in the worst-case scenario is O(n²) but is typically much less.
- **Space Complexity:**
  - The frequency maps store at most O(n) distinct vectors (if all rows are unique), and each vector has n elements, leading to O(n²) space in the worst case.

## Conclusion

This approach efficiently counts matching row and column pairs by:

- Separately building frequency maps for rows and columns,
- Using a custom inline lambda hash function to allow `std::vector<int>` as a key in unordered maps,
- Summing up the product of frequencies for each matching vector.

This solution meets the problem requirements and handles grids up to size 200×200 efficiently.

---
