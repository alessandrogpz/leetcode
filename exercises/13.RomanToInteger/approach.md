# Explanation of Approach

## Overview

The problem requires converting Roman numerals into their integer equivalents. Roman numerals have seven symbols:

| Symbol | Value |
| :----: | :---: |
|   I    |   1   |
|   V    |   5   |
|   X    |  10   |
|   L    |  50   |
|   C    |  100  |
|   D    |  500  |
|   M    | 1000  |

Usually, Roman numerals are written from largest to smallest from left to right. However, if a smaller value appears before a larger value, you subtract the smaller value from the larger one. This leads to special cases like `IV` (4), `IX` (9), `XL` (40), `XC` (90), `CD` (400), and `CM` (900).

---

## Approach 1: `romanToInt`

### Key Idea

- Traverse the string character by character.
- For each symbol, look ahead to the next symbol to handle special subtractive cases (like `IV`, `IX`, etc.).
- If you detect a subtractive pair, add the combined value to the sum and skip the next character.
- Otherwise, add the current symbol's value to the sum.

### Steps

1. Initialize `sum` to 0 and an index `i` to 0.
2. Loop through the string:
   - If `s[i]` is `I`:
     - Check if the next character is `V` or `X`.
       - If `V`, add `4` and increment `i` to skip the next character.
       - If `X`, add `9` and increment `i` to skip the next character.
       - Otherwise, add `1`.
   - If `s[i]` is `V`, add `5`.
   - If `s[i]` is `X`:
     - Check if the next character is `L` or `C`.
       - If `L`, add `40` and skip next character.
       - If `C`, add `90` and skip next character.
       - Otherwise, add `10`.
   - If `s[i]` is `L`, add `50`.
   - If `s[i]` is `C`:
     - Check if the next character is `D` or `M`.
       - If `D`, add `400` and skip next character.
       - If `M`, add `900` and skip next character.
       - Otherwise, add `100`.
   - If `s[i]` is `D`, add `500`.
   - If `s[i]` is `M`, add `1000`.
3. Continue until the end of the string.
4. Return `sum` as the result.

### Complexity

- **Time Complexity**: \(O(n)\), where \(n\) is the length of the Roman numeral string.
- **Space Complexity**: \(O(1)\), only a few variables are used regardless of input size.

---

## Approach 2: `romanToInt2`

### Key Idea

- Use a hash map (`unordered_map`) to associate each Roman character with its integer value.
- Traverse the string from left to right:
  - If the current symbol represents a value less than the next symbol’s value, this indicates a subtractive scenario. Subtract the current value from the total.
  - Otherwise, add the current value to the total.

### Steps

1. Create a map `mp` of Roman symbols to their integer values.
2. Initialize `ans` (the result) to 0.
3. Loop through each character of the string:
   - Compare the value of `mp[s[i]]` with `mp[s[i+1]]`.
   - If `mp[s[i]] < mp[s[i+1]]`, subtract `mp[s[i]]` from `ans`.
   - Else, add `mp[s[i]]` to `ans`.
4. Return `ans`.

### Example

For `MCMXCIV`:

- `M (1000)` and next is `C (100)`. Since 1000 > 100, add 1000 → `ans = 1000`.
- `C (100)` and next is `M (1000)`. Since 100 < 1000, subtract 100 → `ans = 900`.
- `M (1000)` and next is `X (10)`. 1000 > 10, add 1000 → `ans = 1900`.
- `X (10)` and next is `C (100)`. 10 < 100, subtract 10 → `ans = 1890`.
- `C (100)` and next is `I (1)`. 100 > 1, add 100 → `ans = 1990`.
- `I (1)` and next is `V (5)`. 1 < 5, subtract 1 → `ans = 1989`.
- `V (5)` and no more subtractive cases, add 5 → `ans = 1994`.

### Complexity

- **Time Complexity**: \(O(n)\).
- **Space Complexity**: \(O(1)\).

---

## Additional Function: `string_loop`

- Simply loops through each character of the string and prints them, then returns the size of the string.
- This is a helper function to demonstrate iteration through a string (not directly related to the Roman numeral conversion).

---

## Final Thoughts

Both `romanToInt` and `romanToInt2` correctly solve the Roman to Integer problem, but they differ in implementation style:

- **`romanToInt`**: Explicitly checks for each known subtractive combination.
- **`romanToInt2`**: Uses a more concise logic by relying on the comparison of adjacent values.

In practice, `romanToInt2` is often considered more elegant and extensible since it avoids numerous `if/else` checks for each possible combination. However, `romanToInt` might be more immediately clear to beginners because it explicitly handles each known subtractive case. Both solutions have a linear time complexity and constant extra space usage.
