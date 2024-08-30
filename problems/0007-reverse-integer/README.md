# Reverse Integer

**Difficulty:** Medium
**Tags:** math, integer-manipulation, overflow-detection

## Problem

Given a signed 32-bit integer, reverse its digits and return the result. If the reversed number would overflow the 32-bit signed integer range (from -2^31 to 2^31 - 1), return 0 instead. The solution must not use 64-bit integers to detect overflow.

## Approach

The solution extracts digits one by one from the input integer using modulo and division operations, building the reversed number iteratively. Before multiplying the result by 10 and adding the next digit, it checks whether this operation would cause overflow by comparing the current result against MAX/10 and MIN/10. For boundary cases where the result equals exactly MAX/10 or MIN/10, it additionally checks if the next digit would push it over the limit by comparing against MAX%10 or MIN%10. The sign of the original number is preserved naturally because the modulo operation retains the sign of the dividend in C++. This approach detects potential overflow before it happens, allowing the function to return 0 without ever creating a value outside the 32-bit range.

## Complexity

- **Time:** O(log x)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-30 03:12 UTC
- Runtime: 3 ms
- Memory: 8.3 MB
- Language: C++
