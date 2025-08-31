# Find the Length of the Longest Common Prefix

**Difficulty:** Medium
**Tags:** trie, prefix-tree, string, hash-table

## Problem

Given two arrays of positive integers, find the length of the longest common prefix among all pairs where one integer comes from the first array and one from the second. A prefix is formed by taking leading digits of a number (e.g., 12 and 123 are prefixes of 1234). Arrays can contain up to 50,000 elements, with values up to 100,000,000.

## Approach

The solution uses a trie (prefix tree) data structure where each node has 10 children corresponding to digits 0-9. First, all numbers from `arr1` are inserted into the trie by converting each to a string and traversing digit by digit, marking every intermediate node as an end-of-word (creating all possible prefixes). Then, for each number in `arr2`, the code traverses the trie matching its digits from left to right. Whenever a matching node that's marked as end-of-word is found, it represents a valid common prefix, and the maximum length is updated. The key insight is that building the trie from one array allows efficient prefix matching for all numbers in the second array without comparing every pair explicitly.

## Complexity

- **Time:** O(m * d1 + n * d2)
- **Space:** O(m * d1)

## Stats

- Submitted: 2025-08-31 23:44 UTC
- Runtime: 143 ms
- Memory: 169.5 MB
- Language: C++
