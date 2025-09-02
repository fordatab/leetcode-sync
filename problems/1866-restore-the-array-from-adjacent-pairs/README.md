# Restore the Array From Adjacent Pairs

**Difficulty:** Medium
**Tags:** graph, depth-first-search, hash-table, adjacency-list

## Problem

Given a list of adjacent pairs from an unknown array of unique integers, reconstruct the original array. The input contains n-1 pairs representing consecutive elements, but the pairs can appear in any order and in either direction. The array has between 2 and 100,000 elements with values ranging from -100,000 to 100,000.

## Approach

The solution treats the problem as reconstructing a path in an undirected graph. It builds an adjacency list representation where each number points to its neighbors (adjacent elements). The key insight is that the endpoints of the original array have exactly one neighbor, while all middle elements have exactly two neighbors.

The algorithm first constructs the adjacency list by processing each pair bidirectionally, adding edges in both directions. It then identifies a starting point by finding any number that appears in only one pair (has degree 1 in the graph).

Finally, it performs a depth-first search (DFS) starting from this endpoint, using a visited map to avoid revisiting nodes. Since each internal node has exactly two neighbors and we mark nodes as visited, the DFS naturally follows the linear chain from one end to the other, building the result array in order.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-09-02 03:28 UTC
- Runtime: 407 ms
- Memory: 148.6 MB
- Language: C++
