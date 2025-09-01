# Number of Black Blocks

**Difficulty:** Medium
**Tags:** hash-table, counting, geometry, sparse-matrix

## Problem

Given an m×n grid where specific cells are colored black (all others white), count how many 2×2 blocks contain exactly 0, 1, 2, 3, or 4 black cells. A block is defined by its top-left corner at position (x, y) where x < m-1 and y < n-1, containing the four cells at (x,y), (x+1,y), (x,y+1), and (x+1,y+1). The grid can be very large (up to 10^5 × 10^5) but has at most 10^4 black cells.

## Approach

The solution uses a sparse representation to avoid iterating over all possible blocks in a potentially huge grid.

First, it stores all black cell coordinates in a set for quick lookup. Then, for each black cell, it determines which 2×2 blocks could contain that cell—specifically, the four blocks where this cell could be the top-left, top-right, bottom-left, or bottom-right corner. This is done by trying offsets (i, j) where both i and j range from 0 to 1, computing potential block origins at (x-i, y-j).

For each valid block origin (within bounds), it increments a counter in a map that tracks how many black cells each block contains. After processing all black cells, it iterates through the map to count how many blocks have 1, 2, 3, or 4 black cells.

Finally, it calculates the total number of possible 2×2 blocks as (m-1)×(n-1) and subtracts the count of blocks with at least one black cell to determine how many blocks have zero black cells.

## Complexity

- **Time:** O(k log k)
- **Space:** O(k)

## Stats

- Submitted: 2025-09-01 01:10 UTC
- Runtime: 594 ms
- Memory: 292.5 MB
- Language: C++
