# Check if All A's Appears Before All B's

**Difficulty:** Easy
**Tags:** string, single-pass, greedy, boolean-flag

## Problem

Given a string containing only the characters 'a' and 'b', determine whether all occurrences of 'a' come before all occurrences of 'b'. The string length is between 1 and 100 characters. Return true if the string has no 'a' characters following any 'b' character, and false otherwise.

## Approach

The solution uses a single-pass linear scan with a boolean flag to track whether a 'b' has been encountered. It iterates through each character in the string, maintaining a `has_b` flag that becomes true once the first 'b' is seen. If an 'a' is encountered after the flag has been set to true, it means an 'a' appears after a 'b', violating the condition, so the function immediately returns false. If the loop completes without finding such a violation, the function returns true, indicating all 'a's (if any) appeared before all 'b's (if any).

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-04 23:07 UTC
- Runtime: 3 ms
- Memory: 7.5 MB
- Language: C++
