# Capacity To Ship Packages Within D Days

**Difficulty:** Medium
**Tags:** binary-search, greedy, array, simulation

## Problem

<<<<<<< HEAD
Given an array of package weights and a target number of days, find the minimum ship capacity needed to transport all packages in order within the time limit. Packages must be loaded sequentially (no reordering), and each day the ship can carry packages up to its capacity limit. The capacity must be at least as large as the heaviest individual package.

## Approach

The solution uses binary search on the possible capacity values. The search range starts from the maximum package weight (minimum viable capacity) to a very large upper bound. For each candidate capacity, a helper function simulates the shipping process by greedily loading packages onto each day's voyage until the capacity would be exceeded, then starting a new day. The simulation counts how many days are needed with that capacity. If the candidate capacity allows shipping within the day limit, it's a valid answer, so the search continues in the lower half to find a smaller capacity. Otherwise, the search moves to the upper half to try larger capacities. The binary search converges on the minimum capacity that satisfies the constraint.

## Complexity

- **Time:** O(n log C)
=======
Given an array of package weights and a target number of days, find the minimum ship capacity needed to transport all packages in order within the time limit. Packages must be loaded sequentially from the array, and each day the ship can carry weight up to its capacity. The constraint is that we cannot reorder packages, and the number of days available ranges from 1 to the length of the weights array (up to 50,000 elements), with individual weights between 1 and 500.

## Approach

The solution uses binary search on the answer space to find the minimum viable ship capacity. The search range spans from the heaviest single package (since the ship must carry at least that weight) to INT_MAX. For each candidate capacity, a helper function `check` simulates the shipping process: it iterates through packages in order, accumulating weights for the current day until adding the next package would exceed capacity, then starts a new day. The simulation counts how many days are needed with the given capacity. If the required days don't exceed the limit, the capacity is feasible and we search lower; otherwise we search higher. The binary search converges on the minimum capacity that allows shipping within the day constraint.

## Complexity

- **Time:** O(n log(sum(weights)))
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
- **Space:** O(1)

## Stats

- Submitted: 2026-04-23 23:37 UTC
- Runtime: 16 ms
- Memory: 35 MB
- Language: C++
