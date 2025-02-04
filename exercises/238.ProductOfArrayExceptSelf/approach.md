### **Approach to Solve "Product of Array Except Self" (Leetcode 238)**

The goal is to return an array where each element is the **product of all elements except itself**, without using division, and in **O(n) time complexity**.

---

### **1️ Understand the Constraints**

- **No division allowed**.
- **Must run in O(n) time**.
- **Handles zero values correctly**.
- **Input size: 2 ≤ nums.length ≤ 10⁵**.

---

### **2️ Key Observations**

1. **Each element at `i` should be the product of all elements except `nums[i]`**.
2. We can **calculate the product of all elements to the left and right of each element** without needing division.
3. Use **two passes**:
   - **Left pass**: Compute **prefix products** (products before `i`).
   - **Right pass**: Compute **suffix products** (products after `i`).

---

### **3️ Two-Pass Solution (Without Extra Space)**

1. **Create a result array initialized with 1**.
2. **First pass (left product):**
   - Compute the **cumulative product from the left**.
   - Store it in the result array.
3. **Second pass (right product):**
   - Compute the **cumulative product from the right**.
   - Multiply it with the existing value in the result array.

This maintains **O(n) complexity** using **O(1) extra space** (excluding the output array).

---

### **4️ Dry Run Example**

For `nums = [1, 2, 3, 4]`:

#### **Left Pass (Prefix Products)**

| Index | `nums[i]` | Left Product (`result[i]`) |
| ----- | --------- | -------------------------- |
| 0     | 1         | `1` (always 1)             |
| 1     | 2         | `1 × 1 = 1`                |
| 2     | 3         | `1 × 2 = 2`                |
| 3     | 4         | `2 × 3 = 6`                |

**After Left Pass: `[1, 1, 2, 6]`**

#### **Right Pass (Multiplying with Suffix Products)**

| Index | `nums[i]` | Right Product (`result[i] *= right`) |
| ----- | --------- | ------------------------------------ |
| 3     | 4         | `6 × 1 = 6`                          |
| 2     | 3         | `2 × 4 = 8`                          |
| 1     | 2         | `1 × 12 = 12`                        |
| 0     | 1         | `1 × 24 = 24`                        |

**Final Result: `[24, 12, 8, 6]`**

---

### **5️ Final Algorithm (Pseudocode)**

```cpp
1. Initialize `result` array with size `n`, filled with 1.
2. Compute **left product** pass:
   - Iterate `i` from 0 to n-1.
   - Store prefix product in `result[i]`.
3. Compute **right product** pass:
   - Iterate `i` from n-1 to 0.
   - Multiply `result[i]` by suffix product.
4. Return `result`.
```

---

### **6️ Complexity Analysis**

| **Operation**        | **Time Complexity** | **Space Complexity**         |
| -------------------- | ------------------- | ---------------------------- |
| Left pass            | **O(n)**            | **O(1)** (output array only) |
| Right pass           | **O(n)**            | **O(1)**                     |
| **Total Complexity** | **O(n)**            | **O(1)**                     |

---

### **Summary**

- **Use left and right product passes** to avoid division.
- **Keep it O(n) with O(1) extra space**.
- **Two passes (left + right) are sufficient**.
