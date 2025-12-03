# Maximum Number of Upgradable Servers

**Difficulty:** Medium
**Tags:** binary-search, greedy, array

## Problem

Given n data centers, each with a certain number of servers, you must determine the maximum servers that can be upgraded at each center independently. For each center, you have initial money and can sell servers to gain additional funds, then use your total money to upgrade remaining servers. Each center operates with its own budget—money from one cannot help another.

## Approach

The solution uses binary search on the answer for each data center independently. For a given data center, it searches for the maximum number of servers that can be upgraded by trying different values between 0 and the total server count.

The `valid` helper function checks if upgrading a specific number of servers is feasible: it calculates how many servers can be sold (total count minus servers to upgrade), computes the total available money (initial money plus revenue from selling servers), and verifies whether this covers the upgrade cost.

For each data center, binary search maintains a range [l, r] and tests the midpoint. If upgrading `mid` servers is valid, the search moves to higher values (l = mid + 1) to find a potentially larger answer; otherwise, it narrows the range downward (r = mid - 1). The maximum valid value found is returned.

All arithmetic uses 64-bit integers to prevent overflow when multiplying counts by costs or sell prices.

## Complexity

- **Time:** O(n log m)
- **Space:** O(n)

## Stats

- Submitted: 2025-12-03 23:36 UTC
- Runtime: 27 ms
- Memory: 275.4 MB
- Language: C++
