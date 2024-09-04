# Replace Elements with Greatest Element on Right Side

**Difficulty:** Easy
**Tags:** array, iteration, greedy

## Problem

Given an array of integers, transform each element so it becomes the maximum value found among all elements to its right. The final element should always be replaced with -1 since there are no elements to its right. The array can contain up to 10,000 elements with values ranging from 1 to 100,000.

## Approach

The solution uses a single right-to-left traversal with a running maximum tracker. Starting from the rightmost element, it maintains a variable `m` that tracks the greatest element seen so far during the reverse iteration. For each position, the code first saves the current element, then replaces it with the current maximum `m`, and finally updates `m` to be the maximum of itself and the saved value. This ensures each element is replaced with the maximum of all elements that were originally to its right. The variable `m` is initialized to -1, which correctly handles the last element since there are no elements to its right.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-04 08:33 UTC
- Runtime: 82 ms
- Memory: 71.3 MB
- Language: C++
