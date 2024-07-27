# House Robber II

**Difficulty:** Medium
**Tags:** dynamic-programming, array, sliding-window

## Problem

Given an array representing money in houses arranged in a circle, find the maximum amount that can be stolen without robbing two adjacent houses. The circular arrangement means the first and last houses are considered neighbors, creating an additional constraint beyond the linear version of this problem. The array can contain 1 to 100 houses, each with 0 to 1000 units of money.

## Approach

The solution breaks the circular constraint by considering two separate linear scenarios: one excluding the first house and one excluding the last house. Since we cannot rob both the first and last houses simultaneously in a circle, the optimal solution must fall into one of these cases.

The `helper` function solves the standard linear house robber problem using dynamic programming with O(1) space. It maintains two variables: `rob1` tracks the maximum money robbed up to two houses ago, and `rob2` tracks the maximum up to the previous house. For each house, it decides whether to rob the current house (adding its value to `rob1`) or skip it (keeping `rob2`).

The main function creates two subarrays—one from index 1 to end (excluding first house) and one from start to second-to-last (excluding last house)—and runs the helper on both. It then returns the maximum of three values: robbing only the first house, the result from the first subarray, or the result from the second subarray. The special case of `nums[0]` handles single-element arrays.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-27 05:10 UTC
- Runtime: 0 ms
- Memory: 9.7 MB
- Language: C++
