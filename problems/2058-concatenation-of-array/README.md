# Concatenation of Array

**Difficulty:** Easy
**Tags:** array, simulation

## Problem

Given an integer array of length n, construct a new array of length 2n by concatenating the original array with itself. The first n elements should be identical to the original array, and the second n elements should also be identical to the original array. The array length is bounded between 1 and 1000, with element values ranging from 1 to 1000.

## Approach

The solution uses a straightforward two-pass approach. First, it creates an empty output vector. Then it iterates through the input array once, appending each element to the output vector. After completing the first pass, it iterates through the input array a second time, again appending each element to the output vector. This results in the input array being duplicated in sequence, achieving the required concatenation.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-11 08:10 UTC
- Runtime: 3 ms
- Memory: 15.7 MB
- Language: C++
