# Search Suggestions System

**Difficulty:** Medium
**Tags:** sorting, binary-search, string, prefix-matching, greedy

## Problem

Given an array of product names and a search word, return suggestions after typing each character of the search word. For each prefix formed while typing, return up to three lexicographically smallest products that share that prefix. The products array can contain up to 1000 strings, and the total length of all products combined is at most 20,000 characters.

## Approach

The solution first sorts all products lexicographically to ensure that matching products appear in order. Then, for each character typed in the search word, it builds up the current prefix string. Using binary search (`lower_bound`), it finds the starting position in the sorted array where products with the current prefix would begin. From that starting position, it collects up to three products that match the prefix by checking if each product's beginning matches the current prefix string. An optimization is employed by remembering the previous binary search starting position (`bsStart`) and searching only from there forward, since as the prefix grows longer, matching products can only appear at the same position or later in the sorted array. The results for each prefix are collected into a nested vector structure.

## Complexity

- **Time:** O(n log n + m * (log n + k))
- **Space:** O(1)

## Stats

- Submitted: 2024-09-02 06:05 UTC
- Runtime: 33 ms
- Memory: 27.8 MB
- Language: C++
