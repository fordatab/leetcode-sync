# Design File System

**Difficulty:** Medium
**Tags:** trie, hash-table, design, string

## Problem

Design a file system that supports creating hierarchical paths (like "/a" or "/a/b/c") with associated integer values. The createPath operation must fail if the path already exists or if its immediate parent path doesn't exist yet. The get operation retrieves the value for an existing path or returns -1 if not found. Paths consist of forward slashes followed by lowercase letters, with up to 10^4 total operations.

## Approach

The solution implements a trie-like tree structure where each node contains a hash map of child nodes and an integer value. The root node is initialized with a default value of -1.

For createPath, the path string is tokenized by splitting on '/' characters. The code then traverses the tree following the path components. For all segments except the last one, it checks if the intermediate node exists—if any parent is missing, it returns false. When reaching the final segment, it creates a new node with the given value only if that segment doesn't already exist in the current node's children.

For get, the path is similarly tokenized and the tree is traversed segment by segment. If any segment is not found in the current node's children map, it returns -1. Otherwise, it follows the path to the end and returns the value stored in the final node.

The tokenize helper function uses a stringstream with getline to split the path on '/' delimiters, filtering out empty strings that result from the leading slash.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-09-03 01:11 UTC
- Runtime: 148 ms
- Memory: 133.1 MB
- Language: C++
