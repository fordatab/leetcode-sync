# Minimum Penalty for a Shop

**Difficulty:** Medium
**Tags:** array, prefix-sum, greedy

## Problem

Given a string representing customer visits to a shop (where 'Y' means customers arrived and 'N' means no customers), find the earliest hour to close the shop that minimizes the penalty. The penalty is calculated as the sum of hours when the shop is open with no customers (each 'N' before closing) plus hours when the shop is closed but customers arrive (each 'Y' after closing). The closing time can range from hour 0 to hour n (where n is the length of the string).

## Approach

The solution uses a two-pass approach with a prefix-suffix technique:

1. **First pass (backward)**: Build a `closed` array where `closed[x]` counts how many 'Y' characters (customers) appear from hour `x` onward. This represents the penalty if we close at hour `x` due to missed customers.

2. **Second pass (forward)**: Iterate through each possible closing time from 0 to n. For each position `x`, accumulate the count of 'N' characters (empty hours) seen so far in variable `j`. Add this to `closed[x]` to get the total penalty: empty hours before closing plus customer hours after closing.

3. **Find minimum**: Use `min_element` to find the position with the minimum total penalty in the `closed` array, and return its index as the earliest optimal closing time.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-10-01 22:43 UTC
- Runtime: 3372 ms
- Memory: 21.7 MB
- Language: C++
