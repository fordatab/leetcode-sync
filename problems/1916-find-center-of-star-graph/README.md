# Find Center of Star Graph

**Difficulty:** Easy
**Tags:** graph, array

## Problem

Given an undirected star graph with n nodes (labeled 1 to n) represented as an edge list, find the center node. A star graph has one center node connected to all other nodes via exactly n-1 edges. The input is guaranteed to be a valid star graph with 3 ≤ n ≤ 10^5.

## Approach

The solution exploits the fact that in a star graph, the center node must appear in every edge. Since we're guaranteed a valid star graph, we only need to examine the first two edges. The center node is the only node that appears in both edges.

The code compares the two endpoints of the first edge (e[0][0] and e[0][1]) against both endpoints of the second edge (e[1][0] and e[1][1]). If e[0][0] matches either endpoint of the second edge, it's the center; otherwise, e[0][1] must be the center.

This works because the center connects to all n-1 other nodes, so it must appear in at least two edges, while non-center nodes appear in exactly one edge each.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-11 08:32 UTC
- Runtime: 131 ms
- Memory: 71.1 MB
- Language: C++
