# Word Search II

**Difficulty:** Hard
**Tags:** trie, backtracking, depth-first-search, matrix

## Problem

Given an m×n grid of lowercase letters and a list of target words, find all words that can be formed by traversing adjacent cells (horizontally or vertically) without reusing any cell within a single word. The board dimensions are at most 12×12, there can be up to 30,000 words, and each word is at most 10 characters long.

## Approach

The solution uses a trie (prefix tree) to efficiently store and search for all target words simultaneously. Each trie node tracks a reference count indicating how many words still use that prefix branch.

Before searching, all words are inserted into the trie. Then, a depth-first search (DFS) is launched from every cell on the board. During DFS, the algorithm maintains a visited set (storing cell coordinates as strings) to prevent reusing cells in the current path, and builds the current word character by character while traversing the trie.

When a complete word is found (marked by `isWord` flag), it's added to the result set, the `isWord` flag is cleared to avoid duplicates, and the word is removed from the trie by decrementing reference counts along its path. The reference count optimization allows the DFS to prune branches early: if a trie node's `refs` count drops to zero, no remaining words use that prefix, so the search doesn't explore that direction.

After exploring all four adjacent directions recursively, the current cell is removed from the visited set (backtracking), allowing it to be used in other word paths starting from different positions.

## Complexity

- **Time:** O(m * n * 4^L)
- **Space:** O(W * L)

## Stats

- Submitted: 2024-07-21 07:04 UTC
- Runtime: 1467 ms
- Memory: 89.6 MB
- Language: C++
