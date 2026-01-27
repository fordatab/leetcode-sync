# Rearranging Fruits

**Difficulty:** Hard
**Tags:** hash-table, greedy, sorting, counting

## Problem

Given two baskets with n fruits each (represented by their costs), determine the minimum cost to make both baskets identical after rearrangement. You can swap fruits between baskets, where each swap costs the minimum of the two swapped fruit values. Return -1 if it's impossible to equalize the baskets. Two baskets are equal if they contain the same multiset of fruit costs.

## Approach

The solution uses a frequency-counting approach to identify which fruits need to be exchanged between baskets.

First, it counts the net difference of each fruit type between the two baskets using a hashmap (positive means basket1 has excess, negative means basket2 has excess). It also tracks the globally cheapest fruit across both baskets.

If any fruit type has an odd total count across both baskets, the baskets cannot be equalized, so it returns -1.

For fruits with imbalanced counts, it builds a list of fruits that need to be swapped out of basket1 (half of the absolute difference for each fruit type). After sorting this list, it pairs fruits optimally: the first half of the sorted list represents fruits to swap out, which implicitly pairs cheaper fruits with cheaper fruits.

For each swap operation, the cost is either the fruit's own value or twice the global minimum (using the minimum fruit as an intermediary for indirect swaps), whichever is cheaper. This optimization allows expensive fruits to be swapped more cheaply by routing through the cheapest fruit.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## Stats

- Submitted: 2026-01-27 10:01 UTC
- Runtime: 39 ms
- Memory: 90.1 MB
- Language: C++
