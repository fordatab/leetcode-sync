# Nearest Exit from Entrance in Maze

**Difficulty:** Medium
**Tags:** breadth-first-search, matrix, graph-traversal, shortest-path

## Problem

Given an m×n grid representing a maze with empty cells ('.') and walls ('+'), along with a starting entrance position, find the shortest number of steps to reach any border cell (an exit). An exit must be an empty cell on the boundary of the maze, and the entrance itself doesn't count as a valid exit. The maze dimensions are at most 100×100, and you can move in four cardinal directions without stepping into walls or outside the grid.

## Approach

This solution uses breadth-first search (BFS) to explore the maze level by level from the entrance. It maintains a queue of cells to visit and a 2D boolean array to track which cells have already been visited. At each level of the BFS (representing a specific distance from the entrance), it processes all cells at that distance, exploring their four neighboring cells. For each unvisited empty cell, it checks whether the cell is on the border (row 0, column 0, row m-1, or column n-1); if so, it immediately returns the current level as the shortest path length. The entrance cell is marked as visited initially to prevent returning to it. If the BFS completes without finding a border cell, the function returns -1 to indicate no exit is reachable.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-08-08 00:01 UTC
- Runtime: 301 ms
- Memory: 34.8 MB
- Language: C++
