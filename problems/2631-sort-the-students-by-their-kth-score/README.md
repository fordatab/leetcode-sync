# Sort the Students by Their Kth Score

**Difficulty:** Medium
**Tags:** sorting, array, matrix

## Problem

Given an m×n matrix where each row represents a student's scores across n exams, reorder the rows so that students are sorted by their score in the kth exam (0-indexed) in descending order. All scores in the matrix are distinct integers between 1 and 10^5, with up to 250 students and 250 exams.

## Approach

The solution creates a vector of pairs that stores each student's kth exam score alongside their original row index. It iterates through all rows, extracting the score at column k and pairing it with the row number. After collecting all pairs, it sorts them in descending order using reverse iterators. Finally, it constructs the output matrix by iterating through the sorted pairs and appending the corresponding original rows (accessed via the stored indices) to a new result vector. This approach separates the sorting key extraction from the actual row reordering.

## Complexity

- **Time:** O(m log m)
- **Space:** O(m)

## Stats

- Submitted: 2024-07-26 01:20 UTC
- Runtime: 43 ms
- Memory: 30.9 MB
- Language: C++
