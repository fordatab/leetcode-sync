# How Many Numbers Are Smaller Than the Current Number

**Difficulty:** Easy
**Tags:** counting-sort, array, prefix-sum, hash-table

## Problem

Given an array of integers, determine for each element how many other elements in the array are strictly smaller than it. The array contains integers between 0 and 100, with length between 2 and 500. Return the counts in an array where each position corresponds to the original array's position.

## Approach

This solution uses a counting sort approach with a frequency array. First, it creates an array `b` of size 101 to count occurrences of each value (since values range from 0 to 100). Then it converts this frequency array into a cumulative count array where `b[i]` represents the total count of all values ≤ i. Finally, for each element in the original array, it looks up `b[value - 1]` to find how many numbers are smaller than that value. The solution modifies the input array in-place to store the results, using the fact that for any value v, all numbers smaller than v are counted in positions 0 through v-1 of the cumulative array. Special handling ensures that when the value is 0, it correctly returns 0 (since there can be no smaller numbers).

## Complexity

- **Time:** O(n + k)
- **Space:** O(k)

## Stats

- Submitted: 2024-08-16 06:00 UTC
- Runtime: 13 ms
- Memory: 11.2 MB
- Language: C
