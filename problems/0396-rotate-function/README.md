# Rotate Function

**Difficulty:** Medium
**Tags:** math, array, prefix-sum, dynamic-programming

## Problem

Given an integer array of length n, compute a rotation function F(k) for each possible rotation k, where F(k) is the sum of each element multiplied by its index in the k-rotated array. The goal is to find the maximum value among all F(0), F(1), ..., F(n-1). The array can contain negative integers, and n can be up to 100,000.

## Approach

The solution avoids recomputing each rotation function from scratch by deriving a recurrence relation. It first calculates the sum of all elements and F(0) by multiplying each element by its index.

The key insight is that when rotating clockwise by one position, the last element moves to the front. This affects F(k) in a predictable way: F(k+1) = F(k) - nums[n-1-k] * n + sum. The element that was at the end (multiplied by n-1) now gets multiplied by 0, while all other elements effectively get their multipliers increased by 1.

The code iterates backward through the array (from n-1 to 1), updating the current rotation function value using the recurrence: subtract the element times n (removing its old contribution), then add the sum of all elements (accounting for all indices shifting up by 1). It tracks the maximum value seen across all rotations.

This approach computes all rotation functions in a single pass after the initial setup, avoiding the need to explicitly construct or iterate through each rotated array.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-05-01 03:47 UTC
- Runtime: 0 ms
- Memory: 99.4 MB
- Language: C++
