# Step-By-Step Directions From a Binary Tree Node to Another

**Difficulty:** Medium
**Tags:** binary-tree, lowest-common-ancestor, tree-traversal, depth-first-search, string

## Problem

Given a binary tree where each node has a unique value from 1 to n, find the shortest path from a start node to a destination node. The path should be represented as a string using 'L' (left child), 'R' (right child), and 'U' (parent) directions. The tree has between 2 and 100,000 nodes, and the start and destination values are guaranteed to be different and exist in the tree.

## Approach

The solution finds the lowest common ancestor (LCA) of the start and destination nodes, then constructs paths from the root to both nodes.

**Finding the LCA:** A recursive function searches for both values, returning nodes when found. If both left and right subtrees return non-null, the current node is the LCA.

**Path Construction:** For both the start and destination values, the code builds path strings from the root by recursively exploring left ('L') and right ('R') branches, tracking the path taken.

**Path Merging:** The solution identifies the common prefix between the two paths (representing the path to their LCA). It then replaces all remaining directions in the start path with 'U' moves (going up to the LCA) and appends the unique suffix from the destination path.

Note: While an LCA is computed, the implementation doesn't actually use it to optimize the path finding—it still searches from the root for both nodes and relies on string manipulation to extract the answer.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-12-03 12:51 UTC
- Runtime: 15 ms
- Memory: 212 MB
- Language: C++
