# Partition Equal Subset Sum

**Difficulty:** Medium
**Tags:** dynamic-programming, hash-set, subset-sum, knapsack

## Problem

Given an array of positive integers with up to 200 elements (each between 1 and 100), determine whether it can be split into two subsets with equal sums. If the total sum is odd, no equal partition exists. Otherwise, the problem reduces to finding if any subset sums to exactly half the total.

## Approach

The solution uses dynamic programming with a set-based approach. First, it computes the total sum and immediately returns false if the sum is odd (since equal partitioning would be impossible). It then calculates the target as half the total sum.

The algorithm maintains a set `dp` of all achievable subset sums, starting with just 0. For each number in the array (processed in reverse order), it creates a new set `next` by considering two choices for each existing achievable sum: include the current number or exclude it. If adding the current number to any existing sum equals the target, it returns true immediately.

After processing each number, the `dp` set is updated to `next`, which contains all possible sums achievable using the numbers processed so far. If no subset summing to the target is found after examining all numbers, it returns false. This is essentially a 0/1 knapsack variant where we track all reachable sums rather than using a boolean DP table.

## Complexity

- **Time:** O(n * S)
- **Space:** O(S)

## Stats

- Submitted: 2024-08-24 02:12 UTC
- Runtime: 693 ms
- Memory: 261.7 MB
- Language: C++
