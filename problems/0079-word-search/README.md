# Word Search

**Difficulty:** Medium
**Tags:** backtracking, depth-first-search, matrix, recursion

## Problem

Given a 2D grid of characters (at most 6x6) and a target word (at most 15 characters), determine whether the word can be formed by a path of horizontally or vertically adjacent cells in the grid. Each cell can only be used once per path, meaning no cell can be revisited within a single word search.

## Approach

The solution uses depth-first search with backtracking to explore all possible paths in the grid. It iterates through every cell as a potential starting position and attempts to build the target word from that point.

For each starting cell, the `backtrack` function recursively explores the four cardinal directions (right, down, left, up). Before exploring neighbors, it temporarily marks the current cell with a '#' character to prevent revisiting it during the current path exploration. This modification to the board itself serves as the visited tracking mechanism.

The base cases check if the entire word has been matched (index reaches word length) or if the current position is out of bounds or doesn't match the expected character. After exploring all four directions from a cell, the function restores the original character to the board, allowing that cell to be used in different search paths starting from other positions.

The search terminates early as soon as any valid path is found, returning true immediately. If no starting position yields a complete match, the function returns false.

## Complexity

- **Time:** O(m * n * 4^L)
- **Space:** O(L)

## Stats

- Submitted: 2026-04-21 06:48 UTC
- Runtime: 194 ms
- Memory: 10.6 MB
- Language: C++
