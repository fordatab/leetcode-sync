# Find Leaves of Binary Tree

**Difficulty:** Medium
<<<<<<< HEAD
**Tags:** binary-tree, depth-first-search, post-order-traversal, recursion

## Problem

Given a binary tree, repeatedly collect and remove all leaf nodes until the tree becomes empty, returning the nodes grouped by each removal round. The tree has between 1 and 100 nodes with values ranging from -100 to 100. The order of nodes within each collection round doesn't matter.

## Approach

The solution computes the "height" of each node, defined as the maximum distance to any leaf below it (leaves have height 0, their parents have height 1, etc.). Using a post-order traversal, the algorithm recursively determines each node's height by finding the maximum height of its children and adding 1. Nodes are then grouped by their height into a results vector, where `leaves[h]` contains all nodes at height `h`. This naturally groups nodes that would be removed in the same iteration—all leaves (height 0) are removed first, then their parents (height 1), and so on. The result vector is dynamically expanded as new heights are discovered during the traversal.
=======
**Tags:** binary-tree, depth-first-search, post-order-traversal, recursion, tree-height

## Problem

Given a binary tree, repeatedly collect and remove all leaf nodes until the tree is empty, returning the nodes grouped by each removal round. A leaf node is one with no children. The tree has between 1 and 100 nodes with values ranging from -100 to 100.

## Approach

The solution computes the "height" of each node, where height is defined as the distance from the farthest leaf below it (leaves have height 0, their parents have height 1, etc.). This is done through a post-order traversal.

The recursive `height` function:
- Returns -1 for null nodes
- Recursively computes the height of left and right subtrees
- Sets the current node's height as `max(left_height, right_height) + 1`
- Uses the height as an index to place the node's value in the appropriate group within the `leaves` vector

Since nodes at the same height are removed in the same round (height 0 nodes are removed first, then height 1, etc.), grouping by height naturally produces the desired output. The result vector is built dynamically, expanding as new height levels are discovered.
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-04-21 20:25 UTC
- Runtime: 3 ms
- Memory: 11.4 MB
- Language: C++
