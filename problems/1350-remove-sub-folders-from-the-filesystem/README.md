# Remove Sub-Folders from the Filesystem

**Difficulty:** Medium
**Tags:** trie, depth-first-search, string, hash-table

## Problem

Given a list of filesystem folder paths, identify and remove all sub-folders, keeping only the top-level parent folders. A sub-folder is one whose path starts with another folder's path followed by a '/', such as '/a/b' being a sub-folder of '/a'. The input can contain up to 40,000 folder paths, each with lengths between 2 and 100 characters, consisting only of lowercase letters and '/' separators.

## Approach

The solution uses a **trie (prefix tree)** data structure where each node represents a folder segment. For each input path, it splits the path by '/' delimiters and traverses or creates trie nodes for each segment. A boolean flag `Isroot` marks nodes that represent complete folder paths from the input.

During insertion, if the current node is already marked as `Isroot`, insertion stops early since any deeper path would be a sub-folder of an existing parent. After building the trie, a depth-first search (DFS) traverses the structure. When the DFS encounters a node marked `Isroot`, it reconstructs the full path from the accumulated segments and adds it to the result, then returns without exploring deeper (since all descendants would be sub-folders).

The key insight is that by sorting folders implicitly through the trie structure and stopping traversal at marked parent nodes, all sub-folders are automatically excluded from the final output.

## Complexity

- **Time:** O(n * m)
- **Space:** O(n * m)

## Stats

- Submitted: 2025-11-26 12:59 UTC
- Runtime: 107 ms
- Memory: 77.4 MB
- Language: C++
