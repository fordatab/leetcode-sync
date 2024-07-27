# Spiral Matrix II

**Difficulty:** Medium
**Tags:** matrix, simulation, spiral-traversal, direction-vectors

## Problem

Given a positive integer n (1 ≤ n ≤ 20), construct an n×n matrix where cells are filled with consecutive integers from 1 to n² following a clockwise spiral pattern starting from the top-left corner. The spiral moves right, then down, then left, then up, continuing inward until all cells are populated.

## Approach

The solution uses a **direction-based traversal** with boundary detection. It maintains a matrix initialized to zeros and iterates from 1 to n², placing each number in the current cell. 

Four direction vectors (dx, dy) encode movement: right (0,1), down (1,0), left (0,-1), and up (-1,0). At each step, the code attempts to move in the current direction. If the next position would be out of bounds or already filled (detected by checking if out[ni][nj] is non-zero), it rotates clockwise to the next direction using modulo arithmetic.

The key insight is using the filled cells themselves as markers — since we fill with positive integers starting from 1, any zero cell is unfilled. This eliminates the need for a separate visited array. The spiral naturally completes when all n² numbers have been placed.

## Complexity

- **Time:** O(n²)
- **Space:** O(n²)

## Stats

- Submitted: 2024-07-27 01:36 UTC
- Runtime: 0 ms
- Memory: 8 MB
- Language: C++
