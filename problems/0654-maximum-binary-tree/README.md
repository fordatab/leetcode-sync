# Maximum Binary Tree

**Difficulty:** Medium
**Tags:** binary-tree, divide-and-conquer, recursion, array

## Problem

Given an array of unique integers, construct a binary tree where each node's value is the maximum element in its corresponding subarray. The left child is built from elements to the left of the maximum, and the right child from elements to the right. The array can have up to 1000 elements with values between 0 and 1000.

## Approach

The solution uses a recursive divide-and-conquer approach. For each subarray, it scans linearly to find the maximum value and its index. It creates a node with that maximum value, then constructs two new subarrays: one containing all elements before the maximum (for the left subtree) and one containing all elements after it (for the right subtree). The function recursively builds the left and right children by calling itself on these new subarrays. The base case returns `nullptr` when the input array is empty. The linear scan uses a simple loop that tracks both the maximum value and its index position.

## Complexity

- **Time:** O(n^2)
- **Space:** O(n^2)

## Stats

- Submitted: 2024-08-01 03:17 UTC
- Runtime: 92 ms
- Memory: 54.5 MB
- Language: C++
