# Simplify Path

**Difficulty:** Medium
**Tags:** stack, string, string-parsing, simulation

## Problem

Given an absolute Unix path that may contain special components like '.' (current directory), '..' (parent directory), and consecutive slashes, transform it into its canonical simplified form. The canonical path must start with a single '/', have no trailing slash (except for root), contain no consecutive slashes, and have all '..' and '.' components resolved. The path length can be up to 3000 characters and consists of letters, digits, periods, slashes, and underscores.

## Approach

The solution uses a stack to track the valid directory names as we parse the path. It iterates through the input string character by character, skipping over slashes to extract directory/file name components between slashes. For each extracted component:

- If it's a single period '.', it represents the current directory and is ignored (continue to next component)
- If it's a double period '..', it means going up one level, so we pop from the stack if it's not empty
- If it's any other string (including sequences like '...' or '....'), it's treated as a valid directory name and pushed onto the stack

After processing all components, the stack contains the valid path components from root to leaf. The solution then constructs the result by prepending each stack element with a '/' and building the string from top to bottom (which gives the correct order since stack is LIFO). If the stack is empty after processing, it returns '/' for the root directory.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-15 04:26 UTC
- Runtime: 9 ms
- Memory: 11.8 MB
- Language: C++
