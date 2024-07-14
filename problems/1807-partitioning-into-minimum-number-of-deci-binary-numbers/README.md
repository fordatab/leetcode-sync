# Partitioning Into Minimum Number Of Deci-Binary Numbers

**Difficulty:** Medium
**Tags:** greedy, string, math

## Problem

Given a string representing a positive decimal integer, find the minimum number of deci-binary numbers (numbers with only 0s and 1s as digits) that sum to the target number. The input string can be up to 10^5 characters long and represents a valid positive integer without leading zeros.

## Approach

The solution exploits a key insight: since each deci-binary number can contribute at most 1 to any digit position, the minimum number of deci-binary numbers needed equals the maximum digit in the target number. For example, if the largest digit is 8, you need exactly 8 deci-binary numbers because that digit position requires 8 contributions of 1.

The code finds the maximum character in the input string using `max_element`, then converts it from a character to its numeric value by subtracting `'0'`. This single pass through the string determines the answer without needing to construct the actual deci-binary numbers or perform any addition.

This greedy approach works because you can always construct the required deci-binary numbers: place a 1 in each deci-binary number at positions where the target still needs contributions, and 0 elsewhere. The limiting factor is always the largest digit.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-14 06:48 UTC
- Runtime: 24 ms
- Memory: 15.1 MB
- Language: C++
