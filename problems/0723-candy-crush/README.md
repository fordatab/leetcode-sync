# Candy Crush

**Difficulty:** Medium
**Tags:** simulation, matrix, two-pointers, hash-table

## Problem

Given a 2D grid representing candy types (where 0 means empty), simulate a Candy Crush-style elimination game until the board stabilizes. In each iteration, identify and remove all candies that form runs of 3 or more identical values horizontally or vertically, then apply gravity to drop remaining candies downward. Repeat this process until no more eliminations are possible. The board dimensions are at most 50×50, and candy values range from 1 to 2000.

## Approach

The solution uses an iterative simulation approach with three phases per cycle:

**Marking Phase**: Scan the entire board to find all positions that belong to runs of 3+ identical candies. For each non-zero cell, extend in both the vertical (downward) and horizontal (rightward) directions to find consecutive matching candies. If a run of 3+ is found in either direction, mark all positions in that run using a map.

**Gravity Phase**: Process each column independently from bottom to top. Use a two-pointer technique where `write` starts at the bottom row and moves upward. For each position from bottom to top, if it's not marked for crushing, copy its value to the `write` position and decrement `write`. After processing all rows, fill any remaining positions above `write` with zeros.

**Termination**: If no positions were marked for crushing in an iteration, the board is stable and returned. Otherwise, repeat the cycle. The outer loop continues until `marked` is empty, indicating no more eliminations are possible.

## Complexity

- **Time:** O(k × m × n × (m + n))
- **Space:** O(m × n)

## Stats

- Submitted: 2025-09-05 10:51 UTC
- Runtime: 78 ms
- Memory: 32 MB
- Language: C++
