# Minimum Number of Flips to Make the Binary String Alternating

**Difficulty:** Medium
**Tags:** sliding-window, string, greedy, simulation

## Problem

Given a binary string, you can perform two operations: (1) move the first character to the end, and (2) flip any character from '0' to '1' or vice versa. The goal is to find the minimum number of flip operations needed to make the string alternating (no two adjacent characters are equal), after performing any number of move operations.

## Approach

The solution tracks counts of '0's and '1's at even and odd positions separately. It simulates all possible rotations of the string by iterating through each position as a potential starting point.

For an alternating string, there are two valid patterns: '0' at even indices (with '1' at odd) or '1' at even indices (with '0' at odd). The code computes the flip cost for each rotation by taking `min(zero_odd, zero_even) + min(one_odd, one_even)`, which represents the minimum flips needed to achieve either alternating pattern.

When simulating a rotation (moving the leftmost character to the end), the code updates the counts by: removing the character from the even position, swapping odd/even counts to reflect the index shift, then adding the moved character back at the appropriate position (odd or even depending on whether the string length is odd or even).

The algorithm tracks the minimum flip count across all possible rotations and returns it.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-03-03 04:23 UTC
- Runtime: 6 ms
- Memory: 14.3 MB
- Language: C++
