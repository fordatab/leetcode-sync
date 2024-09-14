# Game of Life

**Difficulty:** Medium
**Tags:** matrix, simulation, bit-manipulation, in-place

## Problem

Given an m×n grid representing a cellular automaton where each cell is alive (1) or dead (0), update the board in-place to its next generation based on neighbor counts. A live cell survives with 2-3 live neighbors; a dead cell becomes alive with exactly 3 live neighbors. All cells must transition simultaneously, so intermediate states cannot affect other cells' calculations.

## Approach

The solution uses bit manipulation to store both current and next states in-place. Each cell value uses two bits: the least significant bit holds the current state, and the second bit (position 1) stores the next state.

For each cell, it counts live neighbors by iterating through the 3×3 grid centered on that cell (clamped to board boundaries), summing the least significant bits (current states) via `b[x][y] & 1`. After subtracting the cell's own contribution, it applies the transition rules: live cells with 2-3 neighbors or dead cells with exactly 3 neighbors get their second bit set via `b[i][j] |= 2`.

After processing all cells, a final pass right-shifts every value by 1 (`c >>= 1`), discarding the old state and moving the next state into the least significant bit position.

## Complexity

- **Time:** O(m × n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-14 02:37 UTC
- Runtime: 4 ms
- Memory: 8.5 MB
- Language: C++
