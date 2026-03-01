# Longest Mountain in Array

**Difficulty:** Medium
**Tags:** two-pointers, sliding-window, array, greedy

## Problem

Given an array of integers, find the length of the longest contiguous subarray that forms a valid mountain. A mountain must have at least 3 elements, strictly increase to a peak somewhere in the middle (not at the endpoints), and then strictly decrease from that peak. Return 0 if no such subarray exists.

## Approach

The solution uses a two-pointer sliding window approach with a single pass through the array. Starting from the leftmost position, it attempts to identify mountains by:

1. **Ascending phase**: From the current left pointer `l`, advance the right pointer `r` while values are strictly increasing. If no increase occurs (plateau or immediate descent), skip ahead.

2. **Descending phase**: From the peak position, continue advancing `r` while values are strictly decreasing. A flag `down` tracks whether any descent occurred.

3. **Validation**: A valid mountain requires both an ascent (implicit from moving `r` forward in step 1) and a descent (`down == true`). If valid, update the maximum length as `r - l + 1`.

4. **Next iteration**: Move `l` to the current `r` position to search for the next potential mountain, ensuring no overlap and enabling a single-pass solution.

The algorithm handles edge cases like plateaus and arrays with no valid mountains by checking conditions before updating the result.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-01 03:45 UTC
- Runtime: 0 ms
- Memory: 22.2 MB
- Language: C++
