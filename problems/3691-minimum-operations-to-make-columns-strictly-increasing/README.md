# Minimum Operations to Make Columns Strictly Increasing

**Difficulty:** Easy
**Tags:** matrix, greedy, simulation

## Problem

Given an m×n matrix of non-negative integers, determine the minimum number of increment operations needed to make every column strictly increasing from top to bottom. Each operation increases any cell value by 1. The matrix dimensions are at most 50×50, and cell values are initially less than 2500.

## Approach

The solution processes each column independently from left to right. For each column, it scans from the second row downward, checking if each cell is strictly greater than the cell above it. When a cell is less than or equal to the one above, the algorithm calculates how many increments are needed to make it exactly one greater than its predecessor, adds this count to the total operations, and updates the cell value in-place. This greedy approach ensures each column becomes strictly increasing with the minimum modifications, since making a cell just one more than the previous value is optimal.

## Complexity

- **Time:** O(m × n)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-04 10:43 UTC
- Runtime: 3 ms
- Memory: 28 MB
- Language: C++
