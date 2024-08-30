# Triangle

**Difficulty:** Medium
**Tags:** dynamic-programming, array, bottom-up-dp

## Problem

Given a triangular 2D array where each row has one more element than the previous row, find the minimum sum along any path from the top element to any element in the bottom row. At each step, you can only move down to either the same index or one index to the right in the next row. The triangle has up to 200 rows, and element values range from -10,000 to 10,000.

## Approach

The solution uses dynamic programming with a 2D table to build up minimum path sums row by row. It initializes `dp[0][0]` with the triangle's apex value, then iterates through each subsequent row. For each position `(i, j)`, it computes the minimum path sum by adding the current triangle value to the minimum of the reachable positions from the previous row. Edge cases are handled specially: the leftmost position (j=0) can only come from the position directly above, and the rightmost position (j=i) can only come from the position diagonally above-left. For interior positions, it takes the minimum of both possible parent positions. After filling the DP table, the answer is the minimum value in the last row of the DP array.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n^2)

## Stats

- Submitted: 2024-08-30 06:05 UTC
- Runtime: 54 ms
- Memory: 11.6 MB
- Language: C++
