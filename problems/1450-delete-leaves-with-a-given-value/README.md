# Delete Leaves With a Given Value

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, recursion, post-order-traversal

## Problem

Given a binary tree and a target integer, repeatedly remove all leaf nodes whose value equals the target. After each removal, some internal nodes may become new leaves; if they also match the target, they must be deleted as well. Continue this process until no more qualifying leaves can be removed. The tree can have up to 3000 nodes with values between 1 and 1000.

## Approach

This solution uses a post-order depth-first traversal to process the tree from the bottom up. The recursive function first processes both left and right subtrees, updating the child pointers with the results. After processing children, it checks whether the current node has become a leaf (both children are null) and whether its value matches the target. If both conditions are met, the function returns `nullptr` to signal deletion; otherwise, it returns the node itself. This bottom-up approach ensures that once a leaf is removed, any newly-created leaves are immediately evaluated for removal in the same traversal.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-08-01 04:39 UTC
- Runtime: 13 ms
- Memory: 23.2 MB
- Language: C++
