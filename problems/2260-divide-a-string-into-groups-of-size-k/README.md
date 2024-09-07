# Divide a String Into Groups of Size k

**Difficulty:** Easy
**Tags:** string, array, simulation, math

## Problem

Given a string, partition it into groups of exactly k characters each. If the final group has fewer than k characters, pad it with a specified fill character to reach size k. Return an array containing all groups in order.

## Approach

The solution pre-allocates a result vector with the exact number of groups needed, computed as ceiling(s.size() / k) using the formula (s.size() + k - 1) / k. Each group string is initialized to length k with all characters set to the fill character. Then it iterates through the input string once, placing each character at its correct position: the group index is i/k and the position within that group is i%k. This ensures that any incomplete final group automatically retains its fill characters in the positions not overwritten by actual string characters.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-07 04:37 UTC
- Runtime: 5 ms
- Memory: 8.5 MB
- Language: C++
