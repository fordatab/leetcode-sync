# Minimum Cost Path with Teleportations

**Difficulty:** Hard
**Tags:** dynamic-programming, sorting, greedy, grid-traversal

## Problem

Given an m×n grid and an integer k, find the minimum cost path from the top-left to bottom-right cell. You can move right or down with a cost equal to the destination cell's value, or teleport to any cell with a value less than or equal to the current cell's value at zero cost (up to k teleportations). The grid dimensions are at most 80×80, cell values range from 0 to 10⁴, and k is at most 10.

## Approach

The solution uses dynamic programming with iterative refinement over k+1 rounds. It preprocesses all grid cells and sorts them by value to enable efficient teleportation logic.

In each round, the algorithm first processes teleportations: for each group of cells with the same value (in sorted order), it finds the minimum cost among all previously visited cells with smaller or equal values and assigns this as the teleportation cost. This leverages the fact that from any cell, you can teleport to any cell with a lower or equal value.

After processing teleportations, it performs a backward sweep from bottom-right to top-left, computing normal movement costs. For each cell, it takes the minimum of its current cost (from teleportation) and the costs of moving down or right plus the respective cell values.

This process repeats k+1 times, allowing each iteration to potentially use one more teleportation than the previous, progressively finding better paths until all k teleportations are utilized.

## Complexity

- **Time:** O(k * m * n * log(m * n))
- **Space:** O(m * n)

## Stats

- Submitted: 2026-01-30 23:27 UTC
- Runtime: 507 ms
- Memory: 130.4 MB
- Language: C++
