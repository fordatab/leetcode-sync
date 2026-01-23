# Special Binary String

**Difficulty:** Hard
**Tags:** recursion, string, sorting, divide-and-conquer, greedy

## Problem

Given a special binary string (where the count of 0s equals 1s, and every prefix has at least as many 1s as 0s), find the lexicographically largest string achievable by repeatedly swapping consecutive special substrings. The input string length is at most 50 characters.

## Approach

The solution uses a recursive depth-first search to parse and rearrange the special binary string. It treats the string as a nested structure similar to balanced parentheses, where '1' acts as an opening bracket and '0' as a closing bracket.

The algorithm recursively identifies and extracts all top-level special substrings (those that start with '1' and end with '0' at the same nesting level). For each '1' encountered, it recursively processes the inner content before the matching '0'. These extracted substrings are collected in a vector.

After collecting all consecutive special substrings at the current level, they are sorted lexicographically and then added to the result in reverse order (largest first) to maximize the lexicographic value. Each processed substring is wrapped with '1' at the start and '0' at the end to maintain the special string property.

The recursion naturally handles the nested structure, and the sorting at each level ensures that larger substrings appear first, producing the lexicographically maximum result.

## Complexity

- **Time:** O(n^2 log n)
- **Space:** O(n^2)

## Stats

- Submitted: 2026-01-23 21:42 UTC
- Runtime: 0 ms
- Memory: 8.8 MB
- Language: C++
