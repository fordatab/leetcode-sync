# XOR Operation in an Array

**Difficulty:** Easy
**Tags:** bit-manipulation, math, simulation

## Problem

Given an integer n and a starting value, construct an array of n elements where each element at index i equals start + 2*i. Return the bitwise XOR of all elements in this array. The constraints allow n and start to be up to 1000, meaning the generated values can reach approximately 2000.

## Approach

The solution iterates through indices 1 to n-1, computing each array element on-the-fly using the formula `start + 2*i` and accumulating the XOR result. It initializes the result with the first element (at index 0, which equals `start`), then XORs each subsequent element into the running result. This avoids explicitly constructing the array, instead computing and XORing values in a single pass through a loop.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-19 06:00 UTC
- Runtime: 2 ms
- Memory: 7.5 MB
- Language: C++
