# Summary of `isSubsequence` Approach

## Problem Statement

The function `isSubsequence(s, t)` determines whether string `s` is a subsequence of string `t`. A subsequence maintains the relative order of characters but does not require them to be consecutive.

## Approach

This solution tracks character matches between `s` and `t` using two boolean flags (`FIRST_CHAR` and `SECOND_CHAR`) and an index (`S_INDEX`) to keep track of progress in `s`.

### Step-by-Step Explanation

1. **Edge Case Handling**

   - If `s` is empty, return `true` immediately since an empty string is always a subsequence.

2. **Tracking Characters in `s`**

   - `S_INDEX` keeps track of the current character in `s` being matched.
   - `FIRST_CHAR` and `SECOND_CHAR` act as alternating flags to track whether the current character has been matched.

3. **Iterating Through `t`**

   - Loop through each character in `t` and check if it matches the current character in `s` (`s[S_INDEX]`).
   - If a match is found:
     - If `FIRST_CHAR` is `false` and `SECOND_CHAR` is `true`, set `FIRST_CHAR` to `true` and `SECOND_CHAR` to `false`.
     - If `FIRST_CHAR` is `true` and `SECOND_CHAR` is `false`, switch the flags.
     - Increment `S_INDEX` to move to the next character in `s`.

4. **Termination Condition**

   - If `S_INDEX` reaches the size of `s`, return `true` since all characters of `s` have been matched in `t`.

5. **Return `false` if `s` is not fully matched**
   - If the loop completes without matching all characters of `s`, return `false`.

## Complexity Analysis

- **Time Complexity:** O(N), where N is the length of `t`. Each character in `t` is checked at most once.
- **Space Complexity:** O(1), since only a few integer and boolean variables are used.

## Observations

- The use of `FIRST_CHAR` and `SECOND_CHAR` is an unconventional way to track matches. A simpler approach using a single index to track `s` may make the logic clearer.
- The function efficiently scans `t` while maintaining the order of characters in `s`.

## Alternative Approach

A simpler implementation using just `S_INDEX` could achieve the same result without the need for extra boolean flags:

```cpp
bool Solution::isSubsequence(std::string s, std::string t) {
    int S_INDEX = 0, S_SIZE = s.size();

    if (S_SIZE == 0) return true;

    for (char c : t) {
        if (c == s[S_INDEX]) S_INDEX++;
        if (S_INDEX == S_SIZE) return true;
    }

    return false;
}
```
