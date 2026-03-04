# Flipping an Image

**Difficulty:** Easy
**Tags:** array, matrix, two-pointers, simulation

## Problem

Given a square binary matrix, perform two operations: first reverse each row (flip horizontally), then toggle all bits (invert 0s to 1s and 1s to 0s). The matrix size ranges from 1×1 to 20×20, and all values are strictly 0 or 1.

## Approach

The solution performs the two transformations in sequence using separate loops. First, it iterates through each row and applies the C++ `reverse` function to reverse the elements in-place. Then, in a second nested loop iteration, it uses range-based for loops to visit every cell and applies the logical NOT operator (`!c`) to flip each bit. The modified matrix is returned directly since the operations are done in-place on the input array.

## Complexity

- **Time:** O(n²)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-04 11:23 UTC
- Runtime: 0 ms
- Memory: 12.6 MB
- Language: C++
