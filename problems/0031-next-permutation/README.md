# Next Permutation

**Difficulty:** Medium
**Tags:** array, two-pointers, greedy, in-place

## Problem

Given an array of integers, rearrange it in-place to produce the next lexicographically larger permutation. If the array is already in descending order (the largest permutation), wrap around to the smallest permutation by sorting it in ascending order. The solution must use only constant extra space and modify the array directly.

## Approach

The algorithm finds the next permutation by identifying the rightmost position where the sequence can be increased. It scans from right to left to find the first element (`nums[i]`) that is smaller than its right neighbor, marking the pivot point. If no such element exists, the array is already the largest permutation, so the entire array is reversed to get the smallest permutation.

Once the pivot is found, the algorithm searches from the right end again to find the smallest element larger than `nums[i]` (call it `nums[j]`). These two elements are swapped, ensuring the position `i` now holds a larger value.

After the swap, all elements to the right of position `i` are in descending order (by the nature of how we found `i`). The final step reverses this suffix to transform it into ascending order, producing the lexicographically smallest arrangement for that tail and thus the next permutation overall.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-04-21 20:27 UTC
- Runtime: 0 ms
- Memory: 15.6 MB
- Language: C++
