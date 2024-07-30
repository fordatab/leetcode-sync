# Domino and Tromino Tiling

**Difficulty:** Medium
**Tags:** dynamic-programming, state-machine, combinatorics, modular-arithmetic

## Problem

Given two tile types (2×1 dominoes and L-shaped trominoes that can be rotated), determine how many distinct ways exist to completely tile a 2×n board. The board must be fully covered with no gaps or overlaps, and the answer should be returned modulo 10^9 + 7. The value n ranges from 1 to 1000.

## Approach

The solution uses dynamic programming with two states per column position. For each column i, `dp[i][0]` tracks the count of tilings where both rows are fully covered up to column i (a "complete" state), while `dp[i][1]` tracks tilings where column i has exactly one cell filled, leaving an overhang into the next column (a "partial" state).

The recurrence relations capture how tiles can be placed:
- A complete state at column i can be reached by: (1) placing a vertical domino from a complete state at i-1, (2) placing two horizontal dominoes from a complete state at i-2, or (3) placing a tromino configuration from a partial state at i-2 (the factor of 2 accounts for top and bottom tromino orientations).
- A partial state at column i can be reached by: (1) placing a tromino from a complete state at i-1, or (2) placing a horizontal domino from a partial state at i-1.

Base cases are established for n=1 and n=2, then the DP table is filled iteratively up to n. The final answer is the complete-state count at column n, taken modulo 10^9 + 7.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-30 01:49 UTC
- Runtime: 2 ms
- Memory: 9 MB
- Language: C++
