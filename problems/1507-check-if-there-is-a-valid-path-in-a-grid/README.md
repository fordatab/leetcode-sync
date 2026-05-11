# Check if There is a Valid Path in a Grid

**Difficulty:** Medium
**Tags:** depth-first-search, graph-traversal, grid, connected-components

## Problem

Given an m×n grid where each cell contains a number 1-6 representing a street segment with specific directional connections (e.g., 1 connects left-right, 2 connects top-bottom, 3 connects left-bottom, etc.), determine if there exists a valid path from the top-left corner (0,0) to the bottom-right corner (m-1, n-1). A valid path must follow the street connections, meaning you can only move from one cell to an adjacent cell if both cells have street segments that connect to each other.

## Approach

The solution uses depth-first search (DFS) to explore all reachable cells from the starting position. It maintains a lookup table `streets` that maps each street type (1-6) to a boolean array indicating which of the four directions (top, right, bottom, left) that street connects to.

For each cell during DFS traversal, the algorithm examines all four neighboring cells. It only proceeds to a neighbor if: (1) the current cell's street has an opening in that direction, (2) the neighbor is within grid bounds, (3) the neighbor's street has an opening pointing back to the current cell (verified by checking the opposite direction using `(b + 2) % 4`), and (4) the neighbor hasn't been visited yet.

The algorithm marks cells as visited in a 2D boolean array to avoid revisiting them. After the DFS completes, it checks whether the bottom-right corner cell was reached during the traversal.

## Complexity

- **Time:** O(m × n)
- **Space:** O(m × n)

## Stats

- Submitted: 2026-05-11 20:32 UTC
- Runtime: 132 ms
- Memory: 86.2 MB
- Language: C++
