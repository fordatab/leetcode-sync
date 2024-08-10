# Redundant Connection

**Difficulty:** Medium
**Tags:** union-find, graph, disjoint-set, cycle-detection

## Problem

Given an undirected graph with n nodes (labeled 1 to n) that was originally a tree but has one extra edge added, identify which edge to remove to restore the tree property. The input is an array of n edges, where each edge connects two distinct nodes. If multiple edges could be removed, return the one that appears last in the input array. Constraints include 3 ≤ n ≤ 1000, and the graph is guaranteed to be connected.

## Approach

This solution uses a **Union-Find (Disjoint Set Union)** data structure with path compression and union by rank to detect the redundant edge.

The algorithm initializes each node as its own parent in a `parents` array and tracks component sizes in a `ranks` array. It then processes edges sequentially, attempting to union the two nodes of each edge.

For each edge, it finds the root parent of both nodes using `doFind`, which implements path compression by making each node point directly to its grandparent during traversal. If both nodes already share the same root parent, they're in the same connected component, meaning this edge would create a cycle — this is the redundant edge.

The `doUnion` function merges two components by making the root of the smaller-ranked component point to the root of the larger-ranked component, updating ranks accordingly. This rank-based union keeps the tree relatively flat for efficient future lookups.

The first edge that fails to union (returns false because both endpoints are already connected) is returned as the answer, which by the problem's constraint will be the last redundant edge in the input.

## Complexity

- **Time:** O(n α(n))
- **Space:** O(n)

## Stats

- Submitted: 2024-08-10 01:33 UTC
- Runtime: 3 ms
- Memory: 12.1 MB
- Language: C++
