# Design Add and Search Words Data Structure

**Difficulty:** Medium
**Tags:** trie, depth-first-search, backtracking, string, design

## Problem

Build a data structure that stores words and supports queries where a wildcard character (dot) can match any single letter. The structure must handle adding words and searching for patterns with up to 2 wildcard characters. Word lengths are capped at 25 characters, and up to 10,000 operations will be performed.

## Approach

The solution uses a trie (prefix tree) where each node has 26 child pointers (one per lowercase letter) and a boolean flag marking valid word endings. Adding a word traverses the trie, creating nodes as needed, and marks the final node as a word.

Searching uses depth-first search with backtracking. For regular characters, it follows the corresponding child pointer or returns false if that path doesn't exist. When encountering a dot wildcard, it recursively explores all 26 possible children that exist, trying to match the remaining pattern from each branch.

The DFS function takes the search word, current position index, and current trie node. It iterates through characters starting from the given position. If all characters match successfully (or via wildcard), it checks whether the final node represents a complete word.

## Complexity

- **Time:** O(m) for addWord where m is word length; O(26^k * m) for search in worst case where k is the number of dots and m is word length
- **Space:** O(n * m) where n is the number of words and m is average word length

## Stats

- Submitted: 2024-07-20 04:46 UTC
- Runtime: 521 ms
- Memory: 563.1 MB
- Language: C++
