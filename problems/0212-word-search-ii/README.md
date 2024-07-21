# Word Search II

**Difficulty:** Hard
**Tags:** trie, backtracking, depth-first-search, matrix

## Problem

Given an m×n grid of lowercase letters and a list of words, find all words that can be formed by following adjacent cells (horizontally or vertically) without reusing any cell within a single word. The grid dimensions are at most 12×12, there can be up to 30,000 words, and each word is at most 10 characters long.

## Approach

The solution builds a trie from all dictionary words, then performs depth-first search from every cell on the board, traversing through the trie simultaneously. The code uses a custom 2D board structure that organizes cells into 8×8 blocks for cache efficiency. Before searching, it filters out words containing characters not present on the board or exceeding the character frequency available. During DFS, it marks cells as visited to prevent reuse within a path, explores all four adjacent directions, and collects words when reaching trie nodes marked as word endings. The visited state is backtracked after exploring each path, allowing cells to be reused across different word searches.

## Complexity

- **Time:** O(m * n * 4^L)
- **Space:** O(W * L)

## Stats

- Submitted: 2024-07-21 07:13 UTC
- Runtime: 142 ms
- Memory: 3.3 MB
- Language: Rust
