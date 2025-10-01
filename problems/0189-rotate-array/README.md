# Rotate Array

**Difficulty:** Medium
**Tags:** array, two-pointers, in-place, reversal

## Problem

Given an array of integers and a non-negative rotation count k, shift all elements k positions to the right in a circular manner (elements that fall off the end wrap around to the beginning). The array can contain up to 100,000 elements, and k can be as large as 100,000, meaning it may exceed the array length and require modulo handling.

## Approach

This solution uses the three-reversal technique to achieve in-place rotation. First, it normalizes k by taking the modulo with the array size to handle cases where k exceeds the length. The algorithm then performs three consecutive reversals:

1. Reverse the entire array, which moves the last k elements to the front (but in reversed order)
2. Reverse just the first k elements to restore their correct order
3. Reverse the remaining n-k elements to restore their correct order

The `reverse` helper function swaps elements from both ends moving inward using two pointers. This approach avoids allocating extra space and modifies the array in-place using only a single temporary variable for swapping.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2025-10-01 09:57 UTC
- Runtime: 0 ms
- Memory: 26.6 MB
- Language: C
