# Most Frequent Subtree Sum

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, hash-table, recursion, tree-traversal

## Problem

Given a binary tree, compute the sum of all node values in every possible subtree (where each node is the root of its own subtree). Return all subtree sums that appear most frequently. If multiple sums tie for the highest frequency, return all of them. The tree can have up to 10,000 nodes with values ranging from -100,000 to 100,000.

## Approach

The solution uses a post-order depth-first search (DFS) to compute subtree sums bottom-up. For each node, the DFS recursively calculates the sum of its left subtree and right subtree, then adds the current node's value to get the total subtree sum rooted at that node. Each computed sum is recorded in a hash map that tracks frequency counts.

After traversing the entire tree, the solution performs two passes over the hash map: first to find the maximum frequency among all subtree sums, then to collect all sums that match this maximum frequency into the result vector.

The key insight is that by computing subtree sums recursively and returning each sum up the call stack, we naturally visit every subtree exactly once while building the frequency map in a single tree traversal.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-06 04:53 UTC
- Runtime: 7 ms
- Memory: 24.2 MB
- Language: C++
