# Remove K Digits

**Difficulty:** Medium
**Tags:** greedy, stack, monotonic-stack, string

## Problem

Given a string representing a non-negative integer and an integer k, remove exactly k digits from the string to form the smallest possible number. The result must not have leading zeros (except when the answer is zero itself). Constraints include string length up to 10^5 and k being at most the length of the input string.

## Approach

The solution uses a greedy approach with a monotonic stack implemented as a string. It iterates through each digit of the input number and maintains an increasing sequence in the stack. Whenever a smaller digit is encountered and removals remain (k > 0), it pops larger digits from the stack's end to make room for the smaller digit, effectively minimizing the resulting number. After processing all digits, if k removals remain unused, it removes that many digits from the end of the stack. Finally, it strips leading zeros from the result by finding the first non-zero character and taking a substring from that position. If the result is empty after removing leading zeros, it returns "0".

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2025-12-02 11:53 UTC
- Runtime: 0 ms
- Memory: 11.2 MB
- Language: C++
