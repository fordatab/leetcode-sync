# Rotate Array

**Difficulty:** Medium
**Tags:** array, two-pointers, in-place, reversal

## Problem

Given an array of integers and a non-negative integer k, shift all elements k positions to the right, wrapping elements that fall off the end back to the beginning. The array can have up to 10^5 elements, and k can be larger than the array length, requiring modular arithmetic to handle wraparound.

## Approach

This solution uses the **reverse algorithm** to achieve in-place rotation with three reversal operations:

1. First, it normalizes k using modulo to handle cases where k exceeds the array length.

2. The entire array is reversed, which moves the last k elements to the front (though in reversed order).

3. The first k elements are reversed to restore their original relative order.

4. The remaining elements (from index k to the end) are reversed to restore their original relative order.

For example, rotating [1,2,3,4,5,6,7] by k=3: reverse all → [7,6,5,4,3,2,1], reverse first 3 → [5,6,7,4,3,2,1], reverse last 4 → [5,6,7,1,2,3,4]. This approach modifies the array in-place without requiring extra storage proportional to the input size.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-03 22:13 UTC
- Runtime: 25 ms
- Memory: 27.4 MB
- Language: C++
