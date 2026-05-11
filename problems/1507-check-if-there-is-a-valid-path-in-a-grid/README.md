# Check if There is a Valid Path in a Grid

**Difficulty:** Medium
**Tags:** union-find, graph, grid, connectivity

## Problem

Given an m×n grid where each cell contains a value (1-6) representing a street segment with specific directional connections (e.g., 1 connects left-right, 2 connects top-bottom, 3 connects left-bottom, etc.), determine whether a valid path exists from the top-left corner (0,0) to the bottom-right corner (m-1, n-1). A path is valid only if adjacent cells have compatible street connections that physically link to each other. Grid dimensions can be up to 300×300.

## Approach

The solution uses a **Union-Find (Disjoint Set Union)** data structure to determine connectivity between the start and end cells.

First, it predefines a lookup table (`streets`) where each street type (1-6) maps to a 4-element boolean array indicating which directions (top, right, bottom, left) the street connects to. The grid is then traversed cell-by-cell.

For each cell, the code examines all four neighboring directions. If the current cell's street type has an opening in a particular direction AND the neighbor exists within bounds AND the neighbor's street has an opening pointing back (checked via `(b+2)%4` which reverses the direction), then these two cells are connected and should be unioned.

The Union-Find structure maintains connected components using path compression in the `find` operation. After processing all cells and their valid connections, the algorithm checks whether the top-left cell (index 0) and bottom-right cell (index m×n-1) belong to the same connected component, which indicates a valid path exists.

## Complexity

- **Time:** O(m * n * α(m * n))
- **Space:** O(m * n)

## Stats

- Submitted: 2026-05-11 20:46 UTC
- Runtime: 267 ms
- Memory: 103.8 MB
- Language: C++
