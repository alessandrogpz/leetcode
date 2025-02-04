# Approach for "Maximum Number of Vowels in a Substring of Given Length"

## Problem Recap

Given a string `s` and an integer `k`, the goal is to find the maximum number of vowels in any substring of `s` with length `k`. The vowels are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

### Examples

- **Example 1:**  
  **Input:** `s = "abciiidef"`, `k = 3`  
  **Output:** `3`  
  **Explanation:** The substring `"iii"` contains 3 vowels.

- **Example 2:**  
  **Input:** `s = "aeiou"`, `k = 2`  
  **Output:** `2`  
  **Explanation:** Any substring of length 2 contains 2 vowels.

- **Example 3:**  
  **Input:** `s = "leetcode"`, `k = 3`  
  **Output:** `2`  
  **Explanation:** Substrings such as `"lee"`, `"eet"`, and `"ode"` each have 2 vowels.

---

## Approach Overview

To solve this problem efficiently, we use the **sliding window technique**. This method allows us to traverse the string in a single pass (after processing the first window) and update the count of vowels as we move the window from left to right.

### Step-by-Step Process

1. **Initialize the Vowels Set:**  
   Use an `unordered_set<char>` to store the vowels for O(1) lookup time.

   ```cpp
   std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
   ```

2. **Count Vowels in the Initial Window:**  
   Traverse the first `k` characters of the string and count how many vowels there are.

   ```cpp
   int current_count = 0;
   for (int i = 0; i < k; i++) {
       if (vowels.find(s[i]) != vowels.end()) {
           current_count++;
       }
   }
   ```

   Store this count as the current maximum (`max_count`).

3. **Slide the Window Through the String:**  
   Starting from the `k`-th character, slide the window one position at a time:

   - **Add the New Character:**  
     If the new character entering the window is a vowel, increment the current count.
   - **Remove the Exiting Character:**  
     If the character leaving the window is a vowel, decrement the current count.
   - **Update the Maximum Count:**  
     After each slide, update the maximum count of vowels found.

   ```cpp
   for (int i = k; i < s.size(); i++) {
       if (vowels.find(s[i]) != vowels.end()) {
           current_count++;
       }
       if (vowels.find(s[i - k]) != vowels.end()) {
           current_count--;
       }
       max_count = std::max(max_count, current_count);
   }
   ```

4. **Return the Result:**  
   After processing all windows, return the maximum vowel count.

---

## Complexity Analysis

- **Time Complexity:** O(n)

  - The initial window is processed in O(k) time.
  - The sliding window traverses the rest of the string in O(n - k) time.
  - Overall, the function runs in linear time relative to the length of the string.

- **Space Complexity:** O(1)
  - The extra space is constant because the vowels set contains only 5 elements.

---
