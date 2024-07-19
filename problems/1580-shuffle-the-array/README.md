# Shuffle the Array

**Difficulty:** Easy
**Tags:** array, simulation, two-pointers

## Problem

Given an array of 2n elements structured as two halves (first n elements followed by second n elements), rearrange it by interleaving elements from each half alternately. The first element of the result comes from the first half, the second from the second half, and so on. The array length is guaranteed to be even (between 2 and 1000) and element values range from 1 to 1000.

## Approach

The solution allocates a new result vector of size 2n. It then iterates through indices 0 to n-1, and for each index x, it places the x-th element from the first half at even positions (2*x) and the x-th element from the second half at odd positions (2*x+1) in the output array. This directly constructs the interleaved pattern in a single pass without any auxiliary lookups or complex data structures.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-19 08:57 UTC
- Runtime: 4 ms
- Memory: 12.4 MB
- Language: C++
