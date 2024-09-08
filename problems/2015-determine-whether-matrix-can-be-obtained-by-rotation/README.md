# Determine Whether Matrix Can Be Obtained By Rotation

**Difficulty:** Easy
**Tags:** matrix, simulation, array-manipulation

## Problem

Given two n×n binary matrices (containing only 0s and 1s), determine if one matrix can be transformed into the other through 0, 1, 2, or 3 clockwise 90-degree rotations. The matrices are small, with n constrained to at most 10.

## Approach

The solution checks all four possible rotation states of the source matrix against the target. It uses an in-place rotation helper function that performs a 90-degree clockwise rotation by first reversing the rows of the matrix (top to bottom), then transposing it (swapping elements across the main diagonal). The main function compares the original matrix with the target, then repeatedly rotates the matrix 90 degrees and checks for equality after each rotation, covering all four possible orientations (0°, 90°, 180°, 270°). If any of these four states matches the target, it returns true; otherwise, it returns false.

## Complexity

- **Time:** O(n²)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-08 06:06 UTC
- Runtime: 4 ms
- Memory: 14 MB
- Language: C++
