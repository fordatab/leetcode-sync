# Find the Closest Palindrome

**Difficulty:** Hard
**Tags:** string, math, palindrome, greedy

## Problem

Given a string representing an integer, find the nearest palindromic integer that is not equal to the input. If two palindromes are equidistant from the input, return the smaller one. The input can be up to 18 digits long, representing integers from 1 to 10^18 - 1.

## Approach

The solution generates five candidate palindromes and selects the one with minimum absolute difference from the input:

1. **Extract the first half**: Split the input at the middle (adjusting for odd/even length) and extract the prefix that will be mirrored.

2. **Generate candidates**: Create five palindromes by mirroring different versions of the first half:
   - Mirror the first half as-is
   - Mirror the first half incremented by 1
   - Mirror the first half decremented by 1
   - Edge case: 999...9 (largest palindrome with one fewer digit)
   - Edge case: 100...001 (smallest palindrome with one more digit)

3. **Mirror helper**: The `halfToPalindrome` function creates a palindrome by appending the reverse of the left portion. For odd-length palindromes, it excludes the middle digit before reversing.

4. **Select best candidate**: Iterate through all candidates, skipping the input itself, and track the one with minimum difference. In case of a tie, choose the smaller value.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2026-02-02 22:05 UTC
- Runtime: 0 ms
- Memory: 8.7 MB
- Language: C++
