# Design Neighbor Sum Service

**Difficulty:** Easy
**Tags:** matrix, grid-traversal, simulation, array

## Problem

Given an n×n grid containing distinct integers from 0 to n²-1, implement a class that can compute two types of neighbor sums for any value in the grid: adjacent sum (sum of orthogonal neighbors: up, down, left, right) and diagonal sum (sum of diagonal neighbors: top-left, top-right, bottom-left, bottom-right). The grid size ranges from 3 to 10, and all elements are unique.

## Approach

The solution stores the entire grid in the constructor. For both `adjacentSum` and `diagonalSum`, it performs a linear search through the grid to find the coordinates (i, j) of the target value.

For adjacent neighbors, it uses direction arrays `dx` and `dy` to check all four orthogonal directions (down, right, up, left). For each valid neighboring position within bounds, it adds that cell's value to the sum.

For diagonal neighbors, it creatively combines the orthogonal direction arrays (`dx`, `dy`) with additional offset arrays (`dxz`, `dyz`) to generate diagonal offsets. By adding `dx[f] + dyz[f]` and `dy[f] + dxz[f]`, it produces the four diagonal directions: (1,-1), (0,1), (-1,1), (0,-1) which map to bottom-left, right (invalid), top-right, left (invalid) — though the actual diagonal positions are achieved through the combined offsets. Valid diagonal neighbors within bounds are summed and returned.

## Complexity

- **Time:** O(n²)
- **Space:** O(n²)

## Stats

- Submitted: 2024-08-04 02:43 UTC
- Runtime: 159 ms
- Memory: 70.1 MB
- Language: C++
