# Largest Positive Integer That Exists With Its Negative

**Difficulty:** Easy
**Tags:** hash-table, array, greedy

## Problem

Given an array of non-zero integers, find the largest positive integer k where both k and -k exist in the array. The array can contain between 1 and 1000 elements, with values ranging from -1000 to 1000. Return -1 if no such pair exists.

## Approach

The solution uses a hash map to track encountered numbers while iterating through the array. For each number, it first checks if its negation already exists in the map (by looking up `-n`). If the negation is found (indicated by a non-zero count in the map), it updates the maximum result using the absolute value of the current number. After the check, it increments the count for the current number in the map. This single-pass approach efficiently identifies pairs of opposites and maintains the largest positive value among all valid pairs.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-14 03:30 UTC
- Runtime: 27 ms
- Memory: 29.1 MB
- Language: C++
