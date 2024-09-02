# Path Sum III

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, prefix-sum, hash-table, backtracking

## Problem

Given a binary tree and a target sum, count how many downward paths (from any ancestor to any descendant) have values that sum to the target. The tree can have up to 1000 nodes with values ranging from -10^9 to 10^9, and the target sum ranges from -1000 to 1000. Paths must follow parent-to-child direction but don't need to start at the root or end at a leaf.

## Approach

The solution uses a prefix sum technique with a hash map to efficiently count valid paths. During a depth-first traversal, it maintains a running prefix sum from the root to the current node. For each node, it checks if `prefix_sum - target` exists in the hash map, which indicates that a subpath ending at the current node sums to the target (similar to the subarray sum pattern). The hash map tracks the frequency of each prefix sum encountered along the current path. After processing both children, the solution decrements the current prefix sum count (backtracking) to ensure the map only reflects the ancestor chain for subsequent branches. This approach avoids checking every possible path explicitly by leveraging the mathematical relationship that a path sum equals the difference between two prefix sums.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-02 05:33 UTC
- Runtime: 7 ms
- Memory: 21.9 MB
- Language: C++
