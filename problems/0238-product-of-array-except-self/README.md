# Product of Array Except Self

**Difficulty:** Medium
**Tags:** array, prefix-sum, prefix-product

## Problem

Given an array of integers, construct a result array where each position contains the product of all elements in the original array except the one at that position. The solution must run in linear time without using division, and all intermediate products are guaranteed to fit in 32-bit integers. The array has between 2 and 100,000 elements with values ranging from -30 to 30.

## Approach

The solution uses two auxiliary arrays to store prefix and suffix products. The `forwards` array (size n+2) accumulates products from left to right, where `forwards[i]` contains the product of all elements before index `i-1` in the original array. The `backwards` array (size n+2) accumulates products from right to left, where `backwards[i]` contains the product of all elements after index `i-1`. Both arrays are padded with boundary values of 1 to simplify indexing.

The algorithm first fills `forwards` by iterating left to right, multiplying each element with the previous accumulated product. Then it fills `backwards` by iterating right to left in a similar fashion. Finally, for each position `x` in the output array, it multiplies `forwards[x]` (product of all elements to the left) with `backwards[x+2]` (product of all elements to the right), yielding the product of everything except `nums[x]`.

The code includes debug print statements that output the contents of both auxiliary arrays during execution.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-06-28 00:50 UTC
- Runtime: 131 ms
- Memory: 40.1 MB
- Language: C++
