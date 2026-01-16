# Maximum Number of K-Divisible Components

**Difficulty:** Hard
**Tags:** tree, depth-first-search, graph, greedy, modular-arithmetic

## Problem

Given an undirected tree with n nodes where each node has an associated value, determine the maximum number of components that can be created by removing edges such that each resulting component's sum of node values is divisible by k. The tree has n-1 edges, node values can be up to 10^9, and the total sum of all values is guaranteed to be divisible by k.

## Approach

The solution uses a depth-first search (DFS) to traverse the tree and greedily split components wherever possible.

**Building the adjacency list:** First, construct an undirected graph representation using an adjacency list from the given edges.

**DFS traversal:** Starting from node 0, perform DFS while tracking visited nodes. For each node, compute the sum of values in its subtree modulo k by recursively processing all unvisited neighbors.

**Greedy splitting:** At each node, calculate the remainder when the subtree sum (including the node's own value) is divided by k. If this remainder is 0, the subtree can be separated as an independent component—increment the component counter and return 0 to the parent (effectively cutting the edge). Otherwise, propagate the remainder up to the parent node.

**Key insight:** Since the total sum is divisible by k, any subtree with sum divisible by k can be split off, and the remaining tree will also have a sum divisible by k. The greedy approach of splitting whenever possible maximizes the component count.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-16 03:55 UTC
- Runtime: 163 ms
- Memory: 187.2 MB
- Language: C++
