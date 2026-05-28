# Rotate Function

**Difficulty:** Medium
<<<<<<< HEAD
**Tags:** array, math, dynamic-programming, prefix-sum

## Problem

Given an integer array of length n, compute a rotation function F(k) for each rotation k, where F(k) equals the sum of each element multiplied by its index in the k-rotated array. The goal is to find the maximum value among all F(0) through F(n-1). The array can have up to 10^5 elements with values ranging from -100 to 100.

## Approach

The solution avoids recalculating each rotation function from scratch by deriving a recurrence relation. It first computes F(0) by multiplying each element by its original index and summing the results. It also calculates the total sum of all array elements.

The key insight is that when rotating clockwise by one position, the last element moves to the front. This changes F(k) to F(k+1) in a predictable way: each of the first n-1 elements gets its multiplier increased by 1, while the last element's multiplier drops from (n-1) to 0. This translates to: F(k+1) = F(k) + sum - n * nums[last].

The code iterates backward through the array, applying this recurrence relation to compute each subsequent rotation function value without explicitly rotating the array. It tracks the maximum value encountered across all rotations and returns it.
=======
**Tags:** math, array, prefix-sum, dynamic-programming

## Problem

Given an integer array of length n, compute a rotation function F(k) for each possible rotation k, where F(k) is the sum of each element multiplied by its index in the k-rotated array. The goal is to find the maximum value among all F(0), F(1), ..., F(n-1). The array can contain negative integers, and n can be up to 100,000.

## Approach

The solution avoids recomputing each rotation function from scratch by deriving a recurrence relation. It first calculates the sum of all elements and F(0) by multiplying each element by its index.

The key insight is that when rotating clockwise by one position, the last element moves to the front. This affects F(k) in a predictable way: F(k+1) = F(k) - nums[n-1-k] * n + sum. The element that was at the end (multiplied by n-1) now gets multiplied by 0, while all other elements effectively get their multipliers increased by 1.

The code iterates backward through the array (from n-1 to 1), updating the current rotation function value using the recurrence: subtract the element times n (removing its old contribution), then add the sum of all elements (accounting for all indices shifting up by 1). It tracks the maximum value seen across all rotations.

This approach computes all rotation functions in a single pass after the initial setup, avoiding the need to explicitly construct or iterate through each rotated array.
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-05-01 03:47 UTC
- Runtime: 0 ms
- Memory: 99.4 MB
- Language: C++
