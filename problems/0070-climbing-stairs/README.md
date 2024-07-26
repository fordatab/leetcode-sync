# Climbing Stairs

**Difficulty:** Easy
**Tags:** dynamic-programming, fibonacci, array

## Problem

Given a staircase with n steps, determine the number of distinct ways to reach the top when you can climb either 1 or 2 steps at a time. The input n ranges from 1 to 45.

## Approach

The solution uses dynamic programming with a bottom-up approach. It creates a vector `c` of size `n+1` to store the number of ways to reach each step. The base cases are initialized: `c[0] = 1` (one way to stay at ground) and `c[1] = 2` (representing that there are 2 ways to reach step 2: either two 1-steps or one 2-step). The code then iterates from index 2 to `n-1`, computing each entry as the sum of the previous two entries (`c[x] = c[x-1] + c[x-2]`), following the Fibonacci recurrence pattern. Finally, it returns `c[n-1]`, which holds the answer for n steps. Note that the indexing is offset by one from the typical formulation—the value at index `i` represents the answer for `i+1` steps.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-26 08:28 UTC
- Runtime: 0 ms
- Memory: 7.6 MB
- Language: C++
