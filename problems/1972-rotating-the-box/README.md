# Rotating the Box

**Difficulty:** Medium
**Tags:** matrix, simulation, array-manipulation, gravity-simulation

## Problem

Given an m×n grid representing a side-view box containing stones ('#'), stationary obstacles ('*'), and empty spaces ('.'), rotate the box 90 degrees clockwise and simulate gravity pulling stones downward. Stones fall until they hit an obstacle, another stone, or the bottom edge. The result is an n×m matrix showing the final configuration after rotation and gravity application. Constraints allow grids up to 500×500.

## Approach

The solution uses a two-phase approach:

1. **Rotation Phase**: First, the code performs a 90-degree clockwise rotation by creating a new n×m result matrix and mapping each element from position (i,j) in the original matrix to position (j, m-1-i) in the rotated matrix.

2. **Gravity Simulation Phase**: After rotation, the code processes each column of the rotated matrix from top to bottom. For each column, it counts stones ('#') encountered and temporarily replaces them with empty spaces. When an obstacle ('*') is found or the bottom of the column is reached, it places the accumulated stone count back into the column, filling positions upward from just above the obstacle or from the bottom edge.

The key insight is separating the geometric transformation from the physics simulation, making each step straightforward. The gravity simulation works by tracking stone counts in segments between obstacles and repositioning them at segment ends.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2025-09-01 00:12 UTC
- Runtime: 2374 ms
- Memory: 56.8 MB
- Language: C++
