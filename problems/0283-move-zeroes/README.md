# Move Zeroes

**Difficulty:** Easy
**Tags:** two-pointers, array, in-place

## Problem

Given an integer array of up to 10,000 elements with values in the 32-bit signed integer range, rearrange it in-place so that all zero values appear at the end while preserving the original order of non-zero elements. The solution must modify the array directly without using extra space for a copy.

## Approach

The solution uses a two-pointer technique with a single pass through the array. It maintains a counter `l` that tracks how many zeros have been encountered so far. When iterating through the array with index `x`, if the current element is zero, the counter increments. If the element is non-zero, the algorithm stores its value in a temporary variable, sets the current position to zero, then places the non-zero value at position `x-l` (shifting it left by the number of zeros seen). This effectively moves non-zero elements to earlier positions while leaving zeros in their wake, which naturally accumulate at the end.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-11 03:42 UTC
- Runtime: 14 ms
- Memory: 21.6 MB
- Language: C++
