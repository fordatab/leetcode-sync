# Sort Colors

**Difficulty:** Medium
**Tags:** two-pointers, array, sorting, three-way-partitioning

## Problem

Given an array containing only the values 0, 1, and 2 (representing three colors), rearrange the elements in-place so all 0s come first, followed by all 1s, then all 2s. The array length is between 1 and 300, and the solution must not use a built-in sort function.

## Approach

This solution implements the Dutch National Flag algorithm using three pointers. The `zero` pointer tracks where the next 0 should be placed, `one` serves as the current scanning position, and `two` marks where the next 2 should go from the right end.

The algorithm iterates while `one <= two`, examining each element at position `one`. When a 0 is found (`nums[one] < 1`), it's swapped to the `zero` position and both `zero` and `one` advance. When a 2 is found (`nums[one] > 1`), it's swapped to the `two` position and `two` decrements (but `one` stays put since the swapped element needs inspection). When a 1 is found, `one` simply advances since 1s belong in the middle.

This partitioning approach ensures that after each swap, the invariant holds: all elements before `zero` are 0s, elements between `zero` and `one` are 1s, and elements after `two` are 2s. The algorithm completes in a single pass through the array.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-28 06:56 UTC
- Runtime: 5 ms
- Memory: 10.4 MB
- Language: C++
