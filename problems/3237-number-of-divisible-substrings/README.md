# Number of Divisible Substrings

**Difficulty:** Medium
**Tags:** prefix-sum, hash-table, string, math

## Problem

Given a string where each letter maps to a digit (like on old phone keypads: 'a'-'c' map to 1, 'd'-'f' to 2, etc.), find how many substrings have the property that their mapped digit sum is divisible by their length. The string can be up to 2000 characters long and contains only lowercase English letters.

## Approach

The solution leverages a key insight: a substring is divisible if `sum/length = avg` for some integer `avg`. Since mapped values range from 1 to 9, we only need to check averages 1 through 9.

For each possible average value, the code transforms the problem using a prefix sum technique. It computes `prefix[i] = sum of (f(c) - avg)` for all characters up to position i. Two positions with the same prefix value indicate a substring between them has average `avg`, because the sum of differences equals zero means the actual sum equals `avg * length`.

The algorithm iterates through each of the 9 possible averages. For each average, it maintains a running prefix sum and a hash map counting how many times each prefix value has been seen. When it encounters a prefix value it's seen before, those previous occurrences represent valid substrings ending at the current position. The total count across all 9 iterations gives the answer.

The mapping function `f(c)` computes which digit (1-9) a character maps to by calculating `9 - (('z' - c) / 3)`, which groups letters into sets of three working backwards from 'z'.

## Complexity

- **Time:** O(9n) = O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-03-05 09:20 UTC
- Runtime: 99 ms
- Memory: 41.2 MB
- Language: C++
