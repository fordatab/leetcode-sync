# Count Alternating Subarrays

**Difficulty:** Medium
**Tags:** array, sliding-window, two-pointers, counting

## Problem

Given a binary array, count all subarrays where no two adjacent elements have the same value. A subarray is alternating if each element differs from its immediate neighbors within that subarray. The array can have up to 100,000 elements.

## Approach

The solution uses a sliding window approach with two pointers. It maintains a left pointer `l` that marks the start of the current alternating sequence, and iterates through the array with a right pointer `r`. For each position, it checks if the current element equals the previous element — if so, it resets the left pointer to the current position, effectively starting a new alternating sequence. Otherwise, the alternating sequence continues. At each step, it adds `(r - l + 1)` to the count, which represents the number of alternating subarrays ending at position `r` (all subarrays from any index between `l` and `r` to `r` are alternating). This incrementally counts all valid subarrays in a single pass through the array.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2025-09-02 03:04 UTC
- Runtime: 0 ms
- Memory: 118 MB
- Language: C++
