# Word Search II

**Difficulty:** Hard
**Tags:** trie, backtracking, depth-first-search, matrix, string

## Problem

Given an m×n grid of letters and a list of target words, find all words that can be formed by traversing adjacent cells (horizontally or vertically) without reusing any cell within a single word. The board dimensions are at most 12×12, there can be up to 30,000 words, and each word is at most 10 characters long.

## Approach

The solution builds a trie (prefix tree) from all target words, where each word is marked with a special '#' key at its terminal node. It then performs depth-first search from every cell on the board, using the trie to guide the search and prune paths that don't match any word prefix.

During DFS, the algorithm temporarily marks visited cells with '*' to prevent reuse within the same word path, then restores the original character after exploring all directions. When a complete word is found (indicated by the '#' marker in the trie), it's removed from the trie and added to the results to avoid duplicates.

The solution includes an optimization: after exploring from a trie node, if that node becomes empty (has no remaining children), it's pruned from the parent node. This reduces redundant searches as words are found and removed from the trie during traversal.

## Complexity

- **Time:** O(m * n * 4^L)
- **Space:** O(w * L)

## Stats

- Submitted: 2024-07-21 07:15 UTC
- Runtime: 479 ms
- Memory: 17.8 MB
- Language: Python3
