# Number of Substrings With Only 1s

**Difficulty:** Medium
**Tags:** two-pointers, string, math, combinatorics

## Problem

Given a binary string containing only '0' and '1' characters, count the total number of contiguous substrings that consist entirely of '1's. The string can be up to 100,000 characters long, and since the result may be large, return it modulo 10^9 + 7.

## Approach

The solution uses a two-pointer approach to identify consecutive sequences of '1's in the string.

It maintains two pointers `l` (left) and `r` (right) that scan through the string. When `r` encounters a '1', it advances until it hits a '0' or the end of the string, effectively marking a contiguous block of '1's from index `l` to `r-1`.

For each block of consecutive '1's with length `n`, the number of possible substrings is calculated using the formula n*(n+1)/2. This formula counts all possible contiguous subsequences: a block of length 3 yields 3 substrings of length 1, 2 substrings of length 2, and 1 substring of length 3, totaling 6 = 3*4/2.

After processing each block, both pointers advance past the '0' separator to find the next block. The result is accumulated modulo 10^9 + 7 to handle large values.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-03 05:09 UTC
- Runtime: 0 ms
- Memory: 11.7 MB
- Language: C++
