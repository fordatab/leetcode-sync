# Adding Spaces to a String

**Difficulty:** Medium
**Tags:** string, array, two-pointers

## Problem

Given a string and a sorted array of indices, insert a space before the character at each specified index and return the modified string. The indices are strictly increasing and indicate positions in the original string where spaces should be placed.

## Approach

The solution iterates through the `spaces` array sequentially. For each space index, it extracts the substring from the last processed position up to (but not including) the current space index using `substr`, appends it to the output string followed by a space character, then updates the tracking position to the current space index. After processing all space positions, it appends the remaining portion of the original string from the last space position to the end. This builds the result incrementally by concatenating substrings with spaces inserted at the correct positions.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-04-21 23:09 UTC
- Runtime: 26 ms
- Memory: 86.8 MB
- Language: C++
