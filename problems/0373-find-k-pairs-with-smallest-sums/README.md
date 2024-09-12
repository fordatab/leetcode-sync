# Find K Pairs with Smallest Sums

**Difficulty:** Medium
**Tags:** heap, priority-queue, two-pointers, greedy

## Problem

Given two sorted arrays and an integer k, find the k pairs (one element from each array) that have the smallest sums. The arrays can contain up to 10^5 elements each with values ranging from -10^9 to 10^9, and k is guaranteed to be at most the product of the array lengths and at most 10^4.

## Approach

The solution uses a min-heap (priority queue) to efficiently extract pairs in order of increasing sum. It starts by pushing the pair of indices (0, 0) into the heap. At each iteration, it extracts the pair with the minimum sum from the heap and adds the corresponding values to the result.

After extracting a pair at indices (i, j), the solution considers two potential next pairs: (i, j+1) to advance in the second array, and (i+1, 0) but only when j equals 0 to avoid duplicates. This careful insertion strategy ensures that each pair of indices is added to the heap at most once.

The key insight is that because both arrays are sorted, if (i, j) has been processed, the next smallest sums involving index i will be (i, j+1), and new candidates from the first array are introduced only at the start of the second array. The custom comparator orders pairs by their sum in ascending order, ensuring the heap always provides the next smallest pair.

## Complexity

- **Time:** O(k log k)
- **Space:** O(k)

## Stats

- Submitted: 2024-09-12 02:56 UTC
- Runtime: 144 ms
- Memory: 131 MB
- Language: C++
