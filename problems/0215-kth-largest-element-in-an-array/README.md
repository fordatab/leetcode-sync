# Kth Largest Element in an Array

**Difficulty:** Medium
**Tags:** heap, priority-queue, min-heap

## Problem

Find the kth largest element in an unsorted integer array, where k is guaranteed to be valid (between 1 and the array length). The array can contain up to 100,000 elements with values ranging from -10,000 to 10,000. Duplicate values count separately (not looking for kth distinct element).

## Approach

This solution uses a min-heap (priority queue with greater comparator) initialized with all elements from the input array. The key insight is that by maintaining only the k largest elements in a min-heap, the smallest element in that heap (at the top) will be the kth largest overall.

The algorithm constructs the min-heap from all array elements, then repeatedly removes the smallest element until exactly k elements remain. Since we started with n elements and removed (n-k) smallest ones, the k elements left are the k largest from the original array.

The top of the min-heap at this point is the smallest among these k largest elements, which by definition is the kth largest element in the original array.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-18 08:36 UTC
- Runtime: 101 ms
- Memory: 61.4 MB
- Language: C++
