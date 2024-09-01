# Construct Quad Tree

**Difficulty:** Medium
**Tags:** divide-and-conquer, recursion, quad-tree, matrix

## Problem

Given an n×n binary matrix (containing only 0s and 1s) where n is a power of 2, build a quad-tree representation. Each node in the quad-tree is either a leaf (representing a uniform region of all 0s or all 1s) or an internal node with exactly four children (topLeft, topRight, bottomLeft, bottomRight) representing a region with mixed values. The matrix dimensions range from 1×1 to 64×64.

## Approach

The solution uses recursive divide-and-conquer to build the quad-tree top-down. Starting with the entire grid, it creates a root node and calls a depth-first helper function.

For each subregion, the helper first checks if all cells in the current region share the same value by scanning the entire block. If the region is uniform (or has size 1), it marks the current node as a leaf with the appropriate value and returns.

If the region contains mixed values, it marks the node as non-leaf and recursively constructs four child nodes, each representing one quadrant of the current region. The region is divided by halving the size: topLeft covers [i, i+nsz) × [j, j+nsz), topRight covers [i, i+nsz) × [j+nsz, j+sz), bottomLeft covers [i+nsz, i+sz) × [j, j+nsz), and bottomRight covers [i+nsz, i+sz) × [j+nsz, j+sz).

## Complexity

- **Time:** O(n^2 log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-09-01 06:41 UTC
- Runtime: 5 ms
- Memory: 17.2 MB
- Language: C++
