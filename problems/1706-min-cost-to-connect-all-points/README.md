# Min Cost to Connect All Points

**Difficulty:** Medium
**Tags:** minimum-spanning-tree, prims-algorithm, priority-queue, graph, greedy

## Problem

Given a collection of 2D coordinate points, find the minimum total Manhattan distance needed to connect all points into a single connected graph. The Manhattan distance between two points is the sum of the absolute differences of their x and y coordinates. The constraint allows up to 1000 points with coordinates ranging from -10^6 to 10^6.

## Approach

The solution uses Prim's algorithm to build a minimum spanning tree. First, it constructs a complete adjacency list representation where every point is connected to every other point with their Manhattan distance as the edge weight. Then it employs a greedy approach using a min-heap (priority queue) starting from point 0. The algorithm repeatedly extracts the edge with minimum cost that connects an unvisited point to the growing MST. It maintains a visited set to track which points have been added to the tree, and for each newly added point, it pushes all edges to unvisited neighbors into the priority queue. The total cost is accumulated as points are added to the MST, and the algorithm terminates when all points are visited.

## Complexity

- **Time:** O(n^2 log n)
- **Space:** O(n^2)

## Stats

- Submitted: 2024-08-11 03:19 UTC
- Runtime: 151 ms
- Memory: 134.9 MB
- Language: C++
