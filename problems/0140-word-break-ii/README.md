# Word Break II

**Difficulty:** Hard
**Tags:** trie, backtracking, dynamic-programming, string-segmentation, recursion

## Problem

Given an input string and a dictionary of valid words, find all possible ways to segment the string into space-separated sequences where each segment is a word from the dictionary. Words from the dictionary can be reused multiple times. The string length is at most 20, the dictionary contains up to 1000 words of length up to 10 each, and all dictionary words are unique.

## Approach

The solution uses a **trie data structure** to efficiently store and lookup dictionary words, combined with **backtracking** to explore all valid segmentations.

**Trie Construction**: First, all dictionary words are inserted into a trie where each node contains a map of characters to child nodes and a boolean flag indicating if a complete word ends at that node.

**Backtracking with DP Array**: A recursive `bt` function explores the string from left to right. Starting at each position `i`, it traverses the trie character by character, accumulating characters into a `word`. When a complete word is found (marked by `isWord`), and if position `i` is reachable (checked via `dp[i] == 1`), it appends the word to the current sentence and recursively continues from the next position. The `dp` array tracks which positions have been successfully reached during exploration, acting as a pruning mechanism.

**Result Collection**: When the backtracking reaches the end of the string (`i == s.size()`), the accumulated sentence (with the trailing space removed) is added to the output. The backtracking unwinds by removing the last added word from the current sentence string before trying other branches.

## Complexity

- **Time:** O(2^n * n)
- **Space:** O(n * m + k)

## Stats

- Submitted: 2026-01-19 10:42 UTC
- Runtime: 1 ms
- Memory: 10.7 MB
- Language: C++
