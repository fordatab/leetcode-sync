# Spiral Matrix

**Difficulty:** Medium
**Tags:** matrix, simulation, array

## Problem

Given a 2D matrix with dimensions m×n (where 1 ≤ m, n ≤ 10), traverse it in a clockwise spiral pattern starting from the top-left corner and return all elements in the order visited. The spiral moves right along the top edge, down the right edge, left along the bottom edge, up the left edge, then repeats inward until all elements are collected.

## Approach

The solution uses direction-based simulation with a visited tracker. It maintains four direction vectors representing right, down, left, and up movements in cyclic order. Starting at position (0,0), it iterates exactly m×n times, collecting each element and marking its position as visited in a boolean matrix.

At each step, it attempts to move in the current direction. If the next position would be out of bounds or already visited, it rotates clockwise to the next direction (incrementing the direction index modulo 4) and recalculates the next position. This naturally creates the spiral pattern as boundaries and visited cells force direction changes at the appropriate times.

The algorithm preallocates the output vector to the exact size needed (m×n elements) and fills it sequentially during the traversal, ensuring all elements are collected in spiral order without needing explicit boundary tracking variables.

## Complexity

- **Time:** O(m * n)
- **Space:** O(m * n)

## Stats

- Submitted: 2024-07-27 01:24 UTC
- Runtime: 3 ms
- Memory: 8.7 MB
- Language: C++
