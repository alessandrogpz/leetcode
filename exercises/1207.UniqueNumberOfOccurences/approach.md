# Approach: Ensuring Unique Occurrences of Each Element

---

## 1) **Method 1**: Nested Loop Counting (`uniqueOccurrences_1`)

**Idea:**

1. Collect all **distinct** elements in a set (`uniqueNum`).
2. For each distinct element, **iterate** over `arr` to count how many times it appears.
3. Use another set (`freqNum`) to track each occurrence count. If a count repeats, return `false`.

### **Steps**

1. **Extract Distinct Elements**
   ```cpp
   std::unordered_set<int> uniqueNum = {arr.begin(), arr.end()};
   ```
2. **Nested Loops**
   - Outer loop: Iterate over each distinct element in `uniqueNum`.
   - Inner loop: Count its occurrences in `arr`.
3. **Check for Duplicate Counts**
   - Use `freqNum` to store the counts we have already seen.
   - If we find a count already in `freqNum`, return `false`. Otherwise, insert it.

### **Complexity Analysis**

- **Time Complexity**:

  - Let \(k\) be the number of unique elements, and \(n\) be the size of `arr`.
  - For each unique element, we count occurrences by iterating through `arr`, taking **O(k \* n)** time.
  - Worst-case scenario (all elements are distinct): \(k = n\) → **O(n²)**.

- **Space Complexity**:
  - **O(k)** for the set of unique elements.
  - **O(k)** for the set of frequencies.
  - Overall **O(k)**, which is **O(n)** in the worst case.

---

## 2) **Method 2**: Frequency Map + Frequency Set (`uniqueOccurrences_2`)

**Idea:**

1. Build a **frequency map** (`std::unordered_map<int,int>`) that records how many times each value appears in `arr`.
2. Store all occurrence counts into a **frequency set** to ensure each count is **unique**.

### **Steps**

1. **Build Frequency Map** (One Pass)
   ```cpp
   std::unordered_map<int, int> freq;
   for (int val : arr) {
       freq[val]++;
   }
   ```
2. **Check for Duplicate Frequencies** (One Pass over `freq`)
   ```cpp
   std::unordered_set<int> seen;
   for (auto &p : freq) {
       int count = p.second;
       if (seen.find(count) != seen.end()) {
           return false; // Duplicate occurrence count
       }
       seen.insert(count);
   }
   ```
3. **Return True if All Counts are Unique**

### **Complexity Analysis**

- **Time Complexity**:

  - **O(n)** to build the `freq` map.
  - **O(k)** to check frequencies, where \(k\) is the number of distinct elements.
  - Overall **O(n + k)**, which is effectively **O(n)** because \(k \leq n\).

- **Space Complexity**:
  - **O(k)** for the frequency map.
  - **O(k)** for the frequency set.
  - Overall **O(k)**, again **O(n)** in the worst case.

---

## **Comparison**

1. **Method 1**:
   - **Simpler** to implement directly but runs in **O(n²)** in the worst case.
2. **Method 2**:
   - **More Efficient**; runs in **O(n)** time.
   - Slightly more code to handle map+set logic, but scales better.

---

## **Conclusion**

- If **performance** is critical (especially for large `arr`), use the **Frequency Map + Frequency Set** approach (`uniqueOccurrences_2`).
- For **small** inputs, or if simplicity is favored, the **Nested Loop** method (`uniqueOccurrences_1`) is acceptable, though less optimal for large arrays.
