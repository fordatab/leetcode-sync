# Find Triangular Sum of an Array

**Difficulty:** Medium
**Tags:** array, simulation, iterative

## Problem

Given an array of single digits (0-9), repeatedly replace it with a new array where each element is the sum of two adjacent elements from the previous array, modulo 10. Continue this process until only one element remains, then return that final value. The array shrinks by one element in each iteration, forming a triangular reduction pattern.

## Approach

The solution uses an iterative simulation approach. It repeatedly constructs a new temporary vector where each position stores the sum of two consecutive elements from the current array, taking the result modulo 10. After building the complete temporary vector for one level, it replaces the original `nums` array with this new vector. This process continues in a loop until the array size reduces to 1. The loop condition checks `nums.size() != 1`, and in each iteration, it creates a vector of size `n-1` from an array of size `n`. Finally, it returns the single remaining element `nums[0]`.

## Complexity

- **Time:** O(n²)
- **Space:** O(n²)

## Stats

- Submitted: 2024-09-25 04:48 UTC
- Runtime: 317 ms
- Memory: 381.9 MB
- Language: C++
