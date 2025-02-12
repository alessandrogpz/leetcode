# Removing Stars From a String: Two Approaches

## Problem Description

You are given a string `s` containing lowercase English letters and stars (`*`). In one operation, you can:

- Choose a star in `s`.
- Remove the closest non-star character to its left, as well as remove the star itself.

The operations are performed repeatedly until no stars remain. It is guaranteed that the operation is always possible and that the resulting string is unique.

**Example 1:**

- **Input:** `"leet**cod*e"`
- **Output:** `"lecoe"`

  _Explanation:_

  - The first star removes the `'t'` from `"leet**cod*e"` → `"lee*cod*e"`.
  - The second star removes the `'e'` → `"lecod*e"`.
  - The third star removes the `'d'` → `"lecoe"`.

**Example 2:**

- **Input:** `"erase*****"`
- **Output:** `""` (the entire string is removed)

---

## Approach 1: `removeStars_1`

This approach uses a two-phase method:

1. **Build a Stack (Right-to-Left):**  
   Iterate through the string from right to left and push every character onto a stack.
2. **Process the Stack:**  
   Pop characters from the stack to build the resulting string. When encountering a star (`*`), remove the last character from the result string (if available) and discard the star.

### Code

```cpp
std::string Solution::removeStars_1(std::string s)
{
    std::string updatedStr = "";
    std::stack<char> s_stack = {};
    int n_stars = 0;

    // Phase 1: Push all characters from s (right-to-left) into the stack.
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == '*')
        {
            n_stars++;  // (This counter is maintained but not used later)
        }
        s_stack.push(s[i]);
    }

    // Phase 2: Process the stack to build the final string.
    while (!s_stack.empty())
    {
        if (s_stack.top() != '*')
        {
            updatedStr.push_back(s_stack.top());
            s_stack.pop();
        }
        else if (!s_stack.empty() && s_stack.top() == '*')
        {
            // If there is a star, remove the last character from updatedStr (if any)
            if (!updatedStr.empty())
            {
                int RemoveAt = updatedStr.size() - 1;
                updatedStr.erase(RemoveAt, 1);
            }
            s_stack.pop();
        }
    }
    return updatedStr;
}
```

### Explanation

- **Stack Building (Right-to-Left):**  
  By iterating from the end of the string, each character (including stars) is pushed onto a stack. This reverses the order.
- **Processing the Stack:**  
  As the stack is processed from top to bottom, non-star characters are added to the result. When a star is encountered, the algorithm removes the last character from the result string (simulating the removal of the closest non-star character to the left of that star).

### Performance Discussion

- **Time Complexity:**  
  The algorithm makes two passes over the data (one for building the stack and one for processing it), so its overall time complexity is O(n).
- **Space Complexity:**  
  A stack is used to hold all characters, which requires O(n) extra space.
- **Note:**  
  The extra variable `n_stars` is unnecessary for the final result, so it could be removed for clarity.

---

## Approach 2: `removeStars_2`

This approach uses a more direct method by processing the string in a single left-to-right pass. It simulates the behavior of a stack using an actual stack container. After processing, it rebuilds the string from the stack and reverses it to obtain the final result.

### Code

```cpp
std::string Solution::removeStars_2(std::string s)
{
    std::stack<char> st;

    // Process each character in the string
    for (char &el : s)
    {
        if (el == '*')
        {
            // When a star is found, pop the last character (if the stack is not empty)
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            // Otherwise, push the character onto the stack
            st.push(el);
        }
    }

    // Clear the original string
    s.erase(s.begin(), s.end());

    // Reconstruct the string from the stack (this will be in reverse order)
    while (!st.empty())
    {
        s += st.top();
        st.pop();
    }

    // Reverse the string to obtain the correct order
    std::reverse(s.begin(), s.end());
    return s;
}
```

### Explanation

- **Left-to-Right Processing:**  
  The function iterates over each character in the string. If the character is not a star, it is pushed onto the stack. If it is a star, the most recent character (the top of the stack) is popped.
- **Reconstruction:**  
  After processing, the string is cleared and rebuilt by appending the elements of the stack (which will be in reverse order). A final reverse operation yields the correct result.

### Performance Discussion

- **Time Complexity:**  
  The algorithm processes each character exactly once in O(n) time, with additional O(n) time to reverse the string at the end.
- **Space Complexity:**  
  The use of the stack requires O(n) extra space.
- **Advantages:**  
  This approach is more intuitive, performing the removal operation as it scans through the string without requiring an explicit reverse traversal to build the stack.

---

## Comparison and Conclusion

Both approaches have a time complexity of O(n) and a space complexity of O(n). However, **Approach 2** is generally preferable because:

- It processes the string in a single left-to-right pass.
- It avoids the extra pass and reverse-order handling found in **Approach 1**.
- The code is simpler and more direct, which helps with maintainability.

---
