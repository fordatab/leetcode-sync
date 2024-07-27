# Spiral Matrix III

**Difficulty:** Medium
**Tags:** simulation, matrix, spiral-traversal

## Problem

Given a grid with dimensions rows × cols and a starting position (rStart, cStart), traverse all cells in a clockwise spiral pattern beginning at the start position and facing east. The spiral continues even when moving outside grid boundaries, eventually visiting every cell exactly once. Return the coordinates of all grid cells in the order they are visited.

## Approach

The solution simulates walking in an expanding clockwise spiral from the starting position. It uses direction vectors for the four cardinal directions (right, down, left, up) and cycles through them in order.

The spiral expands by taking an increasing number of steps in each direction. Starting with 1 step, the walker moves right, then down (incrementing step count), then left, then up (incrementing again), forming a square spiral. After every two direction changes, the step count increases.

As the walker moves, it checks whether each position falls within the grid boundaries (0 ≤ row < rows and 0 ≤ col < cols). Only valid positions are added to the result array. The process continues until all rows × cols cells have been collected.

## Complexity

- **Time:** O(max(rows, cols)²)
- **Space:** O(rows × cols)

## Stats

- Submitted: 2024-07-27 03:17 UTC
- Runtime: 10 ms
- Memory: 13.8 MB
- Language: C++
