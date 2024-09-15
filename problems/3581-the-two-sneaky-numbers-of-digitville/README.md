# The Two Sneaky Numbers of Digitville

**Difficulty:** Easy
**Tags:** array, hash-table, counting

## Problem

Given an array that should contain integers from 0 to n-1 exactly once, but has exactly two numbers appearing twice instead of once, identify and return those two duplicate numbers. The array length is n+2, where n ranges from 2 to 100, and the duplicates appear exactly twice each.

## Approach

The solution uses a frequency-counting approach with a fixed-size integer array as a hash map. It iterates through the input array once, incrementing the count for each number encountered in the frequency map. Whenever a count reaches 2, that number is immediately added to the result vector. Since the problem guarantees exactly two duplicates, the loop will find both duplicates during the single pass and return them in the order they complete their second occurrence.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-15 05:19 UTC
- Runtime: 10 ms
- Memory: 25.4 MB
- Language: C++
