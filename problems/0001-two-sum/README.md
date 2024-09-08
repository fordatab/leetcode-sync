# Two Sum

**Difficulty:** Easy
**Tags:** hash-table, array, single-pass

## Problem

Given an array of integers and a target value, find the indices of two elements that sum to the target. The input is guaranteed to have exactly one valid pair, and the same element cannot be used twice. The array can contain between 2 and 10,000 elements, with values ranging from -10^9 to 10^9.

## Approach

This solution uses a hash table to achieve a single-pass algorithm. As it iterates through the array with `for/fold`, it maintains a hash map (`seen`) that stores each visited number as a key and its index as the value.

For each element `n` at position `idx`, the code calculates the complement `k = target - n`. It checks whether this complement already exists in the hash map. If the complement is found, it immediately returns a list containing the stored index of the complement and the current index.

If the complement isn't found, the current number and its index are added to the hash map, and iteration continues. The `#:break` clause ensures the loop terminates as soon as a valid pair is found (when `seen` becomes a list rather than a hash).

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-08 05:52 UTC
- Runtime: 182 ms
- Memory: 101.4 MB
- Language: Racket
