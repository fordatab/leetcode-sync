# Kth Smallest Element in a Sorted Matrix

**Difficulty:** Medium
**Tags:** heap, priority-queue, matrix, k-way-merge

## Problem

Given an n×n matrix where rows and columns are individually sorted in ascending order, find the kth smallest element overall when considering all n² elements in sorted order. The matrix dimensions range from 1×1 to 300×300, element values span from -10⁹ to 10⁹, and the solution must use less than O(n²) space.

## Approach

This solution uses a min-heap to perform a k-way merge across the matrix rows. It initializes the heap with the first element from each of the first min(n, k) rows, storing row-column index pairs. The heap orders elements by their actual matrix values using a custom comparator.

The algorithm repeatedly extracts the minimum element from the heap (k-1 times), and each time an element at position (i, j) is popped, it pushes the next element in that same row (i, j+1) if it exists. This ensures we only explore the necessary elements in sorted order.

After k-1 extractions, the top of the heap contains the kth smallest element's position. By only maintaining at most n elements in the heap at any time and not materializing all n² elements, the solution achieves the required sub-quadratic space complexity.

## Complexity

- **Time:** O(k log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-12 05:40 UTC
- Runtime: 38 ms
- Memory: 16.9 MB
- Language: C++
