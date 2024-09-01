# Convert 1D Array Into 2D Array

**Difficulty:** Easy
**Tags:** array, matrix, simulation

## Problem

Given a 1D array and two integers m and n, reshape the array into a 2D array with m rows and n columns, filling elements row by row in sequential order. If the total number of elements doesn't equal m × n, return an empty array instead.

## Approach

The solution first validates that the input array length equals m × n; if not, it returns an empty vector. It then pre-allocates a 2D vector of size m × n. The core logic iterates through each element of the original array using a single index x, and maps it to the 2D array using division and modulo operations: `x / n` determines the row index, and `x % n` determines the column index. This effectively distributes consecutive elements across rows, filling each row completely before moving to the next.

## Complexity

- **Time:** O(m × n)
- **Space:** O(m × n)

## Stats

- Submitted: 2024-09-01 00:16 UTC
- Runtime: 75 ms
- Memory: 88 MB
- Language: C++
