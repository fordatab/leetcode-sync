# Longest Increasing Path in a Matrix

**Difficulty:** Hard
**Tags:** depth-first-search, dynamic-programming, memoization, matrix, graph

## Problem

Given an m×n matrix of integers, find the length of the longest path where you can move up, down, left, or right to adjacent cells with strictly increasing values. Movement is restricted to the four cardinal directions within matrix bounds, with no diagonal moves or wrap-around allowed. The matrix dimensions can be up to 200×200, and cell values range from 0 to 2³¹-1.

## Approach

The solution uses **depth-first search with memoization** (top-down dynamic programming). For each cell in the matrix, it explores all four cardinal directions, recursively computing the longest increasing path starting from neighboring cells that have greater values. The `dp` table caches the longest path starting from each position to avoid recomputation.

The algorithm iterates through every cell as a potential starting point, invoking DFS for each. During DFS, if a cell's result is already cached, it returns immediately. Otherwise, it explores all valid neighbors (those within bounds and with greater values), recursively computes their longest paths, and takes the maximum plus one for the current cell. This result is stored in `dp[x][y]` before returning.

The key insight is that the strictly increasing constraint creates a directed acyclic graph structure — you can never revisit a cell during a single path traversal. This property guarantees that memoization is safe and prevents infinite recursion. Each cell is computed exactly once, and the global maximum across all starting positions is the answer.

## Complexity

- **Time:** O(m*n)
- **Space:** O(m*n)

## Stats

- Submitted: 2024-08-28 05:25 UTC
- Runtime: 26 ms
- Memory: 19.5 MB
- Language: C++
