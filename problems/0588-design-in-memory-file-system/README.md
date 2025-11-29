# Design In-Memory File System

**Difficulty:** Hard
**Tags:** trie, hash-table, design, tree, string

## Problem

Build an in-memory file system that supports creating directories, adding/reading file contents, and listing directory contents or file names. Paths are absolute and begin with '/'. The ls operation must return results in lexicographic order. When a file is created or content is added, all parent directories are guaranteed to exist. File content can be appended to existing files.

## Approach

The solution uses a tree structure where each node represents either a directory or a file. Each `Node` contains a name, a boolean flag `isPath` distinguishing directories from files, a `fileContent` string for file data, and a `map<string, Node*>` storing child nodes (subdirectories or files). The `map` automatically maintains lexicographic order.

All operations parse the input path by splitting on '/' delimiters using `istringstream`. Starting from the root, they traverse the tree following the path tokens.

For `mkdir`, the code creates intermediate nodes as needed, marking each with `isPath = true`. For `addContentToFile`, it creates a file node (with `isPath = false`) if it doesn't exist, or appends to existing content. For `ls`, it returns the sorted children keys if the target is a directory, or a single-element list containing the file's name if it's a file. For `readContentFromFile`, it simply navigates to the file node and returns its content string.

## Complexity

- **Time:** O(d + k log k)
- **Space:** O(n)

## Stats

- Submitted: 2025-11-29 10:02 UTC
- Runtime: 16 ms
- Memory: 21.8 MB
- Language: C++
