# Word Search

**Difficulty:** Medium
**Tags:** backtracking, depth-first-search, matrix, recursion

## Problem

Given a 2D character grid (up to 6×6) and a target word (up to 15 characters), determine whether the word can be formed by traversing adjacent cells (horizontally or vertically). Each cell can only be visited once per search path.

## Approach

The solution uses backtracking with depth-first search. It iterates through every cell in the grid to find potential starting positions matching the first character of the word. When a match is found, it launches a DFS that explores all four adjacent directions (up, down, left, right) recursively.

During the DFS, the current cell is temporarily marked with '#' to prevent revisiting it in the same path. If the search successfully matches all characters (reaching `index == word.size()-1`), it returns true. If a path fails, the cell is restored to its original character (backtracking) before trying alternative paths.

The base case checks bounds and character matching. The recursive case tries all four directions, returning true if any direction yields a complete match. This exhaustive search continues until either a valid path is found or all possibilities are exhausted.

## Complexity

- **Time:** O(m * n * 4^L)
- **Space:** O(L)

## Stats

- Submitted: 2024-07-21 04:00 UTC
- Runtime: 968 ms
- Memory: 12 MB
- Language: C++
