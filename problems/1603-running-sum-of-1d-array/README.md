# Running Sum of 1d Array

**Difficulty:** Easy
**Tags:** array, prefix-sum, in-place

## Problem

Given an integer array, compute a new array where each element at index i contains the sum of all elements from index 0 through i in the original array. The array can have up to 1000 elements with values ranging from -10^6 to 10^6.

## Approach

The solution modifies the input array in place using a single pass with an accumulator variable. It iterates through each element, adds the current running total (stored in variable `a`) to the element, then updates the accumulator to reflect the new cumulative sum. At each position, the element is replaced with the sum of all elements seen so far, eliminating the need for additional space. The modified array is then returned as the result.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-11 08:01 UTC
- Runtime: 0 ms
- Memory: 10.9 MB
- Language: C++
