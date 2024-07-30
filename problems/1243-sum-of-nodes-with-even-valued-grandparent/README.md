# Sum of Nodes with Even-Valued Grandparent

**Difficulty:** Medium
**Tags:** tree, binary-tree, depth-first-search, recursion

## Problem

Given a binary tree, compute the sum of all node values whose grandparent (the parent's parent) has an even value. The tree can contain up to 10,000 nodes with values between 1 and 100. If no nodes have even-valued grandparents, return 0.

## Approach

The solution uses depth-first search with two boolean flags to track ancestor parity. The `dfs` function accepts three parameters: the current node, a boolean `p` indicating whether the parent has an even value, and a boolean `gp` indicating whether the grandparent has an even value.

When visiting a node, if `gp` is true (meaning the grandparent was even), the node's value is added to the running sum. Then the function recursively processes both children, updating the flags: the current node's parity becomes the new parent flag, and the old parent flag becomes the new grandparent flag.

The implementation propagates parity information down the tree by checking if the current node's value is even (`root->val % 2 == 0`), then passing the appropriate boolean values to child calls. The four conditional branches handle all combinations of current node parity and parent parity, ensuring the grandparent flag is correctly set for descendants.

## Complexity

- **Time:** O(n)
- **Space:** O(h)

## Stats

- Submitted: 2024-07-30 20:35 UTC
- Runtime: 33 ms
- Memory: 40 MB
- Language: C++
