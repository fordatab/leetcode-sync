# Flip String to Monotone Increasing

**Difficulty:** Medium
**Tags:** dynamic-programming, greedy, string

## Problem

Given a binary string, determine the minimum number of bit flips needed to make it monotone increasing, where a monotone increasing string has all zeros (if any) appearing before all ones (if any). The string can have length up to 100,000, and each character is either '0' or '1'.

## Approach

The solution uses a single-pass greedy dynamic programming approach. It maintains two variables: `b_ct` tracks the count of '1's seen so far, and `pre` represents the minimum flips needed to make the string up to the current position monotone increasing.

For each character, if it's a '0', we have two choices: either flip this '0' to '1' (costing `pre + 1` flips), or flip all previous '1's to '0's (costing `b_ct` flips). We take the minimum of these options.

If the character is a '1', we simply increment the count of ones seen (`b_ct`), as a '1' doesn't violate the monotone property at this point and doesn't require flipping.

The final value of `pre` gives us the minimum number of flips needed for the entire string.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-04 23:05 UTC
- Runtime: 27 ms
- Memory: 12.7 MB
- Language: C++
