# Divide Players Into Teams of Equal Skill

**Difficulty:** Medium
**Tags:** hash-table, greedy, array, math

## Problem

Given an even-length array of player skills, partition the players into pairs such that every pair has the same total skill. Return the sum of the products (chemistry) of each pair's skills, or -1 if no valid pairing exists. The array length is at most 100,000, and individual skill values range from 1 to 1,000.

## Approach

The solution first computes the total sum of all skills and determines the required target sum for each pair by dividing by the number of pairs (n/2). If the total is not evenly divisible, no valid pairing exists.

It then builds a frequency map of all skill values. For each unique skill value x in the map, it checks whether the complement (target - x) also exists in the map with the same frequency. If any skill value lacks a matching complement or has mismatched frequencies, the function returns -1.

For valid configurations, the chemistry is accumulated by multiplying each skill x by its complement and its frequency, summing across all unique skills. Since each pair is counted twice (once from each endpoint), the final result is halved before returning.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2026-07-17 05:51 UTC
- Runtime: 7 ms
- Memory: 57.3 MB
- Language: C++
