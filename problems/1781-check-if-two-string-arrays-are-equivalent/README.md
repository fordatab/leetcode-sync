# Check If Two String Arrays are Equivalent

**Difficulty:** Easy
**Tags:** string, array, string-concatenation

## Problem

Given two arrays of strings, determine whether concatenating all strings in the first array produces the same result as concatenating all strings in the second array. Each array can contain up to 1000 strings, with each string containing up to 1000 characters, and the total length of all concatenated characters in each array is at most 1000.

## Approach

The solution uses a straightforward string concatenation approach. It builds two complete strings by iterating through each array separately. For `word1`, it concatenates all strings into variable `a` using a range-based for loop. Similarly, for `word2`, it concatenates all strings into variable `b`. Finally, it performs a direct string comparison using the equality operator to check if both concatenated results are identical. This approach prioritizes simplicity and readability over potential optimizations.

## Complexity

- **Time:** O(n + m)
- **Space:** O(n + m)

## Stats

- Submitted: 2024-08-10 21:38 UTC
- Runtime: 0 ms
- Memory: 13.8 MB
- Language: C++
