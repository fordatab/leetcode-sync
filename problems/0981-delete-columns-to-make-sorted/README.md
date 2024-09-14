# Delete Columns to Make Sorted

**Difficulty:** Easy
**Tags:** array, string, matrix

## Problem

Given an array of n equal-length strings, imagine arranging them as rows in a grid where each column represents characters at the same position across all strings. Count how many columns are not sorted in lexicographic order (where any character is smaller than the one above it). The constraints allow up to 100 strings of up to 1000 characters each.

## Approach

The solution iterates through each column position (x from 0 to n-1) across all strings. For each column, it checks consecutive pairs of characters from top to bottom (y from 1 to m-1). If any character in the column is lexicographically smaller than the character directly above it (strs[y][x] < strs[y-1][x]), the column is unsorted and the counter increments, then breaks to move to the next column. This directly counts columns that violate the sorted property by checking for any descending pair.

## Complexity

- **Time:** O(m * n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-14 03:43 UTC
- Runtime: 32 ms
- Memory: 14.6 MB
- Language: C++
