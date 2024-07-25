# Maximum Subsequence Score

**Difficulty:** Medium
**Tags:** sorting, greedy, heap, priority-queue, two-pointers

## Problem

Given two equal-length integer arrays nums1 and nums2 and an integer k, select k indices to maximize a score defined as the sum of selected nums1 elements multiplied by the minimum of the corresponding nums2 elements. The arrays can have up to 10^5 elements, and values range from 0 to 10^5.

## Approach

The solution pairs elements from both arrays and sorts them by nums2 values in descending order. It then iterates through the sorted pairs, maintaining a min-heap of size k to track the k largest nums1 values seen so far.

As we process each pair, the current nums2 value becomes a candidate for the minimum multiplier. We add the corresponding nums1 value to our running sum and push it onto the min-heap. If the heap exceeds size k, we remove the smallest nums1 value to maintain exactly k elements.

By processing nums2 in descending order, when we have exactly k elements in the heap, the current nums2 value is guaranteed to be the minimum among those k selected indices. We calculate the score (sum of k nums1 values × current nums2 value) and track the maximum across all valid configurations.

The key insight is that by fixing the minimum nums2 value through sorted iteration, we can greedily select the k largest nums1 values available up to that point, ensuring we evaluate all meaningful combinations efficiently.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-25 09:39 UTC
- Runtime: 174 ms
- Memory: 94.7 MB
- Language: C++
