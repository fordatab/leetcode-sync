# Alien Dictionary

**Difficulty:** Hard
**Tags:** graph, topological-sort, depth-first-search, cycle-detection, string

## Problem

Given a list of words from an alien language that uses English letters but in an unknown order, determine if the words are sorted according to some valid lexicographic ordering, and if so, return one possible ordering of the alphabet. The words are claimed to be sorted lexicographically by the alien language rules. If the ordering is invalid (contains contradictions or impossible orderings like a longer prefix appearing before its substring), return an empty string.

## Approach

The solution builds a directed graph where each character points to characters that must come after it in the alien alphabet. First, it initializes the adjacency list with all characters that appear in any word. Then it compares consecutive word pairs: if a longer word is a prefix of the next word, the ordering is invalid; otherwise, it finds the first differing character and adds a directed edge from the character in the first word to the character in the second word.

After building the graph, the solution performs a depth-first search (DFS) on each character to detect cycles and produce a topological ordering. The DFS uses a visited map where `true` indicates the node is currently in the recursion stack (allowing cycle detection) and `false` means it has been fully processed. Characters are appended to the result string in post-order (after visiting all descendants), which produces a reverse topological sort.

Finally, the result string is reversed to get the correct topological order. If a cycle is detected during any DFS traversal (indicated by encountering a node already marked `true` in the visited map), the function returns an empty string, as this means the ordering is invalid.

## Complexity

- **Time:** O(C)
- **Space:** O(C)

## Stats

- Submitted: 2026-01-15 00:25 UTC
- Runtime: 3 ms
- Memory: 12.3 MB
- Language: C++
