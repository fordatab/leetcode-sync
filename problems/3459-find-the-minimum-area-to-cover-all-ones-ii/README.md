# Find the Minimum Area to Cover All Ones II

**Difficulty:** Hard
**Tags:** grid, enumeration, geometry, partitioning, bounding-box

## Problem

Given a 2D binary grid, partition all 1s into exactly three non-overlapping rectangles with positive areas. The rectangles must have horizontal and vertical sides, can touch but not overlap, and must collectively cover all 1s in the grid. Return the minimum possible sum of the three rectangle areas. The grid dimensions are at most 30×30, and at least three 1s are guaranteed to exist.

## Approach

The solution exhaustively tries different ways to partition the grid into three rectangular regions, then computes the minimal bounding rectangle for 1s in each region.

**Core helper function**: `minimumSum(grid, u, d, l, r)` finds the smallest rectangle containing all 1s within bounds `[u,d] × [l,r]` by tracking min/max row and column indices of 1s, then computing area as `(height) × (width)`. Returns a large value if no 1s exist in the region.

**Partitioning strategy**: The `solve` function considers two main partition patterns:
1. **L-shaped splits**: Horizontal cut at row `i` creates a top rectangle, then vertical cut at column `j` splits the bottom into left and right rectangles (two configurations).
2. **Three horizontal strips**: Two horizontal cuts at rows `i` and `j` create three stacked rectangles.

**Rotation trick**: Since vertical splits (three side-by-side rectangles) mirror horizontal splits when the grid is rotated 90°, the main `minimumSum` function calls `solve` on both the original grid and its 90° rotation, taking the minimum result. This handles all six fundamental partitioning patterns (2 L-shapes × 2 orientations + 2 strip orientations) without duplicating code.

## Complexity

- **Time:** O(n² × m²)
- **Space:** O(n × m)

## Stats

- Submitted: 2026-01-28 06:24 UTC
- Runtime: 90 ms
- Memory: 26.1 MB
- Language: C++
