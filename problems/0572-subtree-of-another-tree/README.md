# Subtree of Another Tree

**Difficulty:** Easy
**Tags:** tree, depth-first-search, binary-tree, recursion

## Problem

Given two binary trees, determine whether the second tree appears as an exact subtree somewhere within the first tree. A subtree match requires identical structure and node values from a particular node downward. Both trees can contain between 1 and 2000 nodes (for the main tree) or 1 to 1000 nodes (for the subtree candidate), with node values ranging from -10,000 to 10,000.

## Approach

The solution uses a recursive strategy with two helper functions. The main `isSubtree` function traverses every node in the primary tree, testing whether the subtree rooted at each position matches the target subtree. At each node, it first checks if the trees are identical starting from that point using `sameTree`. If not, it recursively searches the left and right subtrees.

The `sameTree` helper performs a simultaneous traversal of both trees, comparing node values and structure. It returns true only when both trees are null (base case) or when current nodes have matching values and their left and right subtrees also match recursively.

The algorithm essentially performs a depth-first search on the main tree, and at each candidate node, runs a full tree comparison. This approach handles edge cases like null inputs and ensures exact structural matching rather than just checking for the presence of values.

## Complexity

- **Time:** O(m * n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-16 22:59 UTC
- Runtime: 17 ms
- Memory: 28 MB
- Language: C++
