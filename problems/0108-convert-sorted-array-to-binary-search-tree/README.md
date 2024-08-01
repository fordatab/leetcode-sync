# Convert Sorted Array to Binary Search Tree

**Difficulty:** Easy
**Tags:** binary-search-tree, divide-and-conquer, recursion, tree, array

## Problem

Given a sorted array of integers in strictly increasing order (with length between 1 and 10,000 and values from -10,000 to 10,000), construct a height-balanced binary search tree. The resulting tree must maintain the BST property while ensuring that the depths of any node's two subtrees differ by at most one.

## Approach

The solution uses a recursive divide-and-conquer strategy to build the tree from the middle outward. It employs a helper function `dfs` that takes left and right indices defining the current subarray:

- The base case returns `nullptr` when the left index exceeds the right, indicating an empty subarray.
- For each subarray, the middle element is selected as the root node using `mid = (r - l)/2 + l`, which avoids potential integer overflow compared to `(l + r)/2`.
- The left subtree is recursively constructed from the left half (indices `l` to `mid - 1`) and the right subtree from the right half (indices `mid + 1` to `r`).
- By consistently choosing the middle element as the root, the algorithm ensures the tree remains balanced, as each subtree contains roughly equal numbers of elements.

## Complexity

- **Time:** O(n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-08-01 04:43 UTC
- Runtime: 7 ms
- Memory: 22.1 MB
- Language: C++
