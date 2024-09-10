# Island Perimeter

**Difficulty:** Easy
**Tags:** depth-first-search, grid-traversal, matrix

## Problem

Given a rectangular grid where cells contain either 1 (land) or 0 (water), find the perimeter of the single island formed by connected land cells. The grid dimensions are at most 100×100, cells connect only horizontally or vertically, and the island is guaranteed to exist with no internal water bodies.

## Approach

The solution uses depth-first search (DFS) to traverse the island. It scans the grid to find the first land cell, then initiates a DFS from that position. During the traversal, each visited land cell is marked as -1 to avoid revisiting. For each land cell encountered, the code counts how many of its four sides are exposed (either bordering water, already-visited cells that appear as water in the check, or grid boundaries). These exposed sides are accumulated into a running perimeter total. The DFS recursively visits all four adjacent cells, ensuring every land cell in the island is processed exactly once.

## Complexity

- **Time:** O(m × n)
- **Space:** O(m × n)

## Stats

- Submitted: 2024-09-10 03:03 UTC
- Runtime: 49 ms
- Memory: 103.2 MB
- Language: C++
