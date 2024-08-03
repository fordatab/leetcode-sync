# Pascal's Triangle II

**Difficulty:** Easy
**Tags:** dynamic-programming, array, pascals-triangle, math

## Problem

Given a zero-indexed integer rowIndex, return the specific row of Pascal's triangle at that index. In Pascal's triangle, each element is the sum of the two elements directly above it in the previous row. The constraint is that rowIndex ranges from 0 to 33.

## Approach

The solution builds all rows of Pascal's triangle from row 0 up to the requested rowIndex using a 2D dynamic programming table. It initializes a vector of vectors where each row starts with a single 1. For each subsequent row (starting from row 2), it iterates through the previous row and computes each new element as the sum of two adjacent elements from the row above. After computing the interior elements, it appends a trailing 1 to complete the row. Finally, it returns the row at index rowIndex+1 from the dp table (accounting for the indexing offset in the initialization).

The key insight is that each row can be constructed from the previous row by summing adjacent pairs, with 1's at both ends. However, this implementation stores all intermediate rows rather than using the follow-up optimization of maintaining only a single row.

## Complexity

- **Time:** O(n²)
- **Space:** O(n²)

## Stats

- Submitted: 2024-08-03 06:36 UTC
- Runtime: 4 ms
- Memory: 8.2 MB
- Language: C++
