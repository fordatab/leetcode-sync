# Maximum Running Time of N Computers

**Difficulty:** Hard
**Tags:** binary-search, greedy, math, array

## Problem

Given n computers and an array of battery capacities, determine the maximum time all n computers can run simultaneously. Batteries can be swapped between computers instantly at any time, and each computer needs exactly one battery at any moment. The goal is to find the longest duration where all computers remain powered.

## Approach

The solution uses binary search on the answer space to find the maximum runtime. The search range spans from 0 to the sum of all battery capacities.

For each candidate time `mid`, a helper function `check` verifies feasibility: if we run for `mid` minutes with `n` computers, we need a total of `mid * n` battery-minutes. The check sums up the contribution from each battery, capping each battery's contribution at `mid` (since a battery with capacity greater than `mid` can only provide `mid` minutes to our timeline). If this sum meets or exceeds the requirement, that runtime is achievable.

The binary search narrows down to the largest feasible time by moving the left boundary up when a time works, and the right boundary down when it doesn't. The key insight is that batteries can be freely swapped, so what matters is the total available energy capped by the target runtime, not which specific battery powers which computer.

## Complexity

- **Time:** O(m log S)
- **Space:** O(1)

## Stats

- Submitted: 2026-01-20 08:27 UTC
- Runtime: 22 ms
- Memory: 59.6 MB
- Language: C++
