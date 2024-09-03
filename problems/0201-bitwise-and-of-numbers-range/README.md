# Bitwise AND of Numbers Range

**Difficulty:** Medium
**Tags:** bit-manipulation, bitwise-and, math

## Problem

Given two integers representing a range [left, right], compute the bitwise AND of all integers within that range. The range can span from 0 to 2^31 - 1, and both endpoints are included in the computation.

## Approach

The solution uses a bit manipulation trick to find the common prefix of the binary representations of `left` and `right`. It repeatedly clears the rightmost set bit of `right` using the operation `right &= right - 1` until `right` becomes less than or equal to `left`. This effectively removes all bits that differ between numbers in the range. Once the loop terminates, performing `right & left` yields the result, which represents the longest common binary prefix of all numbers in the range. The key insight is that when you AND all numbers in a range, only the bits that remain constant (the common prefix) survive; any bit position that toggles within the range will be zeroed out.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-03 06:25 UTC
- Runtime: 8 ms
- Memory: 10.3 MB
- Language: C++
