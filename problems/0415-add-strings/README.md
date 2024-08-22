# Add Strings

**Difficulty:** Easy
**Tags:** string, math, two-pointers, simulation

## Problem

Given two non-negative integer strings of up to 10,000 digits each, compute their sum and return it as a string. The solution cannot use built-in arbitrary-precision libraries or convert the entire strings to numeric types.

## Approach

The solution simulates elementary-school addition by processing digits from right to left. It maintains two pointers starting at the last character of each string and a carry variable initialized to zero. In each iteration, it extracts the current digits (or treats missing digits as zero when one string is shorter), adds them with the carry, appends the ones place to the result string, and updates the carry to the tens place. After processing all digits, if a carry remains, it appends '1' to the result. Finally, since digits were appended in reverse order (least significant first), the string is reversed before returning.

## Complexity

- **Time:** O(max(m, n))
- **Space:** O(max(m, n))

## Stats

- Submitted: 2024-08-22 09:25 UTC
- Runtime: 8 ms
- Memory: 10.4 MB
- Language: C++
