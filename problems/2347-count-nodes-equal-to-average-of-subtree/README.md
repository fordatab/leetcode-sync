# Count Nodes Equal to Average of Subtree

**Difficulty:** Medium
**Tags:** binary-tree, depth-first-search, post-order-traversal, recursion

## Problem

Given a binary tree, count how many nodes have a value equal to the floor of the average of all values in their subtree (the node itself plus all descendants). The average is computed as the sum divided by the count, rounded down. The tree can have between 1 and 1000 nodes, with node values from 0 to 1000.

## Approach

The solution uses a post-order depth-first traversal to compute subtree statistics bottom-up. The helper function `avg` returns a pair containing the sum of all values and the count of all nodes in the subtree rooted at the current node.

For each node, it recursively processes the left and right children first, then combines their results with the current node's value (sum += node value, count += 1). It checks if the integer division of the sum by the count equals the node's value, and if so, increments a counter passed by reference.

The key insight is that by using post-order traversal, we can efficiently compute subtree sums and counts in a single pass, avoiding redundant traversals. Each node is visited exactly once, and the pair return value allows us to propagate the necessary information up the tree.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-30 20:21 UTC
- Runtime: 3 ms
- Memory: 14.8 MB
- Language: C++
