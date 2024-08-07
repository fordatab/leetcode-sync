# Pacific Atlantic Water Flow

**Difficulty:** Medium
**Tags:** breadth-first-search, matrix, graph-traversal, brute-force

## Problem

Given an m×n grid of heights representing an island bordered by the Pacific Ocean (top and left edges) and Atlantic Ocean (bottom and right edges), find all cells from which water can flow to both oceans. Water flows from a cell to neighboring cells (north, south, east, west) only if the neighbor's height is less than or equal to the current cell's height. The grid dimensions can be up to 200×200, and heights range from 0 to 10^5.

## Approach

The solution performs a brute-force search from every cell in the grid. For each starting position (x, y), it runs a breadth-first search (BFS) that explores all reachable cells following the water flow rules (can move to neighbors with equal or lower height). During the BFS, it tracks whether the search reaches the Pacific Ocean (by going out of bounds at the top or left, i.e., negative coordinates) or the Atlantic Ocean (by going out of bounds at the bottom or right, i.e., coordinates equal to m or n). A visited set prevents revisiting cells within each BFS. If a single BFS from a starting cell reaches both ocean boundaries, that cell is added to the result. This approach checks all m×n cells independently, performing a potentially full grid traversal for each one.

## Complexity

- **Time:** O(m^2 * n^2)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-08-07 03:39 UTC
- Runtime: 985 ms
- Memory: 403.3 MB
- Language: C++
