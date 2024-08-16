# How Many Numbers Are Smaller Than the Current Number

**Difficulty:** Easy
**Tags:** counting-sort, array, prefix-sum, frequency-count

## Problem

Given an array of integers, determine for each element how many other elements in the array are strictly smaller than it. The array has length 2-500 and contains values from 0-100. Return the counts in an array matching the original order.

## Approach

The solution uses a counting-sort-inspired technique that exploits the constraint that values are bounded to 0-100. First, it builds a frequency array `b` where `b[i]` counts how many times value `i` appears in the input. Then it computes a cumulative sum array `r` where `r[i]` represents the total count of values from 0 to `i` inclusive. For each original element with value `v`, the count of smaller numbers is `r[v] - b[v]` (the cumulative count up to `v` minus the frequency of `v` itself). This gives the number of elements strictly less than `v`. Finally, it maps each original element to its corresponding count using this lookup.

## Complexity

- **Time:** O(n + k)
- **Space:** O(n + k)

## Stats

- Submitted: 2024-08-16 05:42 UTC
- Runtime: 0 ms
- Memory: 12.9 MB
- Language: C++
