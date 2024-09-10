# Flood Fill

**Difficulty:** Easy
**Tags:** depth-first-search, recursion, matrix, graph-traversal

## Problem

Given an m×n grid of integers representing an image and a starting pixel position (sr, sc), change the color of that pixel and all connected pixels with the same original color to a new target color. Two pixels are connected if they share a horizontal or vertical edge and have matching colors. The grid dimensions can be up to 50×50, and pixel values range from 0 to 2^16-1.

## Approach

The solution uses depth-first search (DFS) to traverse and recolor the connected region. It first stores the original color of the starting pixel and checks if it already matches the target color (in which case no work is needed). The recursive `dfs` function recolors the current pixel, then recursively visits all four cardinal neighbors (up, down, left, right). The base case stops recursion when moving out of bounds or encountering a pixel that doesn't match the original color. This ensures only pixels in the connected component starting from (sr, sc) with the same initial color get recolored, effectively implementing the flood fill algorithm through recursive exploration.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-09-10 03:19 UTC
- Runtime: 2 ms
- Memory: 16.9 MB
- Language: C++
