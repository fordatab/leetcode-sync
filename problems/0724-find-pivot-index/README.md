# Find Pivot Index

**Difficulty:** Easy
**Tags:** prefix-sum, array, cumulative-sum

## Problem

Given an integer array, find the leftmost index where the sum of elements to its left equals the sum of elements to its right. Elements at the array boundaries have an implicit zero sum on their outer side. If no such index exists, return -1. The array can contain up to 10,000 elements with values ranging from -1000 to 1000.

## Approach

The solution builds two auxiliary arrays: a prefix sum array (stored in-place in `nums`) and a postfix sum array (stored in `postfix`). 

First, it transforms `nums` into a prefix sum array where each position holds the cumulative sum from the start up to and including that index. Similarly, it builds `postfix` as a postfix sum array where each position holds the cumulative sum from that index to the end.

Then it iterates through each potential pivot index. For boundary cases (first and last positions), it checks if the opposite side's sum equals zero. For interior positions, it compares the prefix sum at index `x-1` (sum of all elements strictly to the left) with the postfix sum at index `x+1` (sum of all elements strictly to the right). When these sums match, that index is the pivot.

The solution handles the single-element array as a special case, immediately returning 0 since both sides are empty.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-16 09:13 UTC
- Runtime: 63 ms
- Memory: 35.2 MB
- Language: C++
