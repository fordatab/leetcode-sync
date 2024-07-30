# Pascal's Triangle

**Difficulty:** Easy
**Tags:** array, dynamic-programming, math

## Problem

Given a positive integer numRows (1 ≤ numRows ≤ 30), generate the first numRows rows of Pascal's triangle. Each row starts and ends with 1, and each interior element equals the sum of the two elements directly above it in the previous row.

## Approach

The solution uses a 2D vector `dp` of size `numRows + 1`, where each row is initialized with a single 1. It skips index 0 and starts building from row 2 onwards.

For each row `x` from 2 to `numRows`, it iterates through the previous row (`dp[x-1]`) and computes interior values by summing adjacent pairs: `dp[x-1][y] + dp[x-1][y+1]`. These sums are appended to the current row. After processing all interior elements, a trailing 1 is added to complete the row.

The final result extracts rows 1 through numRows from the `dp` vector (skipping the unused index 0) and returns them as the triangle. The debug output statements (cout) are artifacts from development but don't affect correctness.

## Complexity

- **Time:** O(numRows²)
- **Space:** O(numRows²)

## Stats

- Submitted: 2024-07-30 02:09 UTC
- Runtime: 0 ms
- Memory: 8.1 MB
- Language: C++
