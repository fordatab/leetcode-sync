# Snake in Matrix

**Difficulty:** Easy
**Tags:** simulation, array, matrix

## Problem

Given an n×n grid where each cell has a unique numeric identifier calculated as (row × n) + column, simulate a snake starting at position 0 (top-left corner) and executing a sequence of directional commands (UP, DOWN, LEFT, RIGHT). Return the numeric identifier of the snake's final position. The grid size is at most 10×10, commands are at most 100, and the snake is guaranteed to stay within bounds.

## Approach

The solution tracks the snake's position using two integer variables `x` (column) and `y` (row), both initialized to 0. It iterates through each command string and updates the coordinates accordingly: DOWN increments `y`, UP decrements `y`, RIGHT increments `x`, and LEFT decrements `x`. After processing all commands, it converts the final (x, y) coordinates back to the cell identifier using the formula `y * n + x`, which matches the grid's numbering scheme where each row contains n cells.

## Complexity

- **Time:** O(m)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-11 04:24 UTC
- Runtime: 19 ms
- Memory: 35.2 MB
- Language: C++
