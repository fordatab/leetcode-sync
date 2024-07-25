# Sort an Array

**Difficulty:** Medium
**Tags:** heap, priority-queue, sorting

## Problem

Given an array of integers with up to 50,000 elements (values ranging from -50,000 to 50,000), sort it in ascending order. The solution must avoid built-in sorting functions, achieve O(n log n) time complexity, and minimize space usage.

## Approach

The solution uses a min-heap (priority queue) to sort the array. It constructs the heap by initializing a `priority_queue` with `greater<int>` comparator using all elements from the input array, which takes O(n) time through heapify. Then it repeatedly extracts the minimum element (the root of the min-heap) and places it back into the original array positions from left to right. Each extraction and heap adjustment takes O(log n) time, and this is done n times. While this achieves the required O(n log n) time complexity, it uses O(n) additional space for the heap structure, which is not the most space-efficient approach possible.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-25 00:49 UTC
- Runtime: 144 ms
- Memory: 72.7 MB
- Language: C++
