# Capacity To Ship Packages Within D Days

**Difficulty:** Medium
**Tags:** binary-search, greedy, array, simulation

## Problem

Given an array of package weights and a target number of days, find the minimum ship capacity needed to transport all packages in order within the time limit. Packages must be loaded sequentially (no reordering), and each day the ship can carry packages up to its capacity limit. The capacity must be at least as large as the heaviest individual package.

## Approach

The solution uses binary search on the possible capacity values. The search range starts from the maximum package weight (minimum viable capacity) to a very large upper bound. For each candidate capacity, a helper function simulates the shipping process by greedily loading packages onto each day's voyage until the capacity would be exceeded, then starting a new day. The simulation counts how many days are needed with that capacity. If the candidate capacity allows shipping within the day limit, it's a valid answer, so the search continues in the lower half to find a smaller capacity. Otherwise, the search moves to the upper half to try larger capacities. The binary search converges on the minimum capacity that satisfies the constraint.

## Complexity

- **Time:** O(n log C)
- **Space:** O(1)

## Stats

- Submitted: 2026-04-23 23:37 UTC
- Runtime: 16 ms
- Memory: 35 MB
- Language: C++
