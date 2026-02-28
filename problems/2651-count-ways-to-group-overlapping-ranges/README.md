# Count Ways to Group Overlapping Ranges

**Difficulty:** Medium
**Tags:** intervals, sorting, greedy, merge-intervals, modular-exponentiation

## Problem

Given a collection of integer ranges, partition them into two groups such that any overlapping ranges must be in the same group. Two ranges overlap if they share at least one integer. Count the number of valid ways to perform this partition, returning the result modulo 10^9 + 7. Ranges can contain up to 10^5 elements with endpoints up to 10^9.

## Approach

The solution first merges all overlapping ranges into disjoint components using an interval merging algorithm. It sorts the ranges by start position, then iterates through them, merging consecutive ranges that overlap (when a range's start is less than or equal to the current merged range's end). After merging, the number of disjoint components represents independent groups of ranges that must stay together.

Since each disjoint component can be assigned to either group 1 or group 2 independently, and there are `k` such components after merging, the total number of ways to partition is 2^k. The solution computes this using modular exponentiation with modulus 10^9 + 7.

The `modular_pow` function implements modular exponentiation through repeated multiplication, applying the modulo operation at each step to prevent overflow.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-02-28 09:31 UTC
- Runtime: 71 ms
- Memory: 93.6 MB
- Language: C++
