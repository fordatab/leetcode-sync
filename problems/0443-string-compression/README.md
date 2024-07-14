# String Compression

**Difficulty:** Medium
**Tags:** two-pointers, string, array, in-place

## Problem

Given an array of characters, compress it in-place by replacing consecutive repeating characters with the character followed by its count (if greater than 1). The compression must be done in-place with constant extra space, and the function returns the new length of the compressed array. Counts of 10 or more are split into individual digit characters.

## Approach

The solution uses a two-pointer technique to compress the array in-place. A sentinel null character is appended to simplify boundary handling. The algorithm maintains a read pointer (`x`) that scans through the input and a write pointer (`index`) that tracks where to write the compressed output.

For each group of consecutive characters, it counts occurrences while the current character matches. When a different character is encountered, it writes the previous character to the output position. If the count is greater than 1, it converts the count to a string and writes each digit character sequentially to the array.

The key insight is that by processing left-to-right and writing compressed data at earlier positions, the algorithm safely overwrites positions that have already been read, maintaining constant space complexity. The count is reset to 1 when moving to a new character group.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-14 05:31 UTC
- Runtime: 4 ms
- Memory: 14.1 MB
- Language: C++
