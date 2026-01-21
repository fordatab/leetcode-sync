# Shortest Distance from All Buildings

**Difficulty:** Hard
**Tags:** breadth-first-search, matrix, grid-traversal, multi-source-bfs

## Problem

Given an m×n grid where cells contain 0 (empty land), 1 (building), or 2 (obstacle), find an empty land cell that minimizes the sum of Manhattan distances to all buildings. Movement is restricted to four cardinal directions, and you cannot pass through buildings or obstacles. Return the minimum total distance, or -1 if no valid location exists.

## Approach

The solution performs BFS from each building to compute distance information for all reachable empty cells. For each building (cell with value 1), a separate BFS traversal explores all connected empty cells (value 0) in a level-by-level manner, tracking distances using a local `di` array. Two global matrices are maintained: `total` accumulates the sum of distances from all buildings to each empty cell, and `reach` counts how many buildings can reach each empty cell. After all BFS traversals complete, the algorithm scans the grid for empty cells where `reach[x][y]` equals the total building count, meaning all buildings can reach that cell, and selects the cell with minimum `total[x][y]`.

## Complexity

- **Time:** O(m²n²)
- **Space:** O(mn)

## Stats

- Submitted: 2026-01-21 23:08 UTC
- Runtime: 439 ms
- Memory: 141.4 MB
- Language: C++
