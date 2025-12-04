# Most Profitable Path in a Tree

**Difficulty:** Medium
**Tags:** tree, depth-first-search, graph, backtracking

## Problem

Given an undirected tree of n nodes rooted at node 0, Alice starts at node 0 and moves toward any leaf, while Bob starts at a given node and moves toward node 0. Each node has a gate with an associated cost (negative amount) or reward (positive amount). At each step, both players move simultaneously to adjacent nodes. If they reach a node at the same time, they split the gate's amount; otherwise, the first to arrive claims the full amount (subsequent arrivals get nothing). The goal is to find the maximum net income Alice can achieve by choosing an optimal path to a leaf.

## Approach

The solution uses two separate depth-first searches to solve the problem.

First, it builds an adjacency list representation of the tree from the edge list. Then it runs a DFS starting from Bob's initial position to find the unique path Bob takes to reach node 0. During this DFS, it records the time step at which Bob arrives at each node along his path by setting `bobTime[node] = time`. Nodes not on Bob's path remain at `INT_MAX`. The DFS backtracks by resetting `bobTime` to `INT_MAX` for nodes not on the final path to node 0.

Next, it performs a second DFS starting from Alice's position (node 0) to explore all possible paths to leaf nodes. For each node Alice visits, it calculates the score contribution: if Alice arrives before Bob (`time < bobTime[curr]`), she gets the full amount; if they arrive simultaneously (`time == bobTime[curr]`), she gets half; if Alice arrives after Bob, she gets nothing. The DFS tracks whether each node is a leaf by checking if all neighbors have been visited. When a leaf is reached, it updates the global maximum score.

The algorithm returns the maximum score found across all possible paths from node 0 to any leaf node.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-12-04 10:40 UTC
- Runtime: 88 ms
- Memory: 150.6 MB
- Language: C++
