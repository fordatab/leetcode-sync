# Grumpy Bookstore Owner

**Difficulty:** Medium
**Tags:** sliding-window, array, greedy

## Problem

Given arrays representing customers entering a bookstore each minute and the owner's grumpy status (binary), find the maximum satisfied customers. Normally, customers are satisfied only when the owner isn't grumpy, but the owner can use a one-time technique to stay not grumpy for a specified consecutive window of minutes. The task is to optimally place this window to maximize total satisfied customers across all n minutes (1 ≤ n ≤ 20,000).

## Approach

The solution uses a sliding window technique. First, it calculates the baseline satisfaction by summing all customers during non-grumpy minutes. Then it applies a sliding window of size `minutes` to find which consecutive window, when the owner suppresses grumpiness, would recover the most additional customers.

Initially, the window covers the first `minutes` positions, adding any customers that would have been lost to grumpiness in that range. As the window slides right, it removes customers from the left edge (if that minute was grumpy) and adds customers from the right edge (if that minute is grumpy), tracking the maximum total satisfaction achieved.

The key insight is that we want to place the grumpiness-suppression window where it recovers the most unsatisfied customers, which is found by sliding a fixed-size window across the grumpy periods and tracking the maximum gain.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2025-09-04 10:24 UTC
- Runtime: 0 ms
- Memory: 35.9 MB
- Language: C++
