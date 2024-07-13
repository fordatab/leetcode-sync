# Kids With the Greatest Number of Candies

**Difficulty:** Easy
**Tags:** array, greedy, iteration

## Problem

Given an array representing the number of candies each of n kids has and an integer representing extra candies available, determine for each kid whether giving them all the extra candies would result in them having at least as many candies as the current maximum. The array has between 2 and 100 elements, with candy counts and extra candies both capped at reasonable small values (≤100 and ≤50 respectively).

## Approach

The solution first identifies the maximum number of candies currently held by any kid using `max_element`. It then iterates through each kid's candy count, checking whether adding all the extra candies to that kid's total would reach or exceed the current maximum. For each kid, it appends a boolean result to the output vector: `true` if `candies[i] + extraCandies >= maxCandies`, `false` otherwise. This straightforward single-pass approach after finding the max ensures every kid is evaluated against the same benchmark.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-13 02:44 UTC
- Runtime: 6 ms
- Memory: 11.3 MB
- Language: C++
