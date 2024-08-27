# Path with Maximum Probability

**Difficulty:** Medium
**Tags:** graph, dijkstra, shortest-path, priority-queue, greedy

## Problem

Given an undirected weighted graph with n nodes where each edge has an associated probability of successful traversal, find the path from a start node to an end node that maximizes the product of probabilities along the path. The graph can have up to 10^4 nodes and 2×10^4 edges, with probabilities between 0 and 1. Return 0 if no path exists.

## Approach

The solution uses a modified Dijkstra's algorithm adapted for maximizing probability products instead of minimizing distances. It builds an adjacency list representation of the undirected graph, storing each neighbor with its edge probability. A max-heap priority queue tracks nodes by their current maximum probability from the start node.

The algorithm initializes the start node with probability 1.0 and processes nodes in decreasing order of probability. For each unvisited node popped from the queue, it marks the node as seen and examines all neighbors. If multiplying the current node's probability by an edge's probability yields a better path to a neighbor than previously found, it updates that neighbor's maximum probability and adds it to the queue.

The `mx` array maintains the best probability found so far to reach each node, and the `seen` array ensures each node is processed only once. The algorithm terminates when the queue is empty, and returns the maximum probability stored for the end node (which remains 0.0 if unreachable).

## Complexity

- **Time:** O((V + E) log V)
- **Space:** O(V + E)

## Stats

- Submitted: 2024-08-27 23:32 UTC
- Runtime: 123 ms
- Memory: 70.4 MB
- Language: C++
